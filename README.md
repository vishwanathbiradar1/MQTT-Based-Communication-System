# MQTT Based Communication System Using NodeMCU ESP32/ESP8266

## For Broker and WiFi Hotspot we inbuilt both program in one program and in one NodeMCU. Because when we use external WiFi router to connect Publisher and Subscriber to broker via the external WiFi router we has to update the WiFi ip address eventualy in the program and update/flash the NodeMCU it's time taking and not efficient the connection. It needs the static wifi address so it's not posible it every scenario so we come up with idea of making the broker as the WiFi router and connect the both publisher and subscriber to the brokers WiFi router. By making this it is easily connecting to the brokers WiFi router and connecting faster then earlier method and data transmission and receiving is also fast.


## IOT-Based-Smart-Keypad-Notification-System-Using-MQTT
This project implements a smart keypad notification system using MQTT (Message Queuing Telemetry Transport) protocol for communication between devices. The system consists of three main components: a keypad, an MQTT broker, and MQTT subscribers.

### Components:
1. Keypad (MQTT Publisher):
![publisher!]("images\publisher.jpg" "MQTT Publisher")
![publisher!](images\publisher_hw.jpg "MQTT Publisher")
   - Reads input from a 4x4 keypad matrix.
   - Publishes pressed key values to specific MQTT topics (keypad/input) based on the pressed key (1, 2, 3, or A).
   - Includes a buzzer for acknowledgment (ACK) signal.
2. MQTT Broker:
![broker!](images\broker.jpg "MQTT Broker")
![broker!](images\broker_hw.jpg "MQTT Broker")
   - Acts as a central hub for message routing between devices.
   - Manages topics and subscriptions for the system.
3. MQTT Subscribers:
![subscriber!](images\subscriber.jpg "MQTT Subscriber")
![subscriber!](images\subscribers_hw.jpg "MQTT Subscribers")
   - Three ESP8266 NodeMCU boards act as subscribers, each listening to a specific topic (keypad/input).
   - Trigger actions (e.g., activate a buzzer) upon receiving messages on their subscribed topics.
   - Send acknowledgment (ACK) messages back to the publisher.

### Functionality:
- Keypad Input: Users press keys on the 4x4 keypad to trigger actions.
- MQTT Communication: Keypad presses are published as messages to specific topics via the MQTT broker.
- Subscriptions: Subscribers listen to predefined topics and react to messages accordingly.
- Acknowledgement: Subscribers send ACK messages back to the publisher upon receiving specific key presses.
- Actions: Subscribers perform actions like activating a buzzer upon receiving specific key presses.

### Wiring:
- Connect the 4x4 keypad matrix to the designated pins on the ESP8266 NodeMCU acting as the publisher.
- Connect the buzzer to the specified pin on the publisher ESP8266 NodeMCU.
- Ensure proper wiring for the three ESP8266 NodeMCU boards acting as subscribers, including connections for buzzers and any other peripherals.


