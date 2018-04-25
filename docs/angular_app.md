# Een angular applicatie opzetten
Voor het opzetten van de angular applicatie gebruiken we Angular CLI.

Voor het ontwikkelen van Angular applicatie heb je [nodejs](https://nodejs.org/en/) nodig.
Als IDE raad ik [Visual Studio Code](https://code.visualstudio.com/) aan.

## Angular CLI
Op de [angular-cli github repo](https://github.com/angular/angular-cli) staat hoe je een
nieuwe applicatie maakt.

Volg de handleiding todat je een werkende applicatie hebt.

## Een websocket MQTT-client
Installeer de [ngx-mqtt](https://www.npmjs.com/package/ngx-mqtt) MQTT-client.

Volg de onderstaande stappen (wellicht kan je hier samen met een collega aan werken),
deze komen uit de documentatie van de client.

Voeg de volgende import to aan de app.module.ts file.

```typescript
import {
  IMqttMessage,
  MqttModule,
  MqttService,
  IMqttServiceOptions
} from 'ngx-mqtt';
```

De volgende sectie moet worden toegevoegd aan app.module.ts om de service to configureren

```typescript
export const MQTT_SERVICE_OPTIONS: IMqttServiceOptions = {
  hostname: 'localhost',
  port: 9001,
  path: '/mqtt'
};
```

De laatste toevoeging aan app.module.ts maakt inject van de service mogelijk in de componenten.

```typescript
export function mqttServiceFactory() {
  return new MqttService(MQTT_SERVICE_OPTIONS);
}

@NgModule({
  imports: [
    ...
    MqttModule.forRoot({
      provide: MqttService,
      useFactory: mqttServiceFactory
    })
  ]
  ...
})
```

## Ruim de rotzooi op
We gaan de app component gebruiken om de temperatuur te tonen. Ruim alle onzin uit de app.component.html op.

Vervang dit bijv door
```html
<div style="text-align:center">
  <h1>
    {{ temp }}
  </h1>
</div>
```

Doe een save all en het resultaat is een lege pagina.

## Voeg de service toe

Voeg een constructor toe aan app.component.ts (zie ook de client documentatie).
```typescript
constructor(private mqttService: MqttService){
  this.subscription = this.mqttService.observe('my/topic').subscribe((message: IMqttMessage) => {
    this.temp = message.payload.toString();
  });
}
```
Je zult nog iets met de variabelen, topics en de imports moeten doen !!! Als je dat gedaan hebt moet alles werken. Opslaan en kijken.

## Suggesties voor de volgende keer
- Een client in spring
- Een particale.io implementatie
- ReactiveX operaties op een temperatuur stream
- Een Chat Bot maken voor het opvragen van de temperatuur
- etc. etc.
- Of iets compleet anders
