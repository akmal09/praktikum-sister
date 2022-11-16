#ifdef ESP32
 #include <WiFi.h>
#else
 #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
#include <Servo.h>
// Replace with your network credentials
const char* ssid = "ilmu kelautan";
const char* password = "est2001bos";
Servo myServo;
#define ldr 32
bool isServoAutomate = false;
bool isSubscribe = false;
bool isServoClosed = false;
int nilaiLdr;
 
// Initialize Telegram BOT
#define BOTtoken "5620247510:AAFecY8ZpLf5FAEyYrn9DtGSzgVZfmxHA1I"  // your Bot Token (Get from Botfather)
 
#ifdef ESP8266
 X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif
 
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
 
// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
 
 
// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
 Serial.println("handleNewMessages");
 Serial.println(String(numNewMessages));
 if(numNewMessages == 1){
   for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
  
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);
  
    String from_name = bot.messages[i].from_name; 
  
    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/close_servo to turn GPIO ON \n";
      welcome += "/open_servo to turn GPIO OFF \n";
      welcome += "/status to request current GPIO state \n";
      welcome += "/option to return the reply keyboard \n";
      welcome += "/subscribe to automate send condition via telegram bot \n";
      welcome += "/unsubscribe to unautomate send condition via telegram bot\n";
      bot.sendMessage(chat_id, welcome, "");     
    }
  
    if (text == "/close_servo") {
      bot.sendMessage(chat_id, "Servo is closed", "");
      if(isServoClosed == false){
         isServoClosed = true;  
         myServo.write(90);         
      }
    }
  
    if (text == "/open_servo") {
      bot.sendMessage(chat_id, "Servo is Open", "");
      if(isServoClosed == true){
       isServoClosed = false;
       myServo.write(0);                
      }
    }
  
    if (text == "/status") {
      String SubscribeResponse = "Light Intensity: "+ String(analogRead(ldr)) + "\n";
     if(isServoClosed){
       SubscribeResponse += "Servo Condition : Open";      
     }else{
       SubscribeResponse += "Servo Condition : Close";       
     }
     bot.sendMessage(chat_id, SubscribeResponse);
    }
  
    if (text == "/option") {
      String keyboardJson = "[[\"/subscribe\", \"/unsubscribe\"],[\"/open_servo\", \"/close_servo\"], [\"/status\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Choose one of the following options", "", keyboardJson, true);
    }
  
    if(text == "/subscribe"){
      isSubscribe = true;
    }
  
    if(text == "/unsubscribe"){
      isSubscribe = false;
    }
  }   
 }else{
      for (int i=0; i<numNewMessages+1; i++) {
        String chat_id = String(bot.messages[i].chat_id);
        String SubscribeResponse = "Light Intensity: "+ String(analogRead(ldr)) + "\n";
        if(isServoClosed){
          SubscribeResponse += "Servo Condition : Open";      
        }else{
          SubscribeResponse += "Servo Condition : Close";       
        }
        bot.sendMessage(chat_id, SubscribeResponse);
      }
 }
 
 
}
 
void setup() {
 Serial.begin(115200);
 myServo.attach(13);
 
 #ifdef ESP8266
   configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
   client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
 #endif

 // Connect to Wi-Fi
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 #ifdef ESP32
   client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
 #endif
 while (WiFi.status() != WL_CONNECTED) {
   delay(1000);
   Serial.println("Connecting to WiFi..");
 }
 // Print ESP32 Local IP Address
 Serial.println(WiFi.localIP());
 pinMode(ldr, INPUT);
}
 
void loop() {
 if (millis() > lastTimeBotRan + botRequestDelay)  {
   int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
 
   while(numNewMessages) {
    Serial.println("got response");
    handleNewMessages(numNewMessages);
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
   }
   lastTimeBotRan = millis();
   if(isSubscribe){
      Serial.println("masuk ke is sub");
      if(!numNewMessages){
        handleNewMessages(numNewMessages);
        numNewMessages = bot.getUpdates(bot.last_message_received + 1);   
        delay(10000);     
      }
    }
 }
}
