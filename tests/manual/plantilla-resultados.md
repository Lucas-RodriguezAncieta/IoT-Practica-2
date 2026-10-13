# Ficha de ejecución de prueba

**Caso/ID:** M-01 — Integración y comunicación TCP/IP entre sensor, servidor y actuador.

**Fecha y hora (UTC-4):** 11/10/2026 — Hora: 15:00.

**Responsable:** Equipo de desarrollo — Práctica 2.

**Versiones de firmware y servidor:**
- ESP32 sensor: firmware desarrollado en C++ mediante PlatformIO.
- ESP32 actuador: firmware desarrollado en C++ mediante PlatformIO.
- Servidor TCP: implementación en Python, puerto 5000.
- Versiones exactas: registrar los identificadores de commit de GitHub utilizados durante la prueba.

**Red/condiciones ambientales:**
- Red WiFi local IEEE 802.11.
- Ambos ESP32 y el servidor conectados a la misma red.
- Dirección IPv4 local del servidor configurada en ambos clientes.
- Sensor HC-SR04 orientado hacia un objeto con superficie estable.

**Materiales usados:**
- 2 placas ESP32.
- 1 sensor ultrasónico HC-SR04.
- 3 LEDs (rojo, amarillo y verde).
- Resistencias de 220 Ω para los LEDs.
- Resistencias de 1 kΩ y 2 kΩ para el divisor de tensión del sensor.
- Computadora con Python y servidor TCP.
- Protoboard, cables de conexión y alimentación.
- Cinta métrica para verificar distancias.

**Preparación completada:**

Preparación requerida antes de la ejecución:

1. Comprobar el montaje eléctrico del sensor y los actuadores.
2. Configurar las credenciales WiFi y la dirección IP del servidor.
3. Compilar y cargar los firmwares en ambas placas ESP32.
4. Iniciar el servidor TCP en Python.
5. Verificar que ambos clientes puedan establecer comunicación con el servidor.

**Pasos ejecutados:**

Secuencia de prueba definida:

1. Iniciar el servidor TCP en el puerto 5000.
2. Conectar el ESP32 sensor mediante `REGISTER SENSOR`.
3. Conectar el ESP32 actuador mediante `REGISTER ACTUATOR`.
4. Colocar un objeto a 10 cm del sensor y comprobar que se transmita la medición y se active el estado DANGER.
5. Colocar el objeto a 35 cm y comprobar el estado WARNING.
6. Colocar el objeto a 75 cm y comprobar el estado SAFE.
7. Retirar el objeto fuera del intervalo de medición y comprobar el estado INVALID.
8. Verificar los mensajes `SET` enviados por el servidor y las respuestas `ACK` del actuador.
9. Interrumpir temporalmente la comunicación del sensor para comprobar el comportamiento de seguridad.
10. Restablecer la conexión y verificar el proceso de registro y recuperación.

**Resultado observado:**

La prueba tiene definidos cuatro comportamientos esperados:

| Distancia de referencia | Estado esperado | Comportamiento esperado |
|---|---|---|
| 10 cm | DANGER | LED rojo parpadea cada 150 ms en fases de encendido y apagado |
| 35 cm | WARNING | LED amarillo parpadea cada 500 ms en fases de encendido y apagado |
| 75 cm | SAFE | LED verde permanece encendido |
| Lectura inválida | INVALID | Todos los LEDs permanecen apagados |

La implementación y las compilaciones de los firmwares están documentadas. No se han proporcionado todavía registros físicos de esta ejecución concreta que permitan confirmar los comportamientos observados.

**PASS / FAIL / NO EJECUTADO:** NO EJECUTADO (sin evidencia de ejecución aportada para este caso).

**Enlaces a logs, CSV, fotos y vídeo originales:**

- Logs del servidor: pendiente de adjuntar.
- Registro de mediciones del sensor: pendiente de adjuntar.
- Registro del actuador: pendiente de adjuntar.
- Fotografías del montaje: pendiente de adjuntar.
- Vídeo de funcionamiento: pendiente de adjuntar.

Carpeta prevista: `tests/evidence/`

**Incidentes o desviaciones:**

No es posible determinar incidencias de esta ejecución hasta revisar los registros originales. Durante la prueba deben documentarse las desconexiones, lecturas fuera de rango, errores de comunicación o diferencias respecto a los comportamientos esperados.

**Observación:** No eliminar ninguna desviación ni sustituir los archivos originales de evidencia por este resumen.
