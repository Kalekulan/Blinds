void LCD(String topRow, String botRow, int posTop, int posBot) {

	static String oldTopRow = "";
	static String oldBotRow = "";

	if(DEBUG && LEVEL.LCD) {
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

	if(oldTopRow != topRow || oldBotRow != botRow) {

		lcd.clear();
		lcd.setCursor(posTop, 0); //Start at character 0 on line 0
		lcd.print(topRow);
		lcd.setCursor(posBot, 1);
		lcd.print(botRow);

		oldTopRow = topRow;
		oldBotRow = botRow;

	}	

	else ;
	
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

