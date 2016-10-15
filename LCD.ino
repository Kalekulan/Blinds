void LCD(String topRow, String botRow, int posTop, int posBot) {

	static String oldTopRow = "";	// comparer to avoid writing same string all over again
	static String oldBotRow = "";	// comparer to avoid writing same string all over again

	if(DEBUG && DOMAIN.LCD) {
		Serial.print("LCD::oldTopRow='"); 
		Serial.print(oldTopRow);
		Serial.println("'");
		Serial.print("LCD::oldBotRow='"); 
		Serial.print(oldBotRow);
		Serial.println("'");

		Serial.print("LCD::topRow='"); 
		Serial.print(topRow);
		Serial.println("'");
		
		Serial.print("LCD::botRow='"); 
		Serial.print(botRow);
		Serial.println("'");
	}

	/*if(oldTopRow != topRow) {
		//lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("                ");
		//delay(1000);
		lcd.setCursor(posTop, 0); //Start at character 0 on line 0
		lcd.print(topRow);

		/*if(DEBUG && LEVEL.LCD) {
			Serial.print("LCD::topRow='"); 
			Serial.print(topRow);
			Serial.println("'");

		}*/

	/*	oldTopRow = topRow;
	}*/

	if(oldTopRow != topRow || oldBotRow != botRow) {	// if strings are new, then write them to LCD

		lcd.clear();	// first clear LCD
		lcd.setCursor(posTop, 0);	// start at character x on line 0
		lcd.print(topRow);    // print top row
		lcd.setCursor(posBot, 1);	// set cursor to correct position
		lcd.print(botRow);    // print bot row

		oldTopRow = topRow;	  // update comparer
		oldBotRow = botRow;	  // update comparer

	}	

	else ;    // do nothing
	
	/*if(oldBotRow != botRow) {
		lcd.setCursor(0, 1);
		lcd.print("                ");
		//delay(1000);
		lcd.setCursor(posBot, 1);
		lcd.print(botRow);

		/*if(DEBUG && LEVEL.LCD) {
			Serial.print("LCD::botRow='"); 
			Serial.print(botRow);
			Serial.println("'");

		}	*/

	/*	oldBotRow = botRow;
	}	*/

}

