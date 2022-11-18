#include <FirebaseESP32.h>
#include <WiFi.h>
#include <Servo.h>
// Provide the token generation process info.
#include "addons/TokenHelper.h"
// Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
// Insert Authorized Email and Corresponding Password
#define USER_EMAIL "akmal@mail.com"
#define USER_PASSWORD "12345678"

// #include "DHT.h"
#define ldr 32
// Firebase
#define FIREBASE_HOST "https://sister-7-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_Authorization_key "AIzaSyDbNDzps96QRWbDk5x3BzwPoxiTtG2k1zc"
// Koneksi
#define WIFI_SSID "Redmi" // Change the name of your WIFI
#define WIFI_PASSWORD "12345678" // Change the password of your WIFI
 
int nilai;
bool tutup = true;
 
FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;

Servo myServo;
 
void setup() {
 
Serial.begin(115200);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting...");
  myServo.attach(13);
 while (WiFi.status() != WL_CONNECTED)
 {
   Serial.print(".");
   delay(300);
 }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  config.host = FIREBASE_HOST;
  config.api_key = FIREBASE_Authorization_key;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  
  Firebase.begin(&config, &auth);
  while ((auth.token.uid) == "") {
    Serial.println('Still Connecting');
    delay(500);
  }
  pinMode(ldr, INPUT);
}
 
void loop() {
  nilai = analogRead(ldr);

  if(nilai  < 3000){
    if(tutup == true){
      tutup = false;
      myServo.write(90);
    }
  }else{
    if(tutup == false){
      tutup = true;
      myServo.write(0);
    }
  }  
  
  Firebase.setFloat(firebaseData, "/ESP32_APP/LIGHT_INTENSITY", nilai);
  Firebase.setFloat(firebaseData, "/ESP32_APP/SERVO_CONDITION", tutup);
  //  Firebase.setFloat(firebaseData, "/ESP32_APP/timestamp", Firebase.setTimestamp(FirebaseData &fbdo, T path));
  Firebase.setTimestamp(firebaseData, "/ESP32_APP/timestamp");
  
  // cek nilai intensitas cahaya
  if(Firebase.getFloat(firebaseData, "/ESP32_APP/LIGHT_INTENSITY")){
    Serial.print("intensitas cahaya dari Firebase : ");
    Serial.println(firebaseData.to<int>());
  }
  
  // cek nilai kondisi servo
  if(Firebase.getFloat(firebaseData, "/ESP32_APP/SERVO_CONDITION")){
    Serial.print("Kondisi Servo dari Firebase : ");
    Serial.println(firebaseData.to<int>());
  }

  // cek timestamp
  if(Firebase.getInt(firebaseData, "/ESP32_APP/timestamp")){
    Serial.print("Kondisi timestamp dari Firebase : ");
    Serial.println(firebaseData.to<int>());    
  }

  delay(200);
}
