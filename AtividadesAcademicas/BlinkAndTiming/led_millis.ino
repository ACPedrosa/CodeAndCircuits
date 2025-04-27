/*
  ------------------------------------------------------------
  Atividade: Pisca-LED Sem Delay
  Autor: Ana Caroline Pedrosa
  Data: 22/04/2025
  
  Descrição: Controla um LED piscando a cada 250ms sem usar delay().

  Funcionalidades:
    1. Pisca LED a cada 250ms
    2. Usa millis() para controle não bloqueante
  ------------------------------------------------------------
*/

#define LED_YELLOW 8

int ledState = LOW;
long tempo_anterior = 0;

long intervalo = 250;

void pisca_led(long intervalo){
  unsigned long tempo_atual = millis();
  if(tempo_atual - tempo_anterior > intervalo) {
    tempo_anterior = tempo_atual;
    ledState = !ledState;
    digitalWrite(LED_YELLOW, ledState);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_YELLOW, OUTPUT);
  digitalWrite(LED_YELLOW, ledState);
}

void loop(){
  pisca_led(intervalo);
}