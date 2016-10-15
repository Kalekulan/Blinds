/*
Description
Reads a byte from the EEPROM. Locations that have never been written to have the value of 255.

Syntax
EEPROM.read(address)

Parameters
address: the location to read from, starting from 0 (int)

Returns
the value stored in that location (byte)
*/

/* 2015-05-11 - NOT USED!!

byte EEPROMRead(int adress) {

	byte value = EEPROM.read(adress);

	if(DEBUG && LEVEL.EEPROMRead) {
		Serial.print("EEPROMRead::");
		Serial.print("adress=");
	    Serial.print(adress);
	    Serial.print("\t");
	    Serial.println("value=");
	    Serial.print(value, HEX);
	    Serial.println();
	}

}*/


/*
	byte lastShade[4];
	int i;

	

    for(i = 0; i < 4; i ++) {

	    lastShade[i] = EEPROM.read(i);

	    Serial.print(i);
	    Serial.print("\t");
	    Serial.print(lastShade[i], HEX);
	    Serial.println();
	}

    delay(500);

    return(value);
    */

