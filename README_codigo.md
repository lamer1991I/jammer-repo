# 💾 Explicación del Código — jammer_bluetooth.ino

## ¿Qué hace este código?

El sketch funciona haciendo que los módulos **nRF24L01** salten continuamente entre los **79 canales** que usa Bluetooth en la banda de 2.4 GHz, transmitiendo una **portadora continua** en cada uno. Esto satura el espectro e impide que los dispositivos cercanos puedan comunicarse.

---

## Estructura del código

### 1. Librerías
```cpp
#include <SPI.h>    // Protocolo de comunicación con los nRF24
#include <RF24.h>   // Librería para controlar el nRF24L01
```

### 2. Configuración de los módulos
Cada módulo se configura con:
- **`setAutoAck(false)`** — desactiva los acuses de recibo (no necesitamos respuesta)
- **`setPALevel(RF24_PA_MAX)`** — máxima potencia de transmisión
- **`setDataRate(RF24_2MBPS)`** — mayor ancho de banda = más cobertura espectral
- **`setCRCLength(RF24_CRC_DISABLED)`** — sin corrección de errores, genera ruido puro
- **`startConstCarrier()`** — transmite una onda portadora continua

### 3. Canal hopping (salto de frecuencia)
Bluetooth usa **FHSS** (Frequency Hopping Spread Spectrum): salta 1600 veces por segundo entre 79 canales. Nuestro jammer hace lo mismo pero al revés: salta por todos los canales para que no haya ninguno libre.

```cpp
canal_actual = (canal_actual + 1) % NUM_CANALES;
```

---

## Relación con la Ecuación de Friis

La potencia transmitida por el nRF24 a máximo PA level es aproximadamente **+20 dBm**. Usando Friis podemos estimar la potencia que llega a un dispositivo objetivo:

```
Pr(dBm) = Pt(dBm) + Gt(dBi) + Gr(dBi) + 20·log10(λ / 4πd)
```

Para d = 5 m, f = 2.4 GHz (λ = 0.125 m), Gt = Gr = 2 dBi:
```
Pr ≈ 20 + 2 + 2 + 20·log10(0.125 / 62.8) ≈ 20 + 4 - 54 ≈ -30 dBm
```

Como el ruido de fondo típico en 2.4 GHz es -90 dBm, el jammer domina por **60 dB** → señal Bluetooth completamente soterrada.

---

## Cómo instalar y subir el código

1. Abrir **Arduino IDE**
2. `File → Open` → seleccionar `jammer_bluetooth.ino`
3. Instalar librería **RF24**: `Sketch → Include Library → Manage Libraries → buscar "RF24" by maniacbug`
4. Seleccionar board: `Tools → Board → ESP32 Dev Module` (o WROOM-DA Module)
5. Seleccionar puerto: `Tools → Port → COM_X` (el que aparezca al conectar el ESP32)
6. Hacer clic en **Upload** (flecha →)
7. Abrir `Tools → Serial Monitor` a **115200 baud** para ver los logs

---

## Posibles errores y soluciones

| Error | Causa | Solución |
|---|---|---|
| `No se pudo inicializar nRF24` | Conexión suelta o pines incorrectos | Revisar el pinout, verificar soldaduras |
| El COM no aparece | Drivers no instalados | Instalar driver CP2102 o CH340 para ESP32 |
| Error de compilación RF24 | Librería no instalada | Instalar RF24 desde Library Manager |
| No interfiere bien | Antena corta o sin condensadores | Agregar condensadores 100µF al VCC de cada nRF24 |

---

*B191 UTS · Electromagnetismo · 2026*

