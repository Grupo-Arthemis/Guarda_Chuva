#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
#include "DHT.h"

#define deviceID[] = "01"; //ID do dispositivo
#define DHTPIN 4 // Pino onde o sensor DHT11 está conectado
#define DHTTYPE DHT11 // Tipo do sensor DHT
#define REED_SWITCH_PIN 14 // Pino onde o reed switch está conectado

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

char ssid[] = "Galaxy Felipe";
char pass[] = "Felipe100603";
char serverAddress[] = "https://api.tago.io/data";  // TagoIO address
char contentHeader[] = "application/json";
char tokenHeader[]   = "b6649bfb-bca8-4ee5-8cf6-5b8f021f4621"; // TagoIO Token
HTTPClient client; // Iniciar uma nova instância do cliente HTTP

int ReedSwitch = digitalRead(REED_SWITCH_PIN); // Variável do Reed Switch
float Umidade = dht.readHumidity(); // Variável de umidade
float Temperatura = dht.readTemperature(); // Variável de temperatura
float Chuva = 0;
float ChuvaMinuto = [];
float ChuvaHora = ;
float AddChuva = 1.6;
long Agora = 0;
long Controle = 0;
int AnteriorRS = LOW; // Inicialize com um valor conhecido

void loop() {
  ReedSwitch;

  if (ReedSwitch != AnteriorRS) {
    // Houve uma mudança no estado do reed switch
    if (ReedSwitch == HIGH) {
      // O reed switch mudou para HIGH (contato fechado)
      Chuva += AddChuva
    } else {
      // O reed switch mudou para LOW (contato aberto)
      Chuva += AddChuva
    }
    AnteriorRS = ReedSwitch; // Atualize o estado anterior
  }

  // Outro código do loop...
}

