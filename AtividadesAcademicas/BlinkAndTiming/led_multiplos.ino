/*
  ------------------------------------------------------------
  Atividade: Pisca-LED em intervalos diferentes de tempo
  @author Ana Caroline Pedrosa e Silva
  @version 3.0 24/04/2025
  
  Descrição: Pisca o LED_1 com intervalo de 350ms, o LED_2 com intervalo de
  2500ms. Além disso, ligar o LED_3 e permanecer ligado por 5 segundos quando o botão 1 for
  pressionado.  

  Funcionalidades:
    1. Pisca LED de acordo com seu intervalo
    2. Usa millis() para controle não bloqueante
    3. Modifica o estado do led de acordo com um intervalo
  ------------------------------------------------------------
*/

#define BUTTON_LED 7

#define LED_YELLOW 8
#define LED_GREEN 9
#define LED_RED 10

int ledStateRed = LOW;
int ledStateGreen = LOW;
int ledStateYellow = LOW;

int buttonState = 0;

unsigned long tempo_anterior_green = 0;
unsigned long tempo_anterior_red = 0;
long tempo_anterior_yellow = 0;

long intervalo_led_red = 350;
long intervalo_led_green = 2500;
long intervalo_button = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(BUTTON_LED, INPUT_PULLUP);

  digitalWrite(LED_YELLOW, ledStateYellow);
  digitalWrite(LED_GREEN, ledStateGreen);
  digitalWrite(LED_RED, ledStateRed);
}

void loop(){
  buttonState = digitalRead(BUTTON_LED);

  pisca_led(LED_GREEN, intervalo_led_green, &ledStateGreen, &tempo_anterior_green);
  pisca_led(LED_RED, intervalo_led_red, &ledStateRed, &tempo_anterior_red);

  if(!buttonState){
    acender_led(LED_YELLOW, intervalo_button, &ledStateYellow, &tempo_anterior_yellow);
  } 
}

//Alteração: foi usado ponteiros para garatir a mudança de estado do led fora do escopo da função
void pisca_led(int pino, long intervalo, int *estado_led, unsigned long *tempo_anterior) {
  unsigned long tempo_atual = millis();
  
  if (tempo_atual - *tempo_anterior >= intervalo) {
    *tempo_anterior = tempo_atual;
    *estado_led = !(*estado_led); 
    digitalWrite(pino, *estado_led);
  }
}

void acender_led(int pino, long intervalo, int *estado_led, unsigned long *tempo_anterior) {
  unsigned long tempo_atual = millis();

  if (*estado_led == LOW) {
    *estado_led = HIGH;
    digitalWrite(pino, *estado_led);  
    *tempo_anterior = tempo_atual; 
  }
  if (tempo_atual - *tempo_anterior >= intervalo) {
    *estado_led = LOW; 
    digitalWrite(pino, *estado_led);  
  }
}
