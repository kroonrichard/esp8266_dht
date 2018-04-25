#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Ticker.h>
#include <WEMOS_DHT12.h>

const char* ssid = "****";
const char* password = "****";
const char* mqttServer = "192.168.0.157";
const char* topic = "/dht12/temp";

WiFiClient espClient;
PubSubClient client(espClient);
Ticker publishTask;
String clientId;
DHT12 dht12;

char payload[100];

void configWifi() {
  Serial.print("SSID: "); Serial.println(ssid);
  Serial.print("Password: "); Serial.println(password);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());
  clientId = "ESP8266Client-";
  clientId += String(random(0xffff), HEX);

  Serial.println("");
  Serial.println("Verbinding met WIFI netwerk");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

float readTemp(){
  if(dht12.get()==0){
      return dht12.cTemp;
  } else {
    return -999;
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Probeer een connectie met de broker op te zetten");
    if (client.connect(clientId.c_str())) {
      Serial.println("Verbinding met broker gemaakt");
    } else {
      Serial.print("Geen connect fout: "); Serial.print(client.state());
      Serial.println(" proberen het over 5 seconden opnieuw");
      delay(5000);
    }
  }
}


void readAndPublishTemp() {
  float temp = readTemp();
  if(temp > -999) { // Sensor niet ready?
    snprintf (payload, 100, "Temperatuur: %f", temp);
    Serial.println("Publish: "); Serial.println(payload);
    client.publish(topic, payload);
  } else {
    Serial.println("Geen temperatuur gelezen");
  }
}

void setup() {
  Serial.begin(9600);
  configWifi();
  client.setServer(mqttServer, 1883);
  publishTask.attach(5, readAndPublishTemp);
}

void loop() {
  // Connect of reconnect.
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
