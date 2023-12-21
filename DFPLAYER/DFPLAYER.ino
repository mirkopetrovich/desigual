//#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 0; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 1; // Connects to module's TX 
//SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {

  // Init USB serial port for debugging
  Serial.begin(15200);
  // Init serial port for DFPlayer Mini
  //softwareSerial.begin(115200);


    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(1);
   

}

void loop() {
}
