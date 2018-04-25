# Versturen van berichten naar de broker

We doorlopen de volgende stappen:
- Installeer de PubSubClient via de Library Manager (via de start button), zoek naar de PubSubClient.
- Voeg de noodzakelijke code toe om de gegevens van de sensor naar een topic naar keuze te publishen.

# De PubSubClient
Het bij de library meegeleverde code werkt niet voor ons kaartje gebruik [dit voorbeeld](https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino)
voor de implementatie

# Even helpen

In de voorbeeld code zie je de volgende regels
```c
char msg[50];
snprintf (msg, 75, "hello world #%ld", value);
client.publish("outTopic", msg);
```
De documentatie van de verschillende c-functies kun je terecht op [www.cplusplus.com](http://www.cplusplus.com/reference/cstdio/snprintf/)
