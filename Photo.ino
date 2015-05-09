int Photo() {

	int lightLevel = digitalRead(lightLevelPin);	// read light level

	if(DEBUG && LEVEL.Photo) {
		Serial.print("Photo::lightLevel=");
		Serial.println(lightLevel);
	}

	if(lightLevel == HIGH) {	// if there's no or little light	
		lcd.backlight();	// turn on display backlight
		//lcd.setBacklight(50);
		//LED(RGB[BLUE]);
	}
	else if(lightLevel == LOW) {	// if there's light
		lcd.noBacklight();	// turn off display backlight
		//LED(RGB[NONE]);
	}

	return lightLevel;
}