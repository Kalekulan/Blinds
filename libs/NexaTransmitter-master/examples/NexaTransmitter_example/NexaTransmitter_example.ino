#include <NexaTransmitter.h>

NexaTransmitter remote(12,  14424562); // Create the nexa remote on pin2 with remote id

void setup() {
 Serial.begin(9600);
 Serial.println("start");
 
}

void loop() {
   remote.setSwitch(true, 0, 0); // switch on the unit 2 to dim level 10 (out of 15)
 delay(3000);                   // wait 3 sec
 remote.setSwitch(false, 0);    // switch off the unit 2
 
 Serial.println("stop");        // done. 

 delay(2000);
}


