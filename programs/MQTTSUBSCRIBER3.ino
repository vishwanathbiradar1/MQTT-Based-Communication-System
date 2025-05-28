//MQTT SUBSCRIBER 3

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Buzzer.h>

int buzzerPin = D1;
int button = D2;
const char* ssid = "ssid";
const char* password = "password";
const char* mqtt_server = "ip address";

WiFiClient espClient;
PubSubClient client(espClient);

const char* topic3 = "keypad/input";
const char* topicp = "ACK";

void setup() {
  Serial.begin(115200);
  pinMode(button,INPUT);
  Serial.println("MQTT Subscriber 1");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(buzzerPin, OUTPUT);
}

void setup_wifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {

    Serial.print("Attempting MQTT connection...");

    if (client.connect("NodeMCU_Button_Client")) {
      Serial.println("connected");
      client.subscribe(topic3);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 1 seconds");
      delay(1000);
    }

  }
}

void callback(char* topic3, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic3);
  Serial.print("] ");
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  if (message == "Key_3_Pressed") {
  client.publish(topicp, "ACK");
  tone(buzzerPin, 2000); // Turn on the buzzer at 2kHz
  delay(1000); // Wait for 1 second
  noTone(buzzerPin); // Turn off the buzzer
  delay(1000); // Wait for 1 second
  }
  else if (message == "Key_A_Pressed") {
  client.publish(topicp, "ACK");
  tone(buzzerPin, 2000); // Turn on the buzzer at 2kHz
  delay(1000); // Wait for 1 second
  noTone(buzzerPin); // Turn off the buzzer
  delay(1000); // Wait for 1 second
  }
  // Add more message handling logic as needed
}



void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();
  /*
if(digitalRead(button) == HIGH){
  client.publish(topicp, "ACK");
}
*/

}
