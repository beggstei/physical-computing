
#include <WiFiNINA.h>
#include <MQTT.h>
#include "wifiCredentials.h"

const char ssid[] = WIFI_SSID;
const char pass[] = WIFI_PASS;
unsigned long lastMillis = 0;
int ledBlink; 

WiFiClient net;
MQTTClient client;
int status = WL_IDLE_STATUS;  

int valueNew = 1;
int valueOld = 0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(115200);
  // attempt to connect to Wifi network:
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print("No WiFi connection");
    delay(5000);
  }
  
  // once you are connected :
  Serial.println("You're connected to the network");

  //start mqtt
  client.begin("modob.cloud.shiftr.io", net);
  connect();
}

void loop() {
  client.loop();
  delay(10);
  valueNew = map(analogRead(A0), 0, 1023, 0, 255);
  
  // check if connected
  if (!client.connected()) {
    connect();
  }

  /*
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
  
    if(ledBlink == 1) {
      ledBlink = 0;
    }else {
      ledBlink = 1;
    }
    client.publish("/ledBlink", String(ledBlink));
  }
  */
  
  if (valueOld != valueNew){
    client.publish("/ledBlink", String(valueNew));
    valueOld = valueNew;
  }

}


void connect() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("No Wifi connection...");
    delay(1000);
  }

  while (!client.connect("b3n14m1n", "modob", "zaVmh6y35V81os8F")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected to MQTT!");
  client.subscribe("ledBlink");
}
