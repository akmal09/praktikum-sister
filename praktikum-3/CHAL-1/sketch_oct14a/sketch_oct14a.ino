#define buzzer 27
#define led 26
#define sensorApi 25

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensorApi, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool readFireSensor = digitalRead(sensorApi);

  if (readFireSensor == LOW){
    Serial.println("Ada Api!");
  	tone(buzzer, 293);
    digitalWrite(led, HIGH);
    delay(500);
  }else{
    Serial.println("Tidak ada Api!");
    noTone(buzzer);
    digitalWrite(led, LOW);
  }

}