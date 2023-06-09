/*
URL codigo: https://github.com/luisllamasbinaburo/ESP32-Examples/blob/main/35_Mqtt/ESP32_Utils_MQTT.hpp
*/

void InitMqtt() {
   mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
   SuscribeMqtt();
   mqttClient.setCallback(OnMqttReceived);
}

void ConnectMqtt() {
   while (!mqttClient.connected()) {
      Serial.print("Starting MQTT connection...");
      if (mqttClient.connect(MQTT_CLIENT_NAME)) {
         Serial.println(" MQTT connected");
         SuscribeMqtt();
      }
      else {
         Serial.print(" Failed MQTT connection, rc=");
         Serial.print(mqttClient.state());
         Serial.println(" try again in 5 seconds");
         delay(5000);
      }
   }
}

void HandleMqtt() {
   if (!mqttClient.connected()) {
      ConnectMqtt();
   }
   mqttClient.loop();
}
