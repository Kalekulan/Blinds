/*
Description
Write a byte to the EEPROM.

Syntax
EEPROM.write(address, value)

Parameters
address: the location to write to, starting from 0 (int)
value: the value to write, from 0 to 255 (byte)

Returns
none

Note
An EEPROM write takes 3.3 ms to complete. The EEPROM memory has a specified life of 100,000 write/erase cycles, so you may need to be careful about how often you write to it.
*/


void EEPROMWrite (int adress, byte value) {

	//byte value[4];
	//int i;

	//byte adress = (message >> 16) & 0xFF; 
	//byte value = (message >> 24) & 0xFF;;


	EEPROM.write(adress, value);

	//for(i = 0; i < 4; i ++) {
	/*	value[0] = (shade0 >> 24) & 0xFF;
		value[1] = (shade1 >> 24) & 0xFF;
		value[2] = (shade2 >> 24) & 0xFF;
		value[3] = (shade3 >> 24) & 0xFF;
	*/
	//}

	/*
	for(i = 0; i < 4; i ++) {
		EEPROM.write(i, value[i]);
  		delay(15);
	}
	*/
	
}
