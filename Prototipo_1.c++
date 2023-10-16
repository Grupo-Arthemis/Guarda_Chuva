#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
#include "DHT.h"

#define deviceID[] = "01"; //ID do dispositivo
#define DHTPIN 4 // Pino onde o sensor DHT11 está conectado
#define DHTTYPE DHT11 // Tipo do sensor DHT
#define REED_SWITCH_PIN 14 // Pino onde o reed switch está conectado
#define arraySize = 4; // Definindo tamanho da Array

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

char ssid[] = "Galaxy Felipe";
char pass[] = "Felipe100603";
char serverAddress[] = "https://api.tago.io/data";  // TagoIO address
char contentHeader[] = "application/json";
char tokenHeader[]   = "b6649bfb-bca8-4ee5-8cf6-5b8f021f4621"; // TagoIO Token
HTTPClient client; // Iniciar uma nova instância do cliente HTTP

void setup() {
  Serial.begin(9600);
  init_wifi();
  pinMode(DHTPIN, INPUT);
  dht.begin(); // Inicializar o sensor DHT11
  pinMode(REED_SWITCH_PIN, INPUT_PULLUP); // Configurar o reed switch como entrada com resistor pull-up
  for (int i = 0; i < arraySize; i++) {
    ChuvaMinuto[i] = 0.0; // Inicializa todos os elementos do array com 0
}
void init_wifi() {
  Serial.println("Conectando WiFi");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Conectado");
  Serial.print("Meu IP eh: ");
  Serial.println(WiFi.localIP());
}

int ReedSwitch = digitalRead(REED_SWITCH_PIN); // Variável do Reed Switch
float Umidade = dht.readHumidity(); // Variável de umidade
float Temperatura = dht.readTemperature(); // Variável de temperatura

float Chuva = 0;
float ChuvaHora = [arraySize];
float AddChuva = 1.6;

long Inicio = 0; // Tempo do inicio do aparelho
long Intervalo15 = 15 * 60 * 1000; // Controle de 15 Minutos
long Intervalo60 = Intervalo15 * 4; // Controle de 1 hora

int AnteriorRS = LOW; // Inicialize com um valor conhecido

void loop() {
  long Agora = millis();  // Obtém o tempo atual
  ReedSwitch;

  if (Agora - Inicio >= Intervalo15) { // Passou o intervalo definido
    Chuva = 0.0;  // Reseta a variável para 0
    Inicio = Agora;  // Atualiza o tempo da última reinicialização
  }

  if (ReedSwitch != AnteriorRS) { // Houve uma mudança no estado do reed switch
    if (ReedSwitch == HIGH) {
      // O reed switch mudou para HIGH (contato fechado)
      Chuva += AddChuva;
    } else {
      // O reed switch mudou para LOW (contato aberto)
      Chuva += AddChuva;
    }
    AnteriorRS = ReedSwitch; // Atualize o estado anterior
  }

}