#include <VirtualWire.h>

#define servo1 9
#define pinRF  3

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int delay1 = 1000;
int delay2 = 2000;


struct tipoPacote {
  int valor1;
  int valor2;
  int valor3;
};

tipoPacote pacote;
uint8_t buf[sizeof(pacote)];
uint8_t buflen = sizeof(pacote);


void back() {
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Gira o Motor B no sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void brake() {
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void front() {
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void frontRight() {
  //vira volante pra direita
  turnRight();
  front();
}

void frontLeft() {
  //vira volante pra direita
  turnLeft();
  front();
}

void backRight() {
  //vira volante pra direita
  turnRight();
  back();
}

void backLeft() {
  //vira volante pra direita
  turnLeft();
  back();
}

void turnRight() {
  servo75graus();
  delay(500);
}

void centralizedWheel() {
  servo45graus();
  delay(500);
}

void turnLeft() {
  servo15graus();
  delay(500);
}
void setup() {

  servo45graus();
  //centralizedWheel() ;
  pinMode(servo1, OUTPUT); //saída para o servo1

  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  vw_set_rx_pin(pinRF);
  vw_setup(2000);
  vw_rx_start();


}

void loop() {

  if ( vw_have_message() ) {
    vw_get_message(buf, &buflen);
    memcpy(&pacote, &buf, buflen);

    if (pacote.valor1 == 1) {
      turnRight();
      delay(2000);
      centralizedWheel();
    }
    if (pacote.valor2 == 2) {
      back();
      delay(2000);
      brake();
    }

    if (pacote.valor3 == 3) {
      turnLeft();

      delay(2000);
      centralizedWheel();
      delay(2000);

    }
  }
}

void servo0graus()              //Posiciona o servo em 0 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(600);      //0.6ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 32; i++)delayMicroseconds(600);
}

void servo15graus()              //Posiciona o servo em 0 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(800);      //0.6ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 32; i++)delayMicroseconds(800);
}

void servo30graus()              //Posiciona o servo em 0 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(950);      //0.6ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 32; i++)delayMicroseconds(950);
}

void servo45graus()              //Posiciona o servo em 0 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(1125);      //0.6ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 32; i++)delayMicroseconds(1125);

}

void servo60graus()              //Posiciona o servo em 0 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(1300);      //0.6ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 32; i++)delayMicroseconds(1300);

}
void servo75graus()              //Posiciona o servo em 0 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(1475);      //0.6ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 32; i++)delayMicroseconds(1475);
}
void servo90graus()             //Posiciona o servo em 90 graus
{
  digitalWrite(servo1, HIGH);  //pulso do servo
  delayMicroseconds(1650);     //1.5ms
  digitalWrite(servo1, LOW);   //completa periodo do servo
  for (int i = 0; i < 12; i++)delayMicroseconds(1650);
}
