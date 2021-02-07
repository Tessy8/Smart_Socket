//#include <Ethernet.h>
//#include <BlynkSimpleEthernet.h>
//#include <SPI.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#define BLYNK_MAX_SENDBYTES 1200

int relay = 5; //D1   Normally Closed with Load
// red LED uses 220 ohms
int greenLED = 13;  //D7
int blueLED = 2;  //D4
char ssid[]= "AndroidAP";
char auth[] = "pZCnpA42Eg6WxJcSv3bkWwxwEwUpWBNj";
char pass[] = "qwertyui";


BLYNK_WRITE(V1){ //virtual pin 1
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(relay, HIGH);
    digitalWrite(greenLED, HIGH);
    Blynk.email("olanipekunopeyeoluwa1@gmail.com","Smart Socket ALERT!!","Device is On"); // add email widget to the blynk app setup
    Blynk.notify("Smart Socket ALERT- Device is On!!"); //add notification widget to the blynk app
    }
  else{
    digitalWrite(relay, LOW);
    digitalWrite(greenLED, LOW);
    Blynk.email("olanipekunopeyeoluwa1@gmail.com","Smart Socket ALERT!!","Device is Off");
    Blynk.notify("Smart Socket ALERT- Device is Off!!");
    }
}

BLYNK_CONNECTED(){
   Blynk.syncAll();  //to send the latest values of all values
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  Blynk.notify("Smart Socket ALERT- There is Power!!");
  digitalWrite(relay, LOW);
  WiFi.begin(ssid, pass);   
}

void loop()
{
  if (WiFi.status()== WL_CONNECTED){
    Serial.println("WiFi connection succesful");
    digitalWrite(blueLED, HIGH);
    }
  else{
    Serial.println("WiFi connection lost");
    digitalWrite(blueLED, LOW);
    }
  Blynk.run();
}
//  if (WiFi.status()== WL_NO_SHIELD){
//    Serial.println("WiFi shield not present");
//    digitalWrite(blueLED, LOW);
//    }
//  if (WiFi.status()== WL_CONNECTION_LOST){
//    Serial.println("WiFi connection lost");
//    digitalWrite(blueLED, LOW);
//    }
//  if (WiFi.status()== WL_CONNECT_FAILED){
//    Serial.println("WiFi connection failed");
//    digitalWrite(blueLED, LOW);
//    }
//  if (WiFi.status()== WL_DISCONNECTED){
//    Serial.println("WiFi connection lost");
//    digitalWrite(blueLED, LOW);
//    }
  
