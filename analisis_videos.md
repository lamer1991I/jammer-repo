# 🎬 Análisis de Videos de Referencia
## Jammer Bluetooth — B191 UTS 2026

---

## Video 1 — "Cansado del Bluetooth del vecino"
**Tipo:** Tutorial completo con cableado y código  
**Lo más útil para el proyecto:**
- Usa exactamente el mismo hardware: **ESP32 WROOM 38 pines + nRF24L01**
- Código basado en repositorio **NRF Blue Nullifier** (GitHub, librería RF24 by maniacbug)
- Pinout detallado: GPIO 22→CE, 21→CSN, 18→SCK, 23→MOSI, 19→MISO (VSPI)
- Explica cómo configurar Arduino IDE con la URL de Expressif para ESP32
- Demuestra funcionamiento real interrumpiendo un parlante Bluetooth a ~5 m
- **Costo estimado:** ~20.000–30.000 COP (sin herramientas)

**Observación técnica:** El código usa `startConstCarrier()` + loop de salto de canales 0–79. Coincide exactamente con el mecanismo FHSS que describe la literatura (Rappaport, 2010).

---

## Video 2 — "Construye tu propio Jammer — Paso a paso (PCB)"
**Tipo:** Tutorial avanzado con placa PCB soldada  
**Lo más útil para el proyecto:**
- Introduce los **condensadores electrolíticos 100µF 50V** soldados directamente al VCC/GND de cada nRF24 → esto estabiliza el voltaje y aumenta el alcance (confirma lo que mencionó el compañero en el grupo)
- Uso de **2 módulos nRF24L01** en paralelo (HSPI y VSPI) → duplica la cobertura espectral
- Firmware precompilado (.bin) cargable desde web con Chrome → más fácil que Arduino IDE
- Pantalla OLED para navegar modos: Bluetooth, BLE, WiFi, Control Remoto
- Carcasa en metacrilato: protege los componentes "delicados" que mencionamos en los resultados
- **Dimensiones PCB sugeridas:** 7 cm × 5.5 cm

**Observación técnica:** Con 2 módulos transmitiendo simultáneamente en bandas HSPI y VSPI se logra mayor tasa de salto de canales, reduciendo la probabilidad de que Bluetooth encuentre un canal libre. Esto es equivalente a aumentar la relación J/S (Jamming-to-Signal).

---

## Video 3 — "Así es como funciona un Jammer Bluetooth"
**Tipo:** Demostración rápida de funcionamiento  
**Lo más útil para el proyecto:**
- Validación experimental simple y directa: conecta el jammer → señal BT cae → desconecta → señal regresa
- Confirma que el efecto es instantáneo al conectar alimentación
- El paso a seguir mencionado en el video (hacer PCB) es exactamente lo que hacemos en el Video 2
- Útil como evidencia de que **el prototipo básico funciona antes de optimizar**

---

## Video 4 — "nRFBox — Tutorial completo"
**Tipo:** Firmware avanzado multifunción  
**Lo más útil para el proyecto:**
- Muestra el dispositivo más completo: **3 módulos nRF24L01**
- Funciones del menú NRFBox:
  - **Scanner:** barrido continuo de 2.4 GHz, identifica canales activos
  - **Analyzer:** analiza señales detectadas (útil para medir RSSI)
  - **Jammer:** inhibe WiFi canal por canal (1, 2, 3, 4...)
  - **Protocill:** inhibe WiFi, cámaras, Bluetooth, Zigbee, NRF24
  - **Bluetooth Jammer:** inhibe BT y BLE con 2 o 3 radios activas
  - **BT Scan / WiFi Scan:** lista dispositivos con MAC y canal
- Demuestra inhibición de cámara IP en tiempo real
- **Explota vulnerabilidad iOS 17** mediante spam BT (solo educativo)

**Observación técnica:** El NRFBox representa la evolución natural de nuestro prototipo. Con 3 módulos la relación J/S sube ~4.7 dB respecto a 2 módulos. Para el artículo, podemos citar esto como "trabajo futuro" o mejora del dispositivo.

---

## Tabla Comparativa de los 4 Dispositivos

| Característica | Video 1 | Video 2 | Video 3 | Video 4 (NRFBox) |
|---|---|---|---|---|
| Módulos nRF24 | 1 | 2 | 1 | 3 |
| Pantalla OLED | No | Sí (opcional) | No | Sí |
| Condensadores | No | Sí (100µF) | No | Sí |
| Batería integrada | Opcional | Sí (TP4056) | No | Sí |
| Firmware | Arduino IDE | Precompilado .bin | N/A | Precompilado .bin |
| Alcance aprox. | ~5 m | ~10 m | ~3 m | ~10–15 m |
| Complejidad | Baja | Media | Muy baja | Alta |
| Costo aprox. | $30K COP | $130K COP | $30K COP | $180K COP |

---

## Recomendación para el Proyecto B191

**Implementar el diseño del Video 2** con las siguientes modificaciones:
1. Usar el firmware del NRFBox (Video 4) que tiene más funciones para demostrar en el artículo
2. Agregar los condensadores 100µF tal como sugirió el compañero con los componentes
3. Conectar pantalla OLED para mostrar el RSSI en tiempo real (valida Friis experimentalmente)

---

*Análisis elaborado para B191 · UTS Bucaramanga · Abril 2026*
