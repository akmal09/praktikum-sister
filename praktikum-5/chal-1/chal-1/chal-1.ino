#define Fire_digital 32
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
#define BUZZER 33

void setup() {
  // Serial.begin(115200);
  pinMode(Fire_digital, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD SIAP");
  lcd.setCursor(2, 1);
  // lcd.print("HalloWorld");
}

void loop() {
  int firesensorDigital = digitalRead(Fire_digital);

  // lcd.print("Fire Sensor: ");
  // lcd.print(firesensorDigital);
  // lcd.print("\t");
  // lcd.print("\t"); 
  
  if (firesensorDigital == LOW){
    lcd.println("Ada Api!");
    tone(BUZZER, 293);
  }else{
    lcd.println("");
    noTone(BUZZER);
  }

 delay(100);
}