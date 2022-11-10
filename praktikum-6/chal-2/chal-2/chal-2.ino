const int capteur_A_humid = 2;
const int capteur_D_hujan = 25;
#define capteur_A_hujan  25
int readHumid;
int readHujanDigital;
#define lembab 33
#define tidakLembab 32
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

Servo myservo;
bool servoUdahGerakHl = false;
bool servoUdahGerakThL = false;
bool servoUdahGerakThTl = false;
bool servoUdahGerakHTl = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(capteur_A_humid, INPUT);
  pinMode(capteur_D_hujan, INPUT);
  pinMode(capteur_A_hujan, INPUT);
  pinMode(lembab, OUTPUT);
  pinMode(tidakLembab, OUTPUT);
  myservo.attach(13);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  // lcd.setCursor(0, 0);
  // lcd.print("Arduino");
  // lcd.setCursor(2, 1);
  // lcd.print("HalloWorld");
}

void loop() {
  // ATAP TERBUKA DERAJAT 0, TERTUTUP DERAJAT NYA 90
  // put your main code here, to run repeatedly:
  readHumid=analogRead(capteur_A_humid);
  readHujanDigital=digitalRead(capteur_D_hujan);
  
  if(readHumid < 500){
    digitalWrite(lembab, HIGH);
    digitalWrite(tidakLembab, LOW);
  }else{
    digitalWrite(lembab, LOW);    
    digitalWrite(tidakLembab, HIGH);    
  }

  if(readHujanDigital == HIGH && (readHumid < 500)){
    // Hujan tidak turun tanah lembab
    if(servoUdahGerakThL == false){
       myservo.write(90);
       servoUdahGerakThL = true;
       servoUdahGerakHl = false;       
       servoUdahGerakThTl = false;   
       servoUdahGerakHTl = false;    
    }
       delay(15);
  }else if(readHujanDigital == HIGH && (readHumid >= 500)){
        // Hujan tidak turun tanah kering
        if(servoUdahGerakThTl == false){
          servoUdahGerakThTl = true;
          servoUdahGerakThL = false;
          servoUdahGerakHl = false;  
          servoUdahGerakHTl = false;     
        }
  }else if(readHujanDigital == LOW && (readHumid >= 500)){
        // Hujan turun tanah kering
        if(servoUdahGerakHTl == false){
          myservo.write(0);
          servoUdahGerakHTl = true;
          servoUdahGerakThTl = false;
          servoUdahGerakThL = false;
          servoUdahGerakHl = false;
        }
  }
  else if(readHujanDigital == LOW && (readHumid < 500)){
      // hujan turun tanah lembab
      if(servoUdahGerakHl == false){
        myservo.write(90);
        servoUdahGerakHl = true;
        servoUdahGerakHTl = false;
        servoUdahGerakThTl = false;
        servoUdahGerakThL = false;
      }
  }
  lcd.setCursor(0, 0);
  lcd.print("in-hujan : ");
  lcd.print(analogRead(capteur_A_hujan)); 
  lcd.setCursor(0, 1); 
  lcd.print("ikl-tanah : ");
  lcd.print(readHumid);
  delay(1000);
}
