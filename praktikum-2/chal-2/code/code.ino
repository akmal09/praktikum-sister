#define LDR 14
#define led 27
int nilai;
void setup(){
  pinMode(LDR, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  nilai = analogRead(LDR);
  Serial.println(nilai);
  if(nilai >= 1000) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
  delay(10);
}