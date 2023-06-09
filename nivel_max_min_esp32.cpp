#include <WiFi.h>

// Configurações da rede Wi-Fi
const char* ssid = "Tely 58647_5G";
const char* password = "universitarios";

// Pinos dos sensores de nível
const int sensor1Pin = 4; // Pino do sensor 1
const int sensor2Pin = 5; // Pino do sensor 2

// Nível de água mínimo e máximo (em percentagem)
const int minWaterLevel = 10;
const int maxWaterLevel = 90;

void setup() {
  Serial.begin(115200);

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando à rede Wi-Fi...");
  }

  Serial.println("Conectado à rede Wi-Fi");

  // Configura os pinos dos sensores de nível como entrada
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
}

void loop() {
  // Lê o valor dos sensores de nível
  int sensor1Value = digitalRead(sensor1Pin);
  int sensor2Value = digitalRead(sensor2Pin);

  // Calcula o nível de água atual em percentagem
  int waterLevel = map(sensor1Value + sensor2Value, 0, 2, 0, 100);

  // Verifica se o nível de água está abaixo do mínimo
  if (waterLevel < minWaterLevel) {
    Serial.println("Nível de água baixo! Acione a bomba.");
    // Aqui você pode adicionar o código para acionar a bomba d'água
  }

  // Verifica se o nível de água está acima do máximo
  if (waterLevel > maxWaterLevel) {
    Serial.println("Nível de água alto! Desligue a entrada de água.");
    // Aqui você pode adicionar o código para desligar a entrada de água
  }

  // Aguarda por um intervalo antes de fazer a próxima leitura
  delay(1000);
}
