/*
  ------------------------------------------------------------
  Atividade: Pisca-LED Sem Delay
  @author Ana Caroline Pedrosa e Silva
  @version 1.0 22/04/2025
  
  Descrição: Sketch para fazer um LED piscar a cada segundo como uso de delay().

  Funcionalidades:
    1. Pisca LED a cada 1s
    2. Usa delay() controle bloqueante
  ------------------------------------------------------------
*/

#define LED 13

void setup() {
  pinMode(LED, OUTPUT); 
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  delay(1000);
}