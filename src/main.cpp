#include <Arduino.h>

struct Led
{
  int pino;
  int tempo;
};

Led leds[3] = {
  {4, 5000}, // Vermelho
  {5, 2000}, // Amarelo
  {18, 5000}  // Verde
};

enum Etapa { VERMELHO, AMARELO_SUBINDO, VERDE, AMARELO_DESCENDO };
Etapa etapa = VERMELHO;

void acender(int indice)
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(leds[i].pino, LOW);
  }

  digitalWrite(leds[indice].pino, HIGH);
}

void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(leds[i].pino, OUTPUT);
  }

  acender(0);
}

void loop()
{
  switch (etapa)
  {
    case VERMELHO:
      acender(0);
      delay(leds[0].tempo);
      break;
    case AMARELO_SUBINDO:
      acender(1);
      delay(leds[1].tempo);
      break;
    case VERDE:
      acender(2);
      delay(leds[2].tempo);
      break;
    case AMARELO_DESCENDO:
      acender(1);
      delay(leds[1].tempo);
      break;
  }

  delay(100);
  etapa = (Etapa)((etapa + 1) % 4);
}