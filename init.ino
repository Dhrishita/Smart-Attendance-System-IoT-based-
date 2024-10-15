#include <ESP8266WiFi.h>
#include <SPI.h>
#include <RFID.h>
#include "FirebaseESP8266.h"

#define FIREBASE_HOST "smart-attendance-system-c43a7-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "6qqqCLvKRKS1fDsMRWVpimTTXqRPA0BJyT571t5t"
RFID rfid(D8, D0); // D8: pin of tag reader SDA, D0: pin of tag reader RST
unsigned char str[MAX_LEN]; // MAX_LEN is 16: size of the array

const char ssid[] = "DHRISHITA1";
const char pass[] = "dhrishita@$051805";

String uidPath = "/";

FirebaseData firebaseData;
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;  // Using this for authentication

void connect() 
{
  Serial.print("Checking wifi...");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\n Aioo Connected");
}

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  SPI.begin();
  rfid.init();

  connect();

  // Setting up Firebase configuration
  firebaseConfig.host = FIREBASE_HOST;

  // Setting up Firebase authentication
  firebaseAuth.token.uid = "";  // You can leave this empty if you're using the default Firebase token

  // Initialize Firebase
  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Firebase.reconnectWiFi(true);
}

void pushUser(String temp) 
{
  Serial.println("PUSHING USER ID: " + temp);
  Firebase.setInt(firebaseData, uidPath + "users/" + temp, 0);
}

void loop() 
{
  if (rfid.findCard(PICC_REQIDL, str) == MI_OK)    // Wait for a tag to be placed near the reader
  {
    Serial.println("Card found");
    String temp = "";                               // Temporary variable to store the read RFID card number
    if (rfid.anticoll(str) == MI_OK)                // Anti collision detection, read card's serial number
    {                         
      Serial.print("The Card's ID number is : ");
      for (int i = 0; i < 4; i++)                  // Record and display the card's serial number
      {
        temp = temp + (0x0F & (str[i] >> 4));
        temp = temp + (0x0F & str[i]);
      }
      Serial.println(temp);
      pushUser(temp);     // Check if the identified card is allowed
    }
    rfid.selectTag(str);  // Lock card to prevent redundant reads
  }
  rfid.halt();
}