# esp8266_dht

## Wat heb je nodig
- Een Wemos D1 Mini Pro (die heb je als het goed is gekregen)
- Een usb-kabel voor je laptop met een micro-USB aansluiting
- Visual Studio Code
- PlatformIO of de Arduino IDE
- De USB-driver voor het flashen van de Wemos D1 Mini Pro

### Arduino IDE of PlatformIO
Je kunt zelf besluiten welke IDE je wilt gebruiken. Mijn voorkeur gaat uit naar PlatformIO maar je mag ook de Arduino IDE gebruiken.

De Arduino IDE en PlatformIO maken beide gebruik van dezelfde stack maar de integratie van PlatformIO is beter en het werken met in project libraries is veel gemakkelijker.

PlatformIO is te vinden op de [PlatformIO site](https://platformio.org/)
De Arduino IDE is te vinden op de [Arduino site](https://www.arduino.cc)

Het inrichten van de Arduino omgeving gaat niet automatisch. Het github-project [esp8266/Arduino](https://github.com/esp8266/Arduino) beschrijft hoe je het een en ander voorelkaar kunt krijgen.

### De USB-drivers
De Wemos D1 Mini Pro maakt gebruik van de CP2104 USB naar serieel converter. Hier moet nog een driver voor geinstalleerd worden deze kun je vinden op de [Silicon Labs Site](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

## Wat over de Wemos D1 Mini Pro en de ESP8266(EX)
Kun je vinden op de [Wemos Wiki](https://wiki.wemos.cc/products:d1:d1_mini_pro)
Voor diegene die het leuk vindt kun je daar ook lezen hoe je Micro Python of NodeMCU/lua kunt gebruiken.

Informatie over de ESP8266(EX) kun je vinden op de [Espressif site](https://www.espressif.com/en/products/hardware/esp8266ex/overview)

Als je denkt dat je alles hebt kun je verder met het [testen van je inrichting](docs/whatever.md)
