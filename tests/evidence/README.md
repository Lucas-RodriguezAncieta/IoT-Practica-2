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

## 3. Criterios de evaluación

Para considerar satisfactorio el funcionamiento del sistema se establecieron los siguientes parámetros:

- Estabilidad mínima: 600 segundos sin reinicios ni bloqueos.
- Exactitud de medición: error absoluto máximo de 3 cm.
- Tiempo de respuesta extremo a extremo: máximo 1000 ms.
- Frecuencia objetivo de muestreo: 5 lecturas por segundo.
- Clasificación correcta de los estados DANGER, WARNING, SAFE e INVALID.
- Comunicación mediante sockets TCP sobre WiFi IEEE 802.11.

## 4. Registro de las pruebas

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

## 5. Trazabilidad y conservación

Las pruebas deben conservar sus registros originales, incluyendo logs, archivos CSV, fotografías y vídeos.

Los resultados documentados deben corresponder a los datos obtenidos en la ejecución. Las incidencias y desviaciones deben mantenerse registradas, sin alterar o sustituir los archivos originales.

La documentación permite relacionar los requerimientos del proyecto con sus respectivos procedimientos de verificación y resultados.
