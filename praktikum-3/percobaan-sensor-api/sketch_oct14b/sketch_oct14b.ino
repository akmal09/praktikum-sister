#define Fire_digital 25
void setup() {
  Serial.begin(115200);
  pinMode(Fire_digital, INPUT);
}

void loop() {
  int firesensorDigital = digitalRead(Fire_digital);

  Serial.print("Fire Sensor: ");
  Serial.print(firesensorDigital);
  Serial.print("\t");
  Serial.print("\t"); 
  
  if (firesensorDigital == LOW){
    Serial.println("Ada Api!");
  }else{
    Serial.println("Tidak ada Api!");
  }
 delay(100);
}