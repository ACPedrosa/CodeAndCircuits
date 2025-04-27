/*
  ------------------------------------------------------------
  Atividade: Pisca-LED com Botão usando millis()
  @author Ana Caroline Pedrosa e Silva
  @version 1.0 24/04/2025
  
  Descrição: Modifica a frequência de piscadas de um led. Quando o botão não
  está pressionado, o led pisca de 1 em 1 segundo. Quando o botão está pressionado, o led
  pisca de 0,5 em 0,5 segundos.

  Funcionalidades:
    1. Pisca LED a cada 1s ou 0.5s de acordo com o estado do botão
    2. Usa millis() para controle não bloqueante
  ------------------------------------------------------------
*/


#define LED_YELLOW 8
#define BUTTON_LED 7

int ledState = LOW;
int buttonState = 0;

long tempo_anterior = 0;

long intervalo_simples = 1000;
long intervalo_button = 500;

void setup() {
  Serial.begin(9600);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(BUTTON_LED, INPUT_PULLUP);

  digitalWrite(LED_YELLOW, ledState);
}

void loop(){
  buttonState = digitalRead(BUTTON_LED);

  if(!buttonState){
    pisca_led(intervalo_button);
  } 
  pisca_led(intervalo_simples);
}

void pisca_led(long intervalo){
  unsigned long tempo_atual = millis();
  if(tempo_atual - tempo_anterior > intervalo) {
    tempo_anterior = tempo_atual;
    ledState = !ledState;
    digitalWrite(LED_YELLOW, ledState);
  }
}