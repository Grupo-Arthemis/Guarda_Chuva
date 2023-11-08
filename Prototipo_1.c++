#define deviceID = 1    //ID do dispositivo
#define DHTPIN 15       // Pino onde o sensor DHT11 está conectado
#define DHTTYPE DHT11   // Tipo do sensor DHT
#define REED_SWITCH 13  // Pino onde o reed switch está conectado
#define arraySize 10    // Definindo o tamanho da Array

/* Definindo regra de status return */
#define TIPO_CHUVA 1
#define TIPO_TEMPERATURA 2
#define TIPO_UMIDADE 3

/* Incluindo bibliotecas */
#include "DHT.h"
#include "ArduinoJson.h"
#include "EspMQTTClient.h"

DHT dht(DHTPIN, DHTTYPE);

EspMQTTClient client //MQTT and WiFi configuration
(
  "AndroidAP5599",       //nome da sua rede Wi-Fi
  "barreto351",          //senha da sua rede Wi-Fi
  "mqtt.tago.io",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  "b6649bfb-bca8-4ee5-8cf6-5b8f021f4621",     // Código do Token
  "Guarda_Chuva FIAP Paulista",              //Nome do device
  1883                  //Porta de comunicação padrao
);

void setup() {
  Serial.begin(9600);
  Serial.println("Conectando WiFi");
  while (!client.isWifiConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");
  Serial.println("Conectando com o broker MQTT");
  while (!client.isMqttConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  pinMode(DHTPIN, INPUT);
  dht.begin();  // Inicializar o sensor DHT11
  pinMode(REED_SWITCH, INPUT);
  attachInterrupt(digitalPinToInterrupt(REED_SWITCH), count, FALLING);  //Debouncing Reed Switch
}

void onConnectionEstablished()
{}

int statusCode = 0;
char chuvaData[300];
char umidadeData[300];
char tempData[300];
char anyData[30];

float temperatura = 0;
float umidade = 0;
float chuva = 0;
float addChuva = 0.4;
float chuvaH = 0;
bool reedStats = false;

float lastChuva[arraySize] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int arrayCounter = 0;

long controle = 0;           // Tempo do inicio do aparelho
long intervalo = 20 * 1000;  // Controle de Minutos

// Função para obter o status com base no valor
void getStatus(float value, int variableName, char* retorno) {
  switch (variableName) {

    case TIPO_CHUVA:
      if (value >= 15.0) {
        strcpy(retorno, ";ChuvaForte");
      } else if (value >= 5.0) {
        strcpy(retorno, ";ChuvaMedia");
      } else if (value > 0) {
        strcpy(retorno, ";ChuvaFraca");
      } else {
        strcpy(retorno, ";ChuvaNull");
      }
      break;

    case TIPO_TEMPERATURA:
      if (value >= 30.0) {
        strcpy(retorno, ";TemperaturaAlta");
      } else if (value >= 17.0) {
        strcpy(retorno, ";TemperaturaBoa");
      } else if (value > 0) {
        strcpy(retorno, ";TemperaturaBaixa");
      }
      break;

    case TIPO_UMIDADE:
      if (value >= 80.0) {
        strcpy(retorno, ";UmidadeAlta");
      } else if (value >= 50.0) {
        strcpy(retorno, ";UmidadeBoa");
      } else if (value > 0) {
        strcpy(retorno, ";UmidadeBaixa");
      }
      break;
  }
}

void count(void) {
  if (!reedStats) {
    reedStats = true;
    chuva += addChuva;
  }
}

void loop() {
  long agora = millis();                      // Obtém o tempo atual
  float umidade = dht.readHumidity();         // Variável de umidade
  float temperatura = dht.readTemperature();  // Variável de temperatura

  if (reedStats) {
    delay(300);
    reedStats = false;
  }
  if (agora - controle >= intervalo) {
    if (arrayCounter >= arraySize) {
      arrayCounter = 0;
    }

    lastChuva[arrayCounter] = chuva;
    arrayCounter = arrayCounter + 1;

    for (int i = 0; i < arraySize; i++) {
      chuvaH = chuvaH + lastChuva[i];
    }

    Serial.print("lastChuva: [");
    for (int i = 0; i < arraySize; i++) {
      Serial.print(lastChuva[i]);
      if (i < arraySize - 1) {
        Serial.print(", ");
      }
    }

    /* Mandando dados para TAGO */
    char varStatus[100];
    char docInfo[300];
    char bufferJson[100];

    StaticJsonDocument<300> documentoJson;

    /* Informações de Chuva*/
    dtostrf(chuvaH, 6, 2, anyData);
    strncat(chuvaData, anyData, 100);
    getStatus(chuvaH, TIPO_CHUVA, varStatus);
    strncat(chuvaData, varStatus, 100);
    documentoJson["variable"] = "Chuva";
    documentoJson["value"] = chuvaData;

    /* Informações de Umidade*/
    dtostrf(umidade, 6, 2, anyData);
    strncat(umidadeData, anyData, 100);
    getStatus(umidade, TIPO_UMIDADE, varStatus);
    strncat(umidadeData, varStatus, 100);
    documentoJson["variable"] = "Umidade";
    documentoJson["value"] = umidadeData;

    /* Informações de Temperatura*/
    dtostrf(temperatura, 6, 2, anyData);
    strncat(tempData, anyData, 100);
    getStatus(temperatura, TIPO_TEMPERATURA, varStatus);
    strncat(tempData, varStatus, 100);
    documentoJson["variable"] = "Temperatura";
    documentoJson["value"] = tempData;


    serializeJson(documentoJson, docInfo);
    Serial.println("Enviando dados");
    Serial.println(docInfo);

    client.publish("info", docInfo);
    delay(400);
    client.loop();

    chuvaH = 0;
    chuva = 0;

    controle = millis();
  }
}
