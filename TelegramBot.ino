//Developed by Shebin Jose Jacob

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>


#define LED 1
// Initialize Wifi connection to the router
const char* ssid     = "xxxx";
const char* password = "yyyy";


// Initialize Telegram BOT
const char BotToken[] = "xxxxxxxxxxx";

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);

 // the number of the LED pin  
void setup() 
{  
 Serial.begin(115200);  
 while (!Serial) {}  //Start running when the serial is open 
 delay(3000);  
 // attempt to connect to Wifi network:  
 Serial.print("Connecting Wifi: ");  
 Serial.println(ssid);  
 while (WiFi.begin(ssid, password) != WL_CONNECTED) 
       {  
   Serial.print(".");  
   delay(500);  
 }  
 Serial.println("");  
 Serial.println("WiFi connected");  
 bot.begin();  
 pinMode(LED, OUTPUT);  
}  
void loop() 
{  
 message m = bot.getUpdates(); // Read new messages  
 if (m.text.equals("on")) 
       {  
   digitalWrite(LED, 1);   
   bot.sendMessage(m.chat_id, "The Led is now ON");  
 }  
 else if (m.text.equals("off")) 
       {  
   digitalWrite(LED, 0);   
   bot.sendMessage(m.chat_id, "The Led is now OFF");  
 }  
}  
