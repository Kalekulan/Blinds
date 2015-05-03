 uint16_t RxMsg(int light) { 

    
    int unknown = 5;
    //uint16_t received = unknown;

    uint16_t received;

    if (mySwitch.available()) {
        //LED(12, light); //GREEN

        //int value = mySwitch.getReceivedValue();
        received = mySwitch.getReceivedValue();

        //if (value == 0) {
        if (received == 0) {
          Serial.print("RxMsg::Unknown encoding");
          //received = 0;
        } else {
            if(DEBUG && LEVEL.RxMsg) {  
              Serial.print("RxMsg::received ");
              Serial.print( mySwitch.getReceivedValue(), HEX);
              Serial.print(" / ");
              Serial.print( mySwitch.getReceivedBitlength() );
              Serial.print("bit ");
              Serial.print("Protocol: ");
              Serial.println( mySwitch.getReceivedProtocol() );
            }
            //received = mySwitch.getReceivedValue();
        }

        mySwitch.resetAvailable();
    }
    else {
        //rxTimeout--;
        //if(rxTimeout == 0) received = shadeAll_neutral;
        //Serial.print("RxMsg::rxTimeout=");
        //Serial.println(rxTimeout);

        //received = 0;
        //if(received > 0) 

        if(rxTimeout <= 0) {

            received = shadeAll_neutral;
            timerReset = true;
            //LED(13, light); //BLUE
        }
        else {
            received = 0;
            //LED(13, light); //BLUE
        }
    }

    if(DEBUG && LEVEL.RxMsg) {
        Serial.print("received = ");
        Serial.println(received);
    }
    return(received);


}

















































/*
* Nexa Receiver
* Controls 4 relays connected to Aurduino I/O pins.
* Transmitter codes are hard-coded as a fixed number in the Sketch.
*
* The code has been validated to work with the following NEXA transmitters:
*
* WBT 912 2ch sender
* WT2 PRO 2ch Wall sender
* LMDT 810 Wireless Outdoor motion sensor
* LMST 606 Wireless Magnetic contact
* PB3 kit sender
* Telstick Net
*
* Please note that timing varies some between different senders.
* The Debug Serial port can be used to identifiy Sender codes and also for debug timing issues.
*
* Receiver Hardware is a 1 USD 433MHz wireless reciever module bought on Ebay. Search for "433Mhz RF transmitter and receiver arduino" to find a suitable reciever. 
*
* Receiver functionality is based on original code from
* Barnaby Gray 12/2008
* Peter Mead 09/2008
* "Homeeasy protocol receiver for the new protocol."
*
* * The data is encoded on the wire (aerial) as a Manchester code.
*
* A latch of 275us high, 2675us low is sent before the data.
* There is a gap of 10ms between each message.
*
* 0 = holding the line high for 275us then low for 275us.
* 1 = holding the line high for 275us then low for 1225us.
*
* The timings seem to vary quite noticably between devices.
* If this script does not detect your signals try relaxing the timing
* conditions.
* *
* Each actual bit of data is encoded as two bits on the wire as:
* Data 0 = Wire 01
* Data 1 = Wire 10
*
* The actual message is 32 bits of data (64 wire bits):
* bits 0-25: the group code - a 26bit number assigned to controllers.
* bit 26: group flag
* bit 27: on/off flag
* bits 28-31: the device code - a 4bit number.
*
* The group flag just seems to be a separate set of addresses you can program devices
* to and doesn't trigger the dim cycle when sending two ONs.
*/



