/*
    WiFi Connect - connecting ESP8266 to WiFi, with settings in seperate configuration file. 
*/
#include <ESP8266WiFi.h>    // Include the Wi-Fi library
#include "config.h"

void setup() {
    // Start the Serial communication to send messages to the computer
    Serial.begin(115200);
    delay(10);
    Serial.println("");

    // Create and assign a hostname to the device
    // Hostname is generated as a prefix combined with the chid id code as a hexidecimal string
    WiFi.hostname("ESP8266-" + String(ESP.getChipId(), HEX));

    // Connect to the WiFi network
    WiFi.begin(ssid, password);
    Serial.print("Connecting to ");
    Serial.print(ssid); Serial.println(" ...");

    while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
        delay(1000);
        Serial.print('.');
    }

    Serial.println("");
    Serial.println("Connection established!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop() {
    // empty
}
