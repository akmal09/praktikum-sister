#include <FirebaseESP32.h>
#include  <WiFi.h>
// #include "DHT.h"
#define ldr 32
// Firebase
#define FIREBASE_HOST "https://sister-7-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_Authorization_key "jHBYglxwEKknykgpSAGZH3VF9PrZdmYwx3VG1SUl"
// Koneksi
#define WIFI_SSID "Kosan Maba" // Change the name of your WIFI
#define WIFI_PASSWORD "12345678" // Change the password of your WIFI
 
#define DHTPIN 14   
 
// #define DHTTYPE DHT11  
// DHT dht(DHTPIN, DHTTYPE);
int nilai;
 
FirebaseData firebaseData;
FirebaseJson json;
 
void setup() {
 
Serial.begin(115200);
//  dht.begin();
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting...");
 while (WiFi.status() != WL_CONNECTED)
 {
   Serial.print(".");
   delay(300);
 }
 Serial.println();
 Serial.print("IP Address: ");
 Serial.println(WiFi.localIP());
 Serial.println();
 Firebase.begin(FIREBASE_HOST,FIREBASE_Authorization_key);
  pinMode(ldr, INPUT);
}
 
void loop() {
 
//  float hum = dht.readHumidity();
//  float temp = dht.readTemperature(); 
 
//   if (isnan(hum) || isnan(temp)  ){
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }
 
//  Serial.print("Temperature: ");
//  Serial.print(temp);
//  Serial.print("°C");
//  Serial.print(" Humidity: ");
//  Serial.print(hum);
//  Serial.print("%");
//  Serial.println();
nilai = analogRead(ldr);
Serial.println("intensitas cahaya");
Serial.println(nilai);
 
 Firebase.setFloat(firebaseData, "/ESP32_APP/LIGHT_INTENSITY", nilai);
//  Firebase.setFloat(firebaseData, "/ESP32_APP/timestamp", String(getTime()));
//  Firebase.setFloat(firebaseData, "/ESP32_APP/HUMIDITY", hum);
  delay(200);
}
