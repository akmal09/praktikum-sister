const int capteur_A_humid = 2;
const int capteur_D_hujan = 25;
int readHumid;
int readHujan;
#define lembab 25
#define tidakLembab 32
#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(capteur_A_humid, INPUT);
  pinMode(capteur_D_hujan, INPUT);
  pinMode(lembab, OUTPUT);
  pinMode(tidakLembab, OUTPUT);
  myservo.attach(13);
  Serial.begin(9600);
}

void loop() {
  // ATAP TERBUKA DERAJAT 0, TERTUTUP DERAJAT NYA 90
  // put your main code here, to run repeatedly:
  readHumid=analogRead(capteur_A_humid);
  readHujan=analogRead(capteur_D_hujan);
  if(readHumid < 500){
    digitalWrite(lembab, HIGH);
    digitalWrite(tidakLembab, LOW);
  }else{
    digitalWrite(lembab, LOW);    
    digitalWrite(tidakLembab, HIGH);    
  }

  if(readHujan == LOW && (readHumid < 500)){
       myservo.write(0);
  }else if(readHujan == LOW && (readHumid >= 500)){
      myservo.write(90);
  }else if(readHujan == HIGH && (readHumid >= 500)){
      myservo.write(0);
  }
  else if(readHujan == HIGH && (readHumid < 500)){
      myservo.write(90);
  }
}
