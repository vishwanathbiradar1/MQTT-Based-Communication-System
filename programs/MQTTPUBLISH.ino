//mqtt publish
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Keypad.h>
//#include <LiquidCrystal_I2C.h>
//Defining keypad pins and setup
int buzzerPin = D8;

const char* ssid = "ssid";
const char* password = "password";
const char* mqtt_server = "ip address";
const char* topic1 = "keypad/input";
const char* topic2 = "keypad/input";
const char* topic3 = "keypad/input";
const char* topicp = "ACK";

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

WiFiClient espClient;
PubSubClient client(espClient);

char key_layout[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {D0, D1, D2, D3};      // The ESP8266 pins connect to the row pins
byte pin_column[COLUMN_NUM] = {D4, D5, D6, D7}; // The ESP8266 pins connect to the column pins

Keypad keypad = Keypad( makeKeymap(key_layout), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );


void setup() {
  Serial.begin(115200);
  Serial.println("MQTT Publisher");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("MQTT Publisher started");
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("NodeMCU_Keypad_Client")) {
      Serial.println("connected");
      client.subscribe(topicp);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topicp, byte* payload, unsigned int length) {
  Serial.begin(115200);
  Serial.print("Message arrived [");
  Serial.println(topicp);
  Serial.print("] ");
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  if (message == "ACK") {
  tone(buzzerPin, 2000); // Turn on the buzzer at 2kHz
  delay(1000); // Wait for 1 second
  noTone(buzzerPin); // Turn off the buzzer
  delay(1000); // Wait for 1 second
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  char key = keypad.getKey();

  // Simple keypad reading logic
  if (key == '1') {
    client.publish(topic1, "Key_1_Pressed");
    delay(500); // Debounce delay  
    }
  else if (key == '2') {
    client.publish(topic2, "Key_2_Pressed");
    delay(500); // Debounce delay
  }
  else if (key == '3') {
    client.publish(topic3, "Key_3_Pressed");
    delay(500); // Debounce delay
  }
  else if (key == 'A') {
    client.publish(topic1, "Key_A_Pressed");
    client.publish(topic2, "Key_A_Pressed");
    client.publish(topic3, "Key_A_Pressed");
    delay(500); // Debounce delay
  }



}