# MQTT
[MQTT](http://mqtt.org/) is een asynchroon publish-subscribe protocol 'small'-devices.
Het is uitermate geschikt voor het versturen van berichten van en naar IOT-devices zoals
onze sensor.

## MQTT Broker
Iemand (ik) heeft een MQTT broker opgezet waar berichten naar toe gestuurd
kunnen worden. Als je je eigen broker op wilt zetten dan raad ik je aan om de
volgende [docker image](https://hub.docker.com/r/toke/mosquitto/) te gebruiken.
Deze is oud maar heeft ook de websocket aanstaan.

Wie docker heeft:

docker run -ti -p 1883:1883 -p 9001:9001 toke/mosquitto

Als je wilt kun je ook de [officiele Mosquito](https://hub.docker.com/_/eclipse-mosquitto/)
image gebruiken. Voor het gebruik van websockets moet je dan wel het een en ander configureren.

## Simple NodeJS client maken?
Er is een eenvoudige nodejs applicatie beschikbaar om mee te testen. Clone het github project
[kroonrichard/nodejs_mqtt_example](https://github.com/kroonrichard/nodejs_mqtt_example)

Leef je uit en/of vervolg met [verbind de sensor met het netwerk](ip_setup.md)
