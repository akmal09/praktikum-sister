#define buz 22
#define pot 33

void setup() {
  // put your setup code here, to run once:
  pinMode(buz, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int getPotenValue = analogRead(pot);
  // int potValue = map(getPotenValue, 1,  1024, 0, 251);

  Serial.println(getPotenValue);
  // delay(1000);
  
}
