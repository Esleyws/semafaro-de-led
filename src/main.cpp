#include <Arduino.h>

const int LED_VERMELHO = 4;
const int LED_AMARELO = 5;
const int LED_VERDE = 18;
int tempo;
int etapa = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
}

void loop()
{
  if (etapa == 0)
  {
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, LOW);

    Serial.println("LED Amarelo Ligado");

    delay(tempo = 2000);
  }
  else if (etapa == 1)
  {
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);

    Serial.println("LED Verde Ligado");

    delay(tempo = 5000);
  }
  else if (etapa == 2)
  {
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, LOW);

    Serial.println("LED Amarelo Ligado");

    delay(tempo = 2000);
  }
  else if (etapa == 3)
  {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);

    Serial.println("LED Vermelho Ligado");

    delay(tempo = 5000);
  }

  etapa++;
  if (etapa > 3)
  {
    etapa = 0;
  }
}