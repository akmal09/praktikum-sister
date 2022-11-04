// C++ code
//
int potensio = 0;
#define buzzer 12
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(14, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  potensio = map(analogRead(14), 0, 1023, 0, 250);
  tone(buzzer, potensio*20);
  Serial.println(potensio * 5);
  delay(1000);
}