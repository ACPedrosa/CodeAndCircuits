/*
  ------------------------------------------------------------
  Atividade: Pisca-LED em intervalos diferentes de tempo
  @author Ana Caroline Pedrosa e Silva & Paulo Alfeu S. Martins
  @version 3.0 29/04/2025
  
  Descrição: Fazer um led piscar de acordo com um intervalo definido pelo potenciometro.

  Funcionalidades:
    1. Pisca LED de acordo com o potenciometro
    2. Usa millis() para controle não bloqueante
    3. Modifica o estado do led de acordo com um intervalo
  ------------------------------------------------------------
*/

#define LED_PINO 8
const int analogInPin = A0;
 
unsigned long tempoAnterior = 0; 
bool estadoLed = false;

int sensorValue = 0; 
int intervalo = 0;  

void setup() {
  pinMode(LED_PINO, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  intervalo = map(sensorValue, 0, 1023, 200, 1000);

  if (millis() - tempoAnterior >= intervalo) {
    tempoAnterior = millis();   
    estadoLed = !estadoLed;
    digitalWrite(LED_PINO, estadoLed);
  }
}