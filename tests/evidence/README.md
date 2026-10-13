# Evidencias de pruebas y validaciones — Práctica 2

## 1. Descripción general

Esta carpeta contiene la documentación y los registros de las pruebas correspondientes al sistema distribuido de objetos inteligentes con comunicación TCP/IP.

El sistema está compuesto por un ESP32 con sensor ultrasónico HC-SR04, un servidor TCP desarrollado en Python y un ESP32 actuador encargado de controlar tres LEDs.

Las pruebas permiten evaluar la adquisición de distancias, el procesamiento de información, el funcionamiento de los actuadores y el cumplimiento de los requerimientos funcionales y no funcionales establecidos.

## 2. Organización de evidencias

| Carpeta | Descripción | Requerimientos relacionados |
|---|---|---|
| accuracy | Evaluación de exactitud de las mediciones del sensor ultrasónico | RNF2 |
| actuator | Validación del funcionamiento de los LEDs y los comandos recibidos | RF3 |
| latency | Evaluación del tiempo de respuesta entre sensor, servidor y actuador | RNF3 |
| sampling | Verificación de la frecuencia de muestreo del sensor | RNF4 |
| sensor | Validación de lecturas y transmisión de datos del ESP32 sensor | RF1, RF4 |
| stability | Verificación de estabilidad durante funcionamiento continuo | RNF1 |
| tcp | Pruebas de comunicación cliente-servidor y protocolo de aplicación | RF2, RF4, RF6, RF7 |

## 3. Registros CSV de pruebas físicas

Los CSV siguientes contienen registros de resultados obtenidos durante las pruebas físicas del proyecto, según confirmación del equipo. Se conservaron nombres y filas de datos; sus encabezados se normalizaron a nombres técnicos. Cada archivo se relaciona con el requisito y caso de prueba indicados; los resultados, estados y valores que contiene deben interpretarse únicamente en el alcance documentado por sus propias columnas. Esta carpeta no afirma la existencia de fotografías, vídeos, logs u otras evidencias que no estén incluidos.

| Archivo | Ubicación | Caso o requisito relacionado |
|---|---|---|
| `RF1_medicion_distancia.csv` | `sensor/` | RF1; M-02 y M-03 |
| `RF2_clasificacion_servidor.csv` | `tcp/` | RF2; M-02 |
| `RF3_actuador_estados.csv` | `actuator/` | RF3; M-04 |
| `RF4_comunicacion_tcp.csv` | `tcp/` | RF4; M-01 |
| `RF5_operacion_continua.csv` | `stability/` | RF5; M-04, M-05 y M-07 |
| `RF6_autoridad_clasificacion.csv` | `tcp/` | RF6; M-01 y M-02 |
| `RF7_mensajes_malformados.csv` | `tcp/` | RF7; M-11 |
| `RNF1_estabilidad_10min.csv` | `stability/` | RNF1; M-07 |
| `RNF2_exactitud.csv` | `accuracy/` | RNF2; M-03 |
| `RNF3_latencia_extremo_a_extremo.csv` | `latency/` | RNF3; M-08 |
| `RNF4_frecuencia_muestreo.csv` | `sampling/` | RNF4; M-06 |

## 4. Criterios de evaluación

Para considerar satisfactorio el funcionamiento del sistema se establecieron los siguientes parámetros:

- Estabilidad mínima: 600 segundos sin reinicios ni bloqueos.
- Exactitud de medición: error absoluto máximo de 3 cm.
- Tiempo de respuesta extremo a extremo: máximo 1000 ms.
- Frecuencia objetivo de muestreo: 5 lecturas por segundo.
- Clasificación correcta de los estados DANGER, WARNING, SAFE e INVALID.
- Comunicación mediante sockets TCP sobre WiFi IEEE 802.11.

## 5. Registro de las pruebas

Cada ejecución se documenta indicando:

- Identificador y nombre de la prueba.
- Fecha y hora de ejecución (UTC-4).
- Responsable.
- Versiones de firmware y servidor.
- Configuración de red y materiales utilizados.
- Procedimiento ejecutado.
- Resultados obtenidos.
- Estado PASS, FAIL o NO EJECUTADO.
- Evidencias originales.
- Incidentes y desviaciones.

## 6. Trazabilidad y conservación

Las pruebas deben conservar sus registros originales, incluyendo logs, archivos CSV, fotografías y vídeos.

Los resultados documentados deben corresponder a los datos obtenidos en la ejecución. Las incidencias y desviaciones deben mantenerse registradas, sin alterar o sustituir los archivos originales.

La documentación permite relacionar los requerimientos del proyecto con sus respectivos procedimientos de verificación y resultados.
