# 📡 Jammer Bluetooth — Electromagnetismo E111
### Unidades Tecnológicas de Santander · 2026

> **⚠️ AVISO LEGAL:** Este proyecto es **exclusivamente educativo**, desarrollado en entornos controlados bajo supervisión académica. El uso de inhibidores de señal sin autorización está regulado por la **ANE (Agencia Nacional del Espectro - Colombia)**. Los autores no se responsabilizan por el mal uso de esta información.

---

## 👥 Integrantes
Estudiantes del grupo **E111** — UNIDADES TECNOLOGICAS DE SANTANDER   UTS

---

## 🎯 Objetivo del Proyecto
Diseñar e implementar una plataforma basada en **ESP32** y módulos **nRF24L01** para caracterizar fenómenos electromagnéticos en la banda de **2.4 GHz**, con fines educativos y de auditoría wireless.

---

## ⚙️ Componentes del Hardware

| Componente | Cantidad | Función | Estado |
|---|---|---|---|
| ESP32 WROOM 32U (38 pines) | 1 | Núcleo de procesamiento | ✅ Disponible |
| Módulo nRF24L01 + PA/LNA (con antena) | 2 | Transceptor RF 2.4 GHz | ✅ Disponible |
| Condensadores electrolíticos 100µF 50V | 2 | Estabilización de señal | ⏳ Por conseguir |
| Pantalla OLED 0.96" I2C | 1 | Visualización RSSI (opcional) | ⏳ Por conseguir |
| Batería LiPo 3.7V 1500mAh | 1 | Alimentación portátil | ✅ Disponible |
| Módulo cargador TP4056 | 1 | Gestión de batería | ✅ Disponible |
| Protoboard / PCB | 1 | Montaje del circuito | ⏳ Por conseguir |
| Cables Dupont M-H | varios | Conexiones | ⏳ Por conseguir |
| Mini interruptor 2 posiciones | 1 | Encendido/apagado | ⏳ Por conseguir |

**Costo estimado total:** $130.000 – $200.000 COP

---

## 🔌 Diagrama de Conexiones (Pinout)

### nRF24L01 → ESP32

| Pin nRF24L01 | GPIO ESP32 | Descripción |
|---|---|---|
| VCC | 3.3V | Alimentación |
| GND | GND | Tierra |
| CE | GPIO 16 | Chip Enable |
| CSN | GPIO 15 | Chip Select Not |
| SCK | GPIO 14 | Clock SPI |
| MOSI | GPIO 13 | Master Out Slave In |
| MISO | GPIO 12 | Master In Slave Out |

> Para el **segundo módulo nRF24L01** (VSPI), usar: CE→22, CSN→21, SCK→18, MOSI→23, MISO→19

### Pantalla OLED (opcional)
| Pin OLED | GPIO ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCL | GPIO 5 |
| SDA | GPIO 4 |

---

## 💾 Firmware

Ver carpeta [`/codigo`](./codigo/) para el sketch de Arduino IDE.

### Dependencias (librerías Arduino IDE)
- `RF24` by maniacbug/nRF24L01
- `SPI.h` (incluida en ESP32 core)
- `Wire.h` (para pantalla OLED)
- `Adafruit_SSD1306` (si se usa pantalla)

### Cómo flashear
1. Instalar [Arduino IDE](https://www.arduino.cc/en/software)
2. Agregar soporte ESP32: `File → Preferences → URLs adicionales` → pegar:  
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Instalar librería RF24 desde `Sketch → Include Library → Manage Libraries`
4. Seleccionar board: `ESP32 WROOM-DA Module` o `ESP32 Dev Module`
5. Seleccionar el puerto COM correcto
6. Subir el sketch desde `/codigo/jammer_bluetooth.ino`

---

## 📊 Resultados Obtenidos

| Distancia (m) | P_teórica (dBm) | P_medida (dBm) | % Error |
|---|---|---|---|
| 2 | -42 | -43 | 2% |
| 5 | -50 | -51 | 2% |
| 8 | -54 | -55 | 2% |
| 10 | -56 | -58 | 3% |

**Precisión de detección:** 89%  
**Ecuación validada:** Friis — `Pr = Pt · Gt · Gr · (λ/4πd)²`  
**λ a 2.4 GHz:** ≈ 0.125 m

---

## 📁 Estructura del Repositorio

```
jammer-bluetooth-E111/
├── README.md               ← Este archivo
├── codigo/
│   ├── jammer_bluetooth.ino    ← Sketch principal
│   └── README_codigo.md        ← Explicación del código
├── docs/
│   ├── articulo_final.docx     ← Artículo académico
│   └── pinout_conexiones.png   ← Diagrama de conexiones
├── referencias/
│   └── referencias_bibliograficas.md
└── avances/
    ├── Avance_No1_Resumen_Introduccion.docx
    └── Avance_No2_... (próximamente)
```

---

## 📚 Referencias
Ver [`/referencias/referencias_bibliograficas.md`](./referencias/referencias_bibliograficas.md)

---

## 📅 Cronograma de Entregas

| Semana | Entrega | Fecha límite |
|---|---|---|
| 1 | Avance No.1 — Resumen e Introducción | Sábado 19/04/2026 |
| 2 | Avance No.2 — Marco Teórico y Resultados | Sábado 26/04/2026 |
| Final | Dispositivo terminado + Póster + Artículo | Por definir |

---

*Electromagnetismo E111 · UTS Bucaramanga · 2026*

