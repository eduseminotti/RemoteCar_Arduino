#include <VirtualWire.h>

#define servo1 9

#define pinRF  12

struct tipoPacote {
  int valor1;
  int valor2;
  int valor3;
};

tipoPacote pacote;

uint8_t buf[sizeof(pacote)];
uint8_t buflen = sizeof(pacote);

void setup() {
  servo45graus();
  pinMode(servo1, OUTPUT); //saída para o servo1

  //  vw_set_rx_pin(pinRF);
  //  vw_setup(2000);
  //  vw_rx_start();
}

void loop() {

  servo45graus();
  delay(2000);

  servo75graus();
  delay(2000);

  servo45graus();
  delay(2000);

  servo15graus();
  delay(2000);

  //  if ( vw_have_message() ) {
  //    vw_get_message(buf, &buflen);
  //    memcpy(&pacote, &buf, buflen);
  //  }
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
