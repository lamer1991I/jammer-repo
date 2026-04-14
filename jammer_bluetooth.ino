/*
 * ============================================================
 *  JAMMER BLUETOOTH — Electromagnetismo B191
 *  Unidades Tecnológicas de Santander · 2026
 * ============================================================
 * AVISO: Este código es de uso EXCLUSIVAMENTE EDUCATIVO.
 * Uso en entornos controlados y bajo supervisión académica.
 * El uso no autorizado puede violar la regulación ANE Colombia.
 * ============================================================
 *
 * Hardware requerido:
 *   - ESP32 WROOM 32U (38 pines)
 *   - 2x Módulo nRF24L01 + PA/LNA
 *   - (Opcional) Pantalla OLED 0.96" I2C
 *   - 2x Condensador 100µF 50V (uno por módulo nRF24)
 *
 * Librerías necesarias:
 *   - RF24 by maniacbug  (instalar desde Library Manager)
 *   - SPI.h              (incluida en ESP32 core)
 *
 * Pinout nRF24L01 → ESP32 (módulo 1 - HSPI):
 *   VCC  → 3.3V
 *   GND  → GND
 *   CE   → GPIO 16
 *   CSN  → GPIO 15
 *   SCK  → GPIO 14
 *   MOSI → GPIO 13
 *   MISO → GPIO 12
 *
 * Pinout nRF24L01 → ESP32 (módulo 2 - VSPI):
 *   VCC  → 3.3V
 *   GND  → GND
 *   CE   → GPIO 22
 *   CSN  → GPIO 21
 *   SCK  → GPIO 18
 *   MOSI → GPIO 23
 *   MISO → GPIO 19
 * ============================================================
 * Basado en el repositorio: NRF-Blue-Nullifier
 * Adaptado para uso académico - B191 UTS 2026
 * ============================================================
 */

#include <SPI.h>
#include <RF24.h>

// ── Configuración de pines ──────────────────────────────────
// Módulo 1 (HSPI)
#define CE_1   16
#define CSN_1  15

// Módulo 2 (VSPI)
#define CE_2   22
#define CSN_2  21

// ── Objetos RF24 ────────────────────────────────────────────
RF24 radio1(CE_1, CSN_1);
RF24 radio2(CE_2, CSN_2);

// ── Canales Bluetooth (2402 MHz – 2480 MHz) ─────────────────
// Bluetooth usa salto de frecuencia (FHSS) en 79 canales de 1 MHz
// Los canales del nRF24L01 van de 0 a 125
// Los canales BT relevantes empiezan en canal 2 del nRF24
const uint8_t BT_CHANNELS[] = {
  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
  12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
  32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
  42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
  52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
  62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
  72, 73, 74, 75, 76, 77, 78, 79, 80
};
const uint8_t NUM_CANALES = sizeof(BT_CHANNELS);

uint8_t canal_actual = 0;

// ── Función: Inicializar módulo nRF24L01 ────────────────────
bool initRadio(RF24 &radio, const char* nombre) {
  if (!radio.begin()) {
    Serial.print("[ERROR] No se pudo inicializar: ");
    Serial.println(nombre);
    return false;
  }
  radio.setAutoAck(false);          // Sin ACK — modo jamming
  radio.setPALevel(RF24_PA_MAX);    // Máxima potencia de transmisión
  radio.setDataRate(RF24_2MBPS);    // 2 Mbps — mayor ancho de banda
  radio.setCRCLength(RF24_CRC_DISABLED); // Sin CRC — ruido puro
  radio.startConstCarrier(RF24_PA_MAX, BT_CHANNELS[0]); // Portadora continua
  Serial.print("[OK] Módulo iniciado: ");
  Serial.println(nombre);
  return true;
}

// ── Setup ───────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("============================================");
  Serial.println("  JAMMER BLUETOOTH — B191 UTS 2026");
  Serial.println("  Solo para uso educativo y controlado");
  Serial.println("============================================");

  // Inicializar los dos módulos nRF24
  bool ok1 = initRadio(radio1, "nRF24 #1 (HSPI)");
  bool ok2 = initRadio(radio2, "nRF24 #2 (VSPI)");

  if (!ok1 && !ok2) {
    Serial.println("[FATAL] Ningún módulo responde. Revisa conexiones.");
    while (true) { delay(1000); } // Detener ejecución
  }

  Serial.println("[INFO] Iniciando salto de canales Bluetooth...");
  Serial.print("[INFO] Canales a cubrir: ");
  Serial.println(NUM_CANALES);
}

// ── Loop principal — Salto de frecuencia ────────────────────
void loop() {
  uint8_t ch = BT_CHANNELS[canal_actual];

  // Cambiar canal en ambos módulos
  radio1.setChannel(ch);
  radio2.setChannel(ch);

  // Transmitir en el canal actual
  radio1.startConstCarrier(RF24_PA_MAX, ch);
  radio2.startConstCarrier(RF24_PA_MAX, ch);

  // Log periódico cada 10 canales
  if (canal_actual % 10 == 0) {
    Serial.print("[JAM] Canal activo: ");
    Serial.print(ch);
    Serial.print(" (");
    Serial.print(2400 + ch);
    Serial.println(" MHz)");
  }

  // Avanzar al siguiente canal (FHSS simulado)
  canal_actual = (canal_actual + 1) % NUM_CANALES;

  // Pequeña pausa entre saltos (ajustar para mayor/menor efectividad)
  delayMicroseconds(200);
}
