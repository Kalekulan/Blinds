void Time () {
	byte timeAlive[32];
	int i = 0;
	int add = 1;
	uint32_t timeAliveTotal = 0;
	int lastDayed = 1;


	//if(EEPROMRead(lastDay) != day()) {	//if today is not the same day as the latest one
	if(lastDayed != day()) {	//if today is not the same day as the latest one	
		
		while(i < 32) {	//look in the first 32 addresses of the EEPROM

			timeAlive[i] = EEPROMRead(i);	//read the adress

			if(timeAlive[i] > 0) i++;		//if the address is larger than 0, then check continue reading loop
			else {
				for(int x = 0; x < i; x++) timeAliveTotal =+ timeAlive[i-1];	//if the address is empty, then add all the read values to the total variable
				if(timeAlive[i-1] < 255) EEPROMWrite(i-1, timeAlive[i-1] + add);	//now update the register, if the latest register was smaller than 255.
				else EEPROMWrite(i, add);	//if it was 255, then continue on the next address.
				i = 40; //end loop
			}

		}
		EEPROMWrite(lastDay, day());
	}

	Serial.print("Time::lastDay=");
	Serial.println(lastDay);
	Serial.print("Time::day=");
	Serial.println(day());
	Serial.print("Time::sizeof(timeAlive)=");
	Serial.println(sizeof(timeAlive));
	Serial.print("Time::timeAliveTotal=");
	Serial.println(timeAliveTotal);

	//delay(5000);
	
}