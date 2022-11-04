#include <MQ2.h>

#define pin 26
int lpg, co, smoke;
MQ2 mq2(pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mq2.begin();
  Serial.println("MULAI");
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
  Serial.print("nilai lpg ");
  Serial.println(lpg);
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();
  delay(1000);
}
