#include <ESP8266WiFi.h>
#include "ThingSpeak.h" 
#include <Ultrasonic.h>

//constantes :)
const int trigPin = 5;
const int echoPin = 4;
const int ledPinGreen1 = 12;
const int ledPinGreen2 = 14;
const int ledPinBlue1 = 15;
//const int ledPinBlue2 = 13;
const int ledPinRed = 16;

const char* myWriteAPIKey = "MQ9GD7Y95M2XHOFH";

//variaveis :)
int distance = 0;
char ssid[] = "nomedowifi";  
char pass[] = "senhadowifi";   
unsigned long myChannelNumber = 2142559;

//classes :)
Ultrasonic ultrasonic(trigPin, echoPin);
WiFiClient client;

void setup() {
  Serial.begin(115200);  // Initialize serial
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for Leonardo native USB port only
  }

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  pinMode(ledPinGreen1, OUTPUT);
  pinMode(ledPinGreen2, OUTPUT);
  pinMode(ledPinBlue1, OUTPUT);
  //pinMode(ledPinBlue2, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
}

void loop() {

  // Connect or reconnect to WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  distance = ultrasonic.distanceRead(CM);
  Serial.println(distance);

  if (distance <= 4) {
    digitalWrite(ledPinGreen1, HIGH);
    delay(5000);
    digitalWrite(ledPinGreen1, LOW);
    delay(5000);
  }

  else if (distance = 5 and distance < 7) {
    digitalWrite(ledPinGreen2, HIGH);
    delay(5000);
    digitalWrite(ledPinGreen2, LOW);
    delay(5000);
  }

  else if (distance >= 8) {
    digitalWrite(ledPinBlue1, HIGH);
    delay(5000);
    digitalWrite(ledPinBlue1, LOW);
    delay(5000);
  }


  int x = ThingSpeak.writeField(myChannelNumber, 1, distance, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }



  delay(20000);  // Wait 20 seconds to update the channel again
}
