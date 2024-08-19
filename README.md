# 🔴IoT Botón Alarma ESP8266

## 📄 Descripción
Este proyecto implementa una solución de botón IoT utilizando un ESP8266. Cuando se presiona el botón, el dispositivo envía una señal a un servidor, incluyendo su dirección MAC para identificación.

## 🌟Características
- Conexión WiFi automática
- Detección de pulsación de botón con debounce por software
- Envío de señal HTTP GET con la dirección MAC como parámetro
- Indicador LED para retroalimentación visual

## ⚠️Advertencia de Seguridad
Este código es un ejemplo funcional con fines educativos y de demostración. Sin embargo, presenta algunas vulnerabilidades de seguridad:

1. Usa HTTP en lugar de HTTPS, lo que hace que la comunicación no esté encriptada.
2. La dirección MAC se envía como un parámetro de URL, lo que la hace visible en los logs del servidor.
3. No implementa autenticación entre el dispositivo y el servidor.

## 🚀 Uso
1. Configura las credenciales WiFi y la URL del servidor en las constantes al inicio del código.
2. Carga el código en tu ESP8266.
3. Conecta un botón al pin GPIO 4 (D2) y GND.
4. El LED incorporado parpadeará para indicar el estado de la conexión y las pulsaciones del botón.

## 📈Limitaciones y Mejoras Potenciales
- Implementar HTTPS para una comunicación segura.
- Usar un método más seguro para enviar la dirección MAC (por ejemplo, en el cuerpo de una solicitud POST).
- Agregar autenticación entre el dispositivo y el servidor.
- Implementar manejo de errores más robusto y reintentos de conexión.
- Optimizar el consumo de energía para aplicaciones con batería.

## 📜Licencia

Este proyecto está licenciado bajo la Licencia MIT - consulta el archivo [LICENSE](LICENSE) para más detalles.

## 📞Contacto
Este proyecto es una demostración básica. Para una solución más segura, robusta y optimizada para su caso de uso específico, no dude en contactarme:

Para mas información o ayuda, favor comunicarse por [LinkedIn](https://www.linkedin.com/in/arland-michelena/).

To get more info or help, fell free to contact me over [LinkedIn](https://www.linkedin.com/in/arland-michelena/).