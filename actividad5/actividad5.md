# Conceptos de Sistemas Operativos

## Tipos de Kernel y sus Diferencias

Los kernels se pueden clasificar en varios tipos según su diseño y funcionalidad:

### Monolítico
- **Descripción**: En un kernel monolítico, todos los servicios del sistema operativo funcionan en espacio de kernel y en un único espacio de memoria.
- **Ventajas**: Alta eficiencia y acceso directo al hardware.
- **Desventajas**: Menor seguridad y estabilidad, ya que un fallo puede afectar a todo el sistema.

### Microkernel
- **Descripción**: Los microkernels ejecutan la mayoría de los servicios del sistema operativo, como la comunicación entre procesos y la gestión de drivers, en espacio de usuario.
- **Ventajas**: Mayor seguridad y estabilidad.
- **Desventajas**: Menor eficiencia debido a la comunicación frecuente entre el espacio de usuario y el kernel.

### Híbrido
- **Descripción**: Combina elementos de microkernels y kernels monolíticos.
- **Ventajas**: Balance entre eficiencia y modularidad.
- **Desventajas**: Puede ser complejo de diseñar y mantener.

## User vs Kernel Mode

- **User Mode**: Modo en el que se ejecutan las aplicaciones del usuario, con accesos restringidos al hardware y a los recursos del sistema.
- **Kernel Mode**: Modo en el que el kernel del sistema operativo ejecuta y tiene acceso completo al hardware y a todos los recursos.

## Interruptions vs Traps

- **Interruptions**: Señales generadas externamente (por el hardware) que causan que el procesador interrumpa el proceso actual.
- **Traps**: Interrupciones generadas internamente, como excepciones o errores de software, que requieren la atención del sistema operativo.

