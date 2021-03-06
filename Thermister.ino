double Thermister() {
	//String tempString = "";
    //char tempChar[5];   // temporarily holds data from vals 
    //String stringVal = "";     //data on buff is copied to this string
	double temp = analogRead(tempPin);    // read data from tempPin
	temp = log(((10240000/temp) - 10000));    // do some calculations...
	temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );    // some more...
	temp = temp - 273.15;    // convert Kelvin to Celcius
    //if(temp < 1) temp = oldTemp; 
	//tempString = "" + temp + " Celcius";
    //tempString = "";
    //tempString = tempString + "    ";
    //tempString = tempString + temp;
    //tempString = tempString + " C";
    temp = temp*2;    // temp * 2
    temp = round(temp);    // round off
    temp = temp/2;    // split it by 2 to get one decimal only and wholes and halfes. E.g. 20.5, 23
    //static double averageTemp = temp;
    //dtostrf(temp, 2, 1, tempChar);  //3 is mininum width, 2 is precision; float value is copied onto buff
    //display character array
    //Serial.print("charVal: ");
    //for(int i=0;i<sizeof(charVal);i++)
    //{
    //Serial.print(charVal[i]);
    //}
    //Serial.println();
    //convert chararray to string
    //for(int i=0; i<sizeof(tempChar)-1; i++) tempString+=tempChar[i];  //-1 to remove trash
    //tempString = tempString + "C";    
    if(DEBUG && LEVEL.Thermister) {
        Serial.print("Thermister::temp=");
        Serial.print(temp);
        Serial.println("C");
        //Serial.print("Thermister::tempString: ");
        //Serial.println(tempString); //display string
    }
    //oldTemp = temp;
	//return tempString;
    //return temp;
    /*if((temp != averageTemp) && (tempCounter < 3)) {
        tempCounter++;
        return averageTemp;
    }    
    else if(tempCounter == 3) {
        tempCounter = 0;
        averageTemp = temp;
        return tempString;
    }*/
    //return tempString;
    return temp;
}