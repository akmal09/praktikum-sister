int xValue = 0;
int yValue = 0;
int bValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(14, INPUT);
}

void loop() {
  xValue = analogRead(25);
  yValue = analogRead(26);
  bValue = digitalRead(13);
  Serial.print(xValue, DEC);
  Serial.print(",");
  Serial.print(yValue, DEC);
  Serial.print(",");
  Serial.print(!bValue);
  Serial.print("\n");
  delay(10);
}