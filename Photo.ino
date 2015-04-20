int Photo() {
	
	int lightLevel;

	lightLevel = digitalRead(lightLevelPin); //digital read!


	if(lightLevel == HIGH) { //If high light 
		if(DEBUG && LEVEL.Photo) Serial.println("Photo::lightLevel=HIGH");
		lcd.backlight();
		//lcd.setBacklight(50);
		//LED(RGB[BLUE]);
	}
	else if(lightLevel == LOW) { //If low light 
		if(DEBUG && LEVEL.Photo) Serial.println("Photo::lightLevel=LOW");
		lcd.noBacklight();
		//LED(RGB[NONE]);
	}

	return lightLevel;

}