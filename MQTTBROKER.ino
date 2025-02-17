//MQTT BROKER


#include <ESP8266WiFi.h>
#include "uMQTTBroker.h"

uMQTTBroker myBroker;
WiFiServer server(80);

const char* ssid = "krishna";
const char* password = "11223344";

void setup() {
  Serial.begin(115200);
  Serial.println("MQTT Broker");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  myBroker.init(); // Initialize the MQTT broker

  // Additional setup code (if needed)

  Serial.println("MQTT Broker started successfully");
}

void loop() {
  // Your custom loop logic here (if needed)
  // For example, publish or subscribe to MQTT topics
}
