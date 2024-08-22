# Greet Date Service

## Descripción
Este servicio ejecuta un script que imprime un saludo junto con la fecha y hora actual cada segundo.

## Instalación
- Copiar `greet_date.sh` a `/usr/local/bin/` y asegurarse de que es ejecutable.
- Copiar `greet_date.service` a `/etc/systemd/system/`.
- Ejecutar `sudo systemctl daemon-reload` para recargar la configuración de systemd.
- Ejecutar `sudo systemctl enable greet_date.service` para habilitar el servicio al inicio.
- Ejecutar `sudo systemctl start greet_date.service` para iniciar el servicio.

## Chequear los logs
Para ver los logs del servicio, utilizar:
