#define kiri 14
#define kanan 27
#define atas 26
#define bawah 25
#define kiriAtas 33
#define kiriBawah 32
#define kananAtas 2
#define kananBawah 4
#define x 34
#define y 35
int xValue = 0;
int yValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(atas,OUTPUT);
  pinMode(bawah,OUTPUT);
  pinMode(kiri,OUTPUT);
  pinMode(kanan,OUTPUT);
  pinMode(kiriBawah,OUTPUT);
  pinMode(kananBawah,OUTPUT);
  pinMode(kiriAtas,OUTPUT);
  pinMode(kananAtas,OUTPUT);
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

  xValue = map(analogRead(x), 0,1023, 0, 255);
  yValue = map(analogRead(y), 0,1023, 0, 255);
  Serial.print(xValue);
  Serial.print(", ");
  Serial.print(yValue);
  Serial.println("");

    
  if(xValue == 0 &&  yValue ==0){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,HIGH);
  }else if(xValue == 0 && (yValue >= 760 && yValue < 770)){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,HIGH);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);
  }else if(xValue == 0 && yValue == 1020){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,HIGH);
    digitalWrite(kananBawah,LOW);    
  }else if(xValue == 1020 && yValue == 1020){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,HIGH);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);  
  }else if(xValue == 1020 && yValue ==0){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,HIGH);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);
  }else if((xValue >= 720 && xValue < 730) && yValue == 0){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,HIGH);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);
  }else if((xValue >= 715 && xValue < 730) && (yValue >= 760 && yValue < 770)){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);    
  }else if((xValue >= 715 && xValue < 730)  && yValue == 1020){
    digitalWrite(kiri,LOW);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,HIGH);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);
  }else if(xValue == 1020 && (yValue >= 760 && yValue < 770)){
    digitalWrite(kiri,HIGH);
    digitalWrite(kanan,LOW);
    digitalWrite(atas,LOW);
    digitalWrite(bawah,LOW);
    digitalWrite(kiriAtas,LOW);
    digitalWrite(kiriBawah,LOW);
    digitalWrite(kananAtas,LOW);
    digitalWrite(kananBawah,LOW);
  }
}
