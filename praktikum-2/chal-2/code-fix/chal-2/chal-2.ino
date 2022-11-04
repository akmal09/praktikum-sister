#define pushButton 26
#define LDR 14
#define led 27
bool tekanPushButton;
int nilaiSensor = 0; 
bool onLight = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton, INPUT);
  pinMode(LDR, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(onLight);
  nilaiSensor = analogRead(LDR);
  //Serial.println(nilaiSensor);
  tekanPushButton = digitalRead(pushButton);
  //Serial.println(tekanPushButton);

  if(nilaiSensor >= 1000){
      if(onLight == 1){
        digitalWrite(led, HIGH);      
        delay(500);
      }else{
        digitalWrite(led, LOW);     
        delay(500);                        
      }
       
  }else{
      if(onLight == 0 || onLight == 1){
        digitalWrite(led, LOW);  
        delay(500);
      }
  }

  if(tekanPushButton == 1){
        Serial.print("nilai sensor nya ");
        Serial.print(nilaiSensor);
        Serial.println("button tekan");
        if(onLight == 1)onLight = 0;
        else onLight = 1;
        delay(1000);
      }
  // delay(1000);
}
