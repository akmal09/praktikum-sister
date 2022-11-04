#include "DHT.h"
#define YOUR_PIN

#define DHTTYPE DHT11
#define DHTPIN 27
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHT11"));
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);  
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Sensor Gagal Terbaca!"));
    return;
  } 
  
  Serial.print(F("Kelembaban: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C"));
  Serial.print(f);
  Serial.print(F("°F"));
}
