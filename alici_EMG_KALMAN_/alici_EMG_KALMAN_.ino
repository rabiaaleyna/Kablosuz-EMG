#include <SPI.h>
#include "RF24.h"
#include <SimpleKalmanFilter.h>

SimpleKalmanFilter simpleKalmanFilter1(2, 2, 0.1);

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int data[1];
void setup()
{
Serial.begin(115200);
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
}
void loop()
{
if (radio.available()){
bool done = false;
while (!done){
done = radio.read(data, 1);



 float real_value1 = data[0];
 float estimated_value1 = simpleKalmanFilter1.updateEstimate(real_value1);

  Serial.print(real_value1);
  Serial.print(",");
  Serial.println(estimated_value1);

}
}
}
