#include <MQ2.h>
#define pin YOUR_PIN
int lpg, co, smoke;
MQ2 mq2(pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mq2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  * 1 = LPG in ppm
  * 2 = CO in ppm
  * 3 = SMOKE in ppm
  */


  float* values= mq2.read(true);
  //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();
  delay(1000);
}
