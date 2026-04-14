# 📚 Referencias Bibliográficas

## Artículos y Libros

1. **Balanis, C. A. (2016).** *Antenna Theory: Analysis and Design* (4th ed.). Wiley.
   - Fundamento teórico para radiación de dipolos y patrones de antena.

2. **Goldsmith, A. (2005).** *Wireless Communications*. Cambridge University Press.
   - Desvanecimiento por multitrayectoria y modelos de propagación.

3. **Rappaport, T. S. (2010).** *Wireless Communications: Principles and Practice* (2nd ed.). Prentice Hall.
   - Modelo de Log-Distancia y distribución de Rayleigh. Estándar en propagación RF.

4. **Haykin, S. (2001).** *Communication Systems* (4th ed.). Wiley.
   - Teoría de detección de señales y análisis de ruido.

5. **Proakis, J. G., & Salehi, M. (2008).** *Digital Communications* (5th ed.). McGraw-Hill.
   - Fundamentos de detección de señales digitales.

6. **González, M. (2020).** Caracterización de módulos nRF24L01 en entornos congestionados. *Revista Colombiana de Tecnología, 12*(2), 45–58.

---

## Estándares IEEE

7. **IEEE Standard 802.11-2020.** Wireless LAN Medium Access Control (MAC) and Physical Layer (PHY) Specifications. IEEE.
   - Coexistencia Bluetooth y Wi-Fi en banda ISM 2.4 GHz.

8. **IEEE Standard 802.15.1-2005.** Bluetooth Wireless Personal Area Networks. IEEE.
   - Especificación del protocolo FHSS de Bluetooth (79 canales, 1600 saltos/s).

---

## Recursos Normativos

9. **Agencia Nacional del Espectro — ANE Colombia. (2023).** Regulación sobre uso de inhibidores de señal y dispositivos de interferencia.
   - URL: https://www.ane.gov.co
   - *Relevante: el uso de jammers sin autorización es ilegal en Colombia.*

---

## Repositorios y Recursos Técnicos

10. **NRF-Blue-Nullifier** — Repositorio GitHub con firmware para ESP32 + nRF24L01.
    - Librería: RF24 by maniacbug/nRF24L01

11. **nRFBox / Blue Jammer Flasher** — Firmware precompilado (.bin) para ESP32.
    - Funciones: Scanner 2.4 GHz, Bluetooth Jammer, WiFi Jammer, Bluetooth Scan, WiFi Scan.
    - Herramienta de flasheo web compatible con Chrome.

12. **Espressif Systems. (2023).** *ESP32 Technical Reference Manual*.
    - URL: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/

---

## Videos de Referencia Analizados

13. Tutorial: "Cansado del Bluetooth del vecino — Haz un Bluetooth Jammer" (YouTube, español).
    - Componentes: ESP32 38 pines + nRF24L01. Código basado en repositorio NRF Blue Nullifier. Arduino IDE. Librería RF24.

14. Tutorial: "Construye tu propio Jammer Bluetooth fácil y rápido — Paso a paso" (YouTube, español).
    - Construcción con PCB soldada. 2x nRF24L01 + condensadores 100µF. Firmware precompilado. Pantalla OLED opcional.

15. Tutorial: "Así es como funciona un Jammer Bluetooth" (YouTube, español).
    - Demostración de funcionamiento con parlante Bluetooth. Validación experimental.

16. Tutorial: "Construye tu propio Jammer Bluetooth y de redes 2.4 GHz — nRFBox" (YouTube, español).
    - NRFBox: dispositivo multifunción. 3x nRF24L01. Funciones: Scanner, Jammer, Protocill, BT Spoof, WiFi Scan.

---

*Última actualización: Abril 2026 — B191 UTS Electromagnetismo*
