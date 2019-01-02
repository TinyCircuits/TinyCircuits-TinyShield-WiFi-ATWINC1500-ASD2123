
/*************************************************************************
 * TinyDuino WiFi Tutorial:
 * Just a basic tutorial showing you how to connect to WiFi with the Wifi
 * TinyShield
 * 
 * Hardware by: TinyCircuits
 * Written by: Laverena Wienclaw
 * 
 * NOTE: There are a couple things you'll need to change for this to work!
 *
 * Initiated: Mon. 5/29/2018 
 * Updated: Tue. 06/15/2018
 ************************************************************************/

// This library is for the wifi connection
#include <WiFi101.h>

char ssid[] = "TinyCircuits";  //  your network SSID (name)
char wifiPassword[] = "********";  // your network password

void setup() {
  Serial.begin(9600);
  WiFi.setPins(8, 2, A3, -1); // VERY IMPORTANT FOR TINYDUINO
  while(!Serial);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  // Connect to WiFi, and loop until connection is secured
  WiFi.begin(ssid, wifiPassword);
  while (WiFi.status() != WL_CONNECTED)
    Serial.print(".");
    delay(500);

  // Print out the local IP address
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}

void loop()
{
  Serial.print("Main loop entered. Now that we're connected, let's do something cool.");
  delay(60000); // Wait a minute before going back through main loop
}