/*

uint32_t RxMsg() {



int t1 = 0; // Latch 1 time only needed for debugging purposes
int t2 = 0; //latch 2 time only needed for debugging purposes.

unsigned long Sendercode; // Here is the unique Transmitter code. Use the Serial monitor to identify your Transmitter code.

uint32_t received;


    int i = 0;
    unsigned long t = 0;
    
    byte prevBit = 0;
    byte bit = 0;
    
    unsigned long sender = 0;
    bool group = false;
    bool on = false;
    unsigned int recipient = 0;

    String string = "";
    
    
    
    // latch 1
    // Latch timing has been loosened to acommodate varieties in the Nexa transmitters.
    
    while ((t < 8000 || t > 13000)) {
        t = pulseIn(rxPin, LOW, 1000000);
        t1 = t; // Save latch timing for debugging purposes
    }
    
    // Next line can be used to debug latch timing. Please note that this affects timing and that recieving the following data bits may fail.
    //Serial.println (t);
    
    // latch 2
    // Latch timing has been loosened to acommodate varieties in the Nexa transmitters.
    while (t < 2200 || t > 2900) { 
        t = pulseIn(rxPin, LOW, 1000000);
    }
    t2 = t; // Save latch timing for debugging purposes
    // Next line can be used to debug latch timing. Please note that this affects timing and that recieving the following data bits may fail.
    //Serial.println (t);
    
    
    
    // data collection from reciever circuit
    while (i < 64){
      
        t = pulseIn(rxPin, LOW, 1000000);
    
        if (t > 200 && t < 400) {
            bit = 0;  
        }
        else if (t > 1100 && t < 1560) {
            bit = 1;
        }
        else {
            i = 0;
            break;
        }
        
        if (i % 2 == 1) {
            if ((prevBit ^ bit) == 0) { // must be either 01 or 10, cannot be 00 or 11
                i = 0;
                break;
            }
            
            if (i < 53) { // first 26 data bits
                sender <<= 1;
                sender |= prevBit;
                received <<= 1;
                received |= prevBit;
            }
            else if (i == 53) { // 26th data bit
                group = prevBit;
                received <<= 1;
                received |= prevBit;
            }
            else if (i == 55) { // 27th data bit
                on = prevBit;
                received <<= 1;
            }
            else { // last 4 data bits
                recipient <<= 1;
                recipient |= prevBit;
                received <<= 1;
                received |= prevBit;
            }
        }
        
        prevBit = bit;
        ++i;
    }
    
    // interpret message
    /*if (i > 0) {
        //Serial.println(string);
        printResult(sender, group, on, recipient); // Print the result on Serial Monitor. Use this to identify your transmitter code.
    
        //if (Sendercode = sender) // This is the check for the correct transimtter code. If code is incorrect then go back to look for new code.
        if (group){ // Group command affects all relays, Either all on, or all off.
            digitalWrite(txPin0, on); // Relay 1
            digitalWrite(txPin1, on); // Relay 2
            digitalWrite(txPin2, on); // Relay 3
            digitalWrite(txPin3, on); // Group Relay
        }
        
        else {
            switch (recipient) // Check which channel should be activated
            {
                case 0:
                    digitalWrite(txPin0, on); // Relay 1
                    break;
                case 1:
                    digitalWrite(txPin1, on); // Relay 2
                    break;
                case 2:
                    digitalWrite(txPin2, on); // Relay 3
                    break;
                
                break;
            }
        }
    }
    
}
    
    
    
void printResult(unsigned long sender, bool group, bool on, unsigned int recipient) {
    Serial.print("sender ");
    Serial.println(sender);
    
    if (group) {
        Serial.println("group command");
    }
    else {
        Serial.println("no group");
    }
    
    if (on) {
        Serial.println("on");
    }
    else {
        Serial.println("off");
    }
    
    Serial.print("recipient ");
    Serial.println(recipient);
    Serial.println(t1); // Timing for latch 1
    Serial.println(t2); // Timing for latch 2
    Serial.print("received ");
    Serial.println(received);
    Serial.print("received HEX 0x");
    Serial.println(received, HEX);
        Serial.print("received BIN ");
    Serial.println(received, BIN);
    
    Serial.println();


}*/

/*
    Serial.print("RxMsg::received=");
    Serial.println(received, HEX);
    return(received);
    
}
    
    
*/
