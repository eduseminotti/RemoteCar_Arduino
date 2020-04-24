#include <VirtualWire.h>

#define pinRF  12

struct tipoPacote {
  int valor1 ;
  int valor2 ;
  int valor3;
  
};

tipoPacote pacote; 

void setup() {

  vw_set_tx_pin(pinRF);
  vw_set_ptt_inverted(true);
  vw_setup(2000);


  //Serial.begin(9600);
}

void loop() {

  pacote.valor1 = 1;
  pacote.valor2 = 2;
  pacote.valor3 = 3;


  
  vw_send((uint8_t *)&pacote, sizeof(pacote));
  vw_wait_tx(); 
  
  delay(200);
}
