void Relays(int shade, boolean relayPwr, boolean relayDir, int time) {

    static boolean relayPwrActiveState[4] = { HIGH, HIGH, HIGH, HIGH };   // on first init, set pwr relay comparer to off/HIGH
    static boolean relayDirActiveState[4] = { HIGH, HIGH, HIGH, HIGH };   // on first init, set dir relay comparer to down/HIGH
    int all = 10;    // a randomly chosen number when shade = ALL

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

    if(shade <= 3) {    // if shade equals 0, 1, 2, 3 then...

        if(relayPwrPin[shade] != relayPwrActiveState[shade]) {    // if relay isn't LOW/ON already, then change state
            digitalWrite(relayPwrPin[shade], relayPwr);    // set power (0, LOW = ON, 1 = OFF)
            relayPwrActiveState[shade] = relayPwrPin[shade];    // update comparer
        }
        if(relayDirPin[shade] != relayDirActiveState[shade]) {    // if relay isn't LOW/UP already, then change state
            digitalWrite(relayDirPin[shade], relayDir);    // set Direction (0 = UP, 1 = DOWN) 
            relayDirActiveState[shade] = relayDirPin[shade];    // update comparer
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

    else if(shade == all) {    // if all shades, then...

        for(int i = 0; i <= 3; i++) {    // check comparer for all shades/relays

            if(relayPwrPin[i] != relayPwrActiveState[i]) {    // if relay isn't LOW/ON already, then change state
                digitalWrite(relayPwrPin[i], relayPwr);    // set power (0, LOW = ON, 1 = OFF)
                relayPwrActiveState[i] = relayPwrPin[i];    // update comparer
            }

            if(relayDirPin[i] != relayDirActiveState[i]) {    // if relay isn't LOW/UP already, then change state
                digitalWrite(relayDirPin[i], relayDir);    // set Direction (0, LOW = UP, 1 = DOWN)
                relayDirActiveState[i] = relayDirPin[i];    // update comparer
            }

        }
    }

    if(relayPwr == LOW) relaysActive = true;    // pwr = ON, the relays are active
    else relaysActive = false;    // pwr relays are off

    delay(time);    // wait till motor is finished

}
