void Relays(int shade, boolean relayPwr, boolean relayDir, int time) {

    static boolean relayPwrActiveState[4] = { HIGH, HIGH, HIGH, HIGH }; //OFF
    static boolean relayDirActiveState[4] = { HIGH, HIGH, HIGH, HIGH }; //DOWN
//	digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
//	Serial.println("StateHigh: ");
//	Serial.println(digitalRead(RELAY1));
//	delay(2000);                                      // Wait 2 seconds
//	digitalWrite(RELAY1,HIGH);          // Turns Relay Off
//	Serial.println("StateLow: ");
//	Serial.println(digitalRead(RELAY1));
//	delay(2000);

    int all = 10;

    if(DEBUG && LEVEL.Relays) { 
        Serial.print("Relays::");
        Serial.print("shade=");
        Serial.print(shade);
        Serial.print("\t");
        Serial.print("relayPwrPin[");
        Serial.print(shade);
        Serial.print("]=");
        Serial.print(relayPwr);
        Serial.print("\t");
        Serial.print("relayDirPin[");
        Serial.print(shade);
        Serial.print("]=");
        Serial.print(relayDir);
        Serial.print("\t");
        Serial.print("relayPwrActiveState[");
        Serial.print(shade);
        Serial.print("]=");
        Serial.print(relayPwrActiveState[shade]);
        Serial.print("\t");
        Serial.print("relayDirActiveState[");
        Serial.print(shade);
        Serial.print("]=");
        Serial.println(relayDirActiveState[shade]);
    }

    


    if(shade <= 3) {

        if(relayPwrPin[shade] != relayPwrActiveState[shade]) {
            digitalWrite(relayPwrPin[shade], relayPwr); //Set power (0, LOW = ON, 1 = OFF)
            relayPwrActiveState[shade] = relayPwrPin[shade];
        }
        if(relayDirPin[shade] != relayDirActiveState[shade]) {
            digitalWrite(relayDirPin[shade], relayDir); //Set Direction (0 = UP, 1 = DOWN) 
            relayDirActiveState[shade] = relayDirPin[shade];
        }
    }
    /*if(shade == 0) {
        digitalWrite(relayPwrPin[0], relayPwr); //Set power (0, LOW = ON, 1 = OFF)
        //delay(100); //Needed 
        digitalWrite(relayDirPin[0], relayDir); //Set Direction (0 = UP, 1 = DOWN)       
    }

    else if(shade == 1) {
        digitalWrite(relayPwrPin[1], relayPwr); //Set power (0, LOW = ON, 1 = OFF)
        //delay(100); //Needed 
        digitalWrite(relayDirPin[1], relayDir); //Set Direction (0 = UP, 1 = DOWN)
    }

    else if(shade == 2) {

        digitalWrite(relayPwrPin[2], relayPwr); //Set power (0, LOW = ON, 1 = OFF)
        //delay(100); //Needed 
        digitalWrite(relayDirPin[2], relayDir); //Set Direction (0 = UP, 1 = DOWN)        
    }
    
    else if(shade == 3) {

        digitalWrite(relayPwrPin[3], relayPwr); //Set power (0, LOW = ON, 1 = OFF)
        //delay(100); //Needed 
        digitalWrite(relayDirPin[3], relayDir); //Set Direction (0, LOW = UP, 1 = DOWN)
    }*/

    else if(shade == all) {

        for(int i = 0; i <= 3; i++) {

            if(relayPwrPin[i] != relayPwrActiveState[i]) {
                digitalWrite(relayPwrPin[i], relayPwr); //Set power (0, LOW = ON, 1 = OFF)
                relayPwrActiveState[i] = relayPwrPin[i];
            }

            if(relayDirPin[i] != relayDirActiveState[i]) {
                digitalWrite(relayDirPin[i], relayDir); //Set Direction (0, LOW = UP, 1 = DOWN)
                relayDirActiveState[i] = relayDirPin[i];
            }

        }
    }

    if(relayPwr == LOW) relaysActive = true;  //Pwr = ON, the relays are active
    else relaysActive = false;

    delay(time); //wait till motor is finished

}
