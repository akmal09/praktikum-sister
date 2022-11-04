#include <MQ2.h>
#define buzzer 27
#define led1 26
#define led2 33
#define sensorApi 25
#define pinmq2 32

int lpg;
MQ2 mq2(pinmq2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensorApi, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  mq2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  bool readFireSensor = digitalRead(sensorApi);
  float* values = mq2.read(true);
  lpg = mq2.readLPG();

  if(lpg != 0){
    Serial.print("lpg bocor : ");
    Serial.println(lpg);
    digitalWrite(led1, HIGH);
    tone(buzzer, 293);
    delay(700); 
    noTone(buzzer);
    if (readFireSensor == LOW){
      Serial.println("LPG bbocor dan Api menyala !!!!!!");
      digitalWrite(led2, HIGH);
  	  tone(buzzer, 293);
      delay(500);
    }
  }
  else{
    if (readFireSensor == LOW){
      Serial.println("Ada Api!");
      digitalWrite(led2, HIGH);
  	  tone(buzzer, 293);
      delay(500);
    }else{
      
    }
    Serial.println("Tidak ada Api!");
    noTone(buzzer);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

}
