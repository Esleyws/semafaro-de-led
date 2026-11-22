#include <Arduino.h>

const int LED[3] = {4, 5, 18};
int tempo;
enum Etapa { VERMELHO, AMARELO_SUBINDO, VERDE, AMARELO_DESCENDO };
Etapa etapa = VERMELHO;

void setup()
{
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);

  digitalWrite(LED[0], HIGH);
  digitalWrite(LED[1], LOW);
  digitalWrite(LED[2], LOW);
}

void loop()
{
  switch (etapa)
  {
    case VERMELHO:
      tempo = 5000;
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      break;
    case AMARELO_SUBINDO:
      tempo = 2000;
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], LOW);
      break;
    case VERDE:
      tempo = 5000;
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], HIGH);
      break;
    case AMARELO_DESCENDO:
      tempo = 2000;
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], LOW);
      break;
  }
  
  delay(tempo);
  etapa = (Etapa)((etapa + 1) % 4);
}