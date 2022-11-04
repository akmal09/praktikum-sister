#define RV 33
int aV;
void setup()
{
pinMode(RV, INPUT);
  Serial.begin(9600);
}

void loop()
{
aV = analogRead(RV);
Serial.println(aV);
delay(10);
}