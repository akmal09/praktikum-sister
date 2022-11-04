#define kiri 14
#define kanan 27
#define atas 26
#define bawah 25
#define kiriAtas 33
#define kiriBawah 32
#define kananAtas 2
#define kananBawah 4
#define x 35
#define y 34
int xValue = 0;
int yValue = 0;

void setup() {
  // put your setup code here, to run once:
  // pinMode(atas,OUTPUT);
  // pinMode(bawah,OUTPUT);
  // pinMode(kiri,OUTPUT);
  // pinMode(kanan,OUTPUT);
  // pinMode(kiriBawah,OUTPUT);
  // pinMode(kananBawah,OUTPUT);
  // pinMode(kiriAtas,OUTPUT);
  // pinMode(kananAtas,OUTPUT);
  Serial.begin(9600);
  pinMode(x,OUTPUT);
  pinMode(y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(kiri,HIGH);
  // digitalWrite(kanan,HIGH);
  // digitalWrite(atas,HIGH);
  // digitalWrite(bawah,HIGH);
  // digitalWrite(kiriAtas,HIGH);
  // digitalWrite(kiriBawah,HIGH);
  // digitalWrite(kananAtas,HIGH);
  // digitalWrite(kananBawah,HIGH);
  xValue = analogRead(x);
  yValue = analogRead(y);
  Serial.print(map(xValue, 0,1023, 0, 7));
  Serial.print(", ");
  Serial.print(map(yValue, 0,1023, 7, 0));
  Serial.println("");
  
}
