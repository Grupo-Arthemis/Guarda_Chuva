#define REED_SWITCH 13
#define arraySize 4
#define TIPO_CHUVA 1
#define TIPO_TEMPERATURA 2
#define TIPO_UMIDADE 3

void setup() {
  Serial.begin (9600);
  pinMode (REED_SWITCH, INPUT);
  attachInterrupt(digitalPinToInterrupt(REED_SWITCH), count, FALLING); //Debouncing Reed Switch
}

float chuva = 0;
float addChuva = 1.6;
float chuvaH = 0;
bool reedStats = false;

float lastChuva [arraySize]  = {0, 0, 0, 0};
int arrayCounter = 0;

long controle = 0; // Tempo do inicio do aparelho
long intervalo = 5 * 1000; // Controle de Minutos

void count(void) {
  if (!reedStats) {
    reedStats = true;
    chuva += addChuva;
  }
}

void loop() {
  long agora = millis();  // Obtém o tempo atual
  if (reedStats) {
    delay(300);
    reedStats = false;
    Serial.print("chuva: ");
    Serial.println (chuva);
  }
  if (agora - controle >= intervalo) {
    if (arrayCounter >= arraySize) {
      arrayCounter = 0;
      for (int i = 0; i < arraySize; i++) {
        chuvaH = chuvaH + lastChuva[i];
      }
      Serial.print("Soma = "); Serial.println(chuvaH);
      chuvaH = 0;
    }
    lastChuva[arrayCounter] = chuva;
    arrayCounter = arrayCounter + 1;
    chuva = 0;
    Serial.print("lastChuva: [");
    for (int i = 0; i < arraySize; i++) {
      Serial.print(lastChuva[i]);
      if (i < arraySize - 1) {
        Serial.print(", ");
      }
    }
    Serial.println("]");
    controle = millis();
  }
}
