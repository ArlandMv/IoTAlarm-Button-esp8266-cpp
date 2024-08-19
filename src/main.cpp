#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiClient wifiClient;

// Set LED_BUILTIN if it is not defined by Arduino framework
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif
int ledState = HIGH;

const char *SSID = "ingenieria";
const char *PASSWORD = "iping2024";
const char *serverURL = "http://192.168.43.227/trigger";

// Button and debouncing variables
const int buttonPin = 4;   // GPIO 4 (D2)
int lastButtonState = LOW; // Previous state of the button
static unsigned long lastPressTime = 0;
const unsigned long debounceDelay = 50; // Debounce time in milliseconds

// DECLARATIONS
void connectToWiFi();
void sendMessageToESP8266B();

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(LED_BUILTIN, LOW); // turn ON
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH); // turn OFF

  connectToWiFi();
}

void loop()
{
  unsigned long currentTime = millis();
  if (digitalRead(buttonPin) == HIGH && (currentTime - lastPressTime > debounceDelay))
  {
    digitalWrite(LED_BUILTIN, LOW);
    sendMessageToESP8266B();
    digitalWrite(LED_BUILTIN, HIGH);
    lastPressTime = currentTime;
  }
}

void sendMessageToESP8266B()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    String macAddress = WiFi.macAddress();
    String url = serverURL + String("?mac=") + macAddress;
    // Change serverURL to "http://[IP_ESP32]/trigger"
    http.begin(wifiClient, url);
    int httpResponseCode = http.GET();

    if (httpResponseCode == 200)
    {
      Serial.println("Message sent to ESP32");
    }
    else
    {
      Serial.print("Error sending message. HTTP response code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else
  {
    Serial.println("Wi-Fi not connected");
  }
}

void connectToWiFi()
{
  Serial.println("Connecting to WiFi...");
  WiFi.begin(SSID, PASSWORD);

  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED && timeout < 20)
  {
    delay(500);
    Serial.print(".");
    timeout++;
  }

  if (WiFi.status() == WL_CONNECTED)
  { //\n
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println(" IP address: ");
    Serial.println(WiFi.macAddress());
  }
  else
  {
    Serial.println("\nFailed to connect to WiFi. Restarting...");
    ESP.restart();
  }
}