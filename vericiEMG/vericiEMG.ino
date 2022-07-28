
#include <SPI.h>
#include "RF24.h"

int data[1];
RF24 radio(9,10);//CE -> 9 CSN -> 10
const uint64_t pipe = 0xE8E8F0F0E1LL;
int EMGpin = 0;
int EMGdeger;
void setup(void){
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(pipe);
}
void loop(void){
EMGdeger = analogRead(EMGpin);

data[0] = EMGdeger;
radio.write(data, 1);

Serial.println(EMGdeger);

delay(1);

}
