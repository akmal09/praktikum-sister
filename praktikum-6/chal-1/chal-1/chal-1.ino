const int capteur_A_humid = 2;
const int capteur_D_hujan = 25;
int readHumid;
int readHujan;
#define lembab 33
#define tidakLembab 32
#include <Servo.h>

Servo myservo;
bool servoUdahGerakHl = false;
bool servoUdahGerakThL = false;
bool servoUdahGerakThTl = false;
bool servoUdahGerakHTl = false;

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
  readHujan=digitalRead(capteur_D_hujan);
  
  if(readHumid < 500){
    digitalWrite(lembab, HIGH);
    digitalWrite(tidakLembab, LOW);
  }else{
    digitalWrite(lembab, LOW);    
    digitalWrite(tidakLembab, HIGH);    
  }

  if(readHujan == HIGH && (readHumid < 500)){
    // Hujan tidak turun tanah lembab
    if(servoUdahGerakThL == false){
      Serial.println("gerak 90");                        
       myservo.write(90);
       servoUdahGerakThL = true;
       servoUdahGerakHl = false;       
       servoUdahGerakThTl = false;   
       servoUdahGerakHTl = false;    
    }
       delay(15);
  }else if(readHujan == HIGH && (readHumid >= 500)){
        // Hujan tidak turun tanah kering
        if(servoUdahGerakThTl == false){
          servoUdahGerakThTl = true;
          servoUdahGerakThL = false;
          servoUdahGerakHl = false;  
          servoUdahGerakHTl = false;     
        }
  }else if(readHujan == LOW && (readHumid >= 500)){
        // Hujan turun tanah kering
        if(servoUdahGerakHTl == false){
          myservo.write(0);
          servoUdahGerakHTl = true;
          servoUdahGerakThTl = false;
          servoUdahGerakThL = false;
          servoUdahGerakHl = false;
        }
  }
  else if(readHujan == LOW && (readHumid < 500)){
      // hujan turun tanah lembab
      if(servoUdahGerakHl == false){
        myservo.write(90);
        servoUdahGerakHl = true;
        servoUdahGerakHTl = false;
        servoUdahGerakThTl = false;
        servoUdahGerakThL = false;
      }
  }
}
