void LED(int LEDPin, int light) {

	for(int i = 1; i <= 3; i++) digitalWrite(LEDPin, LOW); //everything is OFF by default

	if(light != LOW) {

		digitalWrite(LEDPin, HIGH);

	}
	

}