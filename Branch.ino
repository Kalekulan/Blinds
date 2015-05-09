void Branch(uint16_t msgBranch, double temp) {

    //String tempString;

    boolean ON = LOW; //LED LIT
    boolean OFF = HIGH;
    boolean UP = LOW; //LED LIT
    boolean DOWN = HIGH;

    const int AVG = 7;
    static double tempArray[AVG];
    static double tempAvg;
    static int tempCounter = 0;


    if(DEBUG && LEVEL.Branch) {
        Serial.print("rxTimeout = ");
        Serial.println(rxTimeout);
    }
    //if(received > 0 || timerReset == true) {
    if(msgBranch > 0 || timerReset == true) {
        rxTimeout = 20; //reset timer
        timerReset = false;
    }
    //else if(received == 0) rxTimeout--;
    else if(msgBranch == 0) rxTimeout--;
    /*if(msgBranch > 0) {
        shadeTimeout.StartTimer();
        //Serial.println("Branch::shadeTimeout.StartTimer()");
        Serial.println(shadeTimeout.ShowSeconds());
    }*/


    switch (msgBranch) {

    //**************************** SHADE 0 ********************************        
        /*case shade0_neutral:
            
            Serial.println("Branch::shade0_neutral");
            LCD("Shade0:", "Neutral", 0, 0);
            Relays(0, OFF, DOWN, 10); //both relays OFF, 0 sec
            //tempVisible = false;
            //tempDelay = 100;
            
            break;*/

        case shade0_up:

            Serial.println("Branch::shade0_up");
            LCD("Shade0:", "Up", 0, 0);
            Relays(0, ON, UP, 0); //PWR ON, UP (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;

            //EEPROMWrite(0, shade0_up);
                 
            break;
        
        case shade0_down:

            Serial.println("Branch::shade0_down");
            LCD("Shade0:", "Down", 0, 0);
            Relays(0, ON, DOWN, 0); //PWR ON, DOWN (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;
            //EEPROMWrite(0, shade0_down);

            break;
        
    //**************************** SHADE 1 ********************************
        /*case shade1_neutral:

            Serial.println("Branch::shade1_neutral");
            LCD("Shade1:", "Neutral", 0, 0);

            //tempVisible = false;
            //tempDelay = 100;

            break;*/

        case shade1_up:

            Serial.println("Branch::shade1_up");
            LCD("Shade1:", "Up", 0, 0);
            Relays(1, ON, UP, 0); //PWR ON, UP (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;

            break;
        
        case shade1_down: 

            Serial.println("Branch::shade1_down");
            LCD("Shade1:", "Down", 0, 0);
            Relays(1, ON, DOWN, 0); //PWR ON, DOWN (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;

            break;

    //**************************** SHADE 2 ********************************
        /*case shade2_neutral:
            
            Serial.println("Branch::shade2_neutral");
            LCD("Shade2:", "Neutral", 0, 0);
            //tempVisible = false;
            //tempDelay = 100;

            break;*/

        case shade2_up:

            Serial.println("Branch::shade2_up");
            LCD("Shade2:", "Up", 0, 0);
            Relays(2, ON, UP, 0); //PWR ON, UP (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;

            break;
        
        case shade2_down: 

            Serial.println("Branch::shade2_down");
            LCD("Shade2:", "Down", 0, 0);
            Relays(2, ON, DOWN, 0); //PWR ON, DOWN (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;

            break;
        
    //**************************** SHADE 3 ********************************
        /*case shade3_neutral:

            Serial.println("Branch::shade3_neutral");
            LCD("Shade3:", "Neutral", 0, 0);
            //tempVisible = false;
            //tempDelay = 100;

            break;*/

        case shade3_up:

            Serial.println("Branch::shade3_up");
            LCD("Shade3:", "Up", 0, 0);       
            Relays(3, ON, UP, 0); //PWR ON, UP (?), 3 sec
            //tempVisible = false;    
            //tempDelay = 100; 

            break;
        
        case shade3_down: 

            Serial.println("Branch::shade3_down");
            LCD("Shade3:", "Down", 0, 0);      
            Relays(3, ON, DOWN, 0); //PWR ON, DOWN (?), 3 sec
            //tempVisible = false;
            //tempDelay = 100;

            break;

    //**************************** SHADE ALL ********************************
        case shadeAll_neutral:

            Serial.println("Branch::shadeAll_neutral");
            //LCD("Action", "ShadeAll Neutral");   
            //LCD("", "");    
            Relays(10, OFF, DOWN, 0);
            rxTimeout = 20;
            //tempVisible = false;
            //tempDelay = 0;

            break;

        case shadeAll_up:

            Serial.println("Branch::shadeAll_up");
            LCD("ShadeAll:", "Up", 0, 0);      
            Relays(10, ON, UP, 0);
            //tempVisible = false;

            break;
        
        case shadeAll_down: 

            Serial.println("Branch::shadeAll_down");
            LCD("ShadeAll:", "Down", 0, 0);      
            Relays(10, ON, DOWN, 0);
            //tempVisible = false;

            break;
        
    //**************************** ELSE *************************************

    /*    case empty:

            if(DEBUG) Serial.println("empty message received");

            if(tempDelay == 100) { //check temperature every 100 time while in this state
                tempString = Thermister();
                tempDelay++; //increment everytime
                if(tempDelay == 101) tempDelay = 0; //reset if 101
            }

            if(tempVisible == false) LCD("Temperature", tempString); //if temp isn't visible, make it visible
            tempVisible = true; //temp is now visible

            break;
    */

        default:
            //Serial.print("Branch::tempDelay=");

            

            if(DEBUG && LEVEL.Branch) {
                Serial.println("Branch::default");
                //Serial.print("unknown message received");
                Serial.print("\t");
                Serial.println(msgBranch);
                //Serial.print("Branch::tempDelay=");
                //Serial.println(tempDelay);
                //Serial.print("Branch::tempVisible=");
                //Serial.println(tempVisible);
            }

            //Relays(0, OFF, DOWN, 0); //both relays OFF, 0 sec

            //if(tempDelay <= 0 || tempVisible == false) {
            //if(tempVisible == false) {
            if(relaysActive == false) {   
                //tempString = Thermister(); 
                //LCD("  Temperature", tempString); //if temp isn't visible, make it visible
                tempCounter++;
                tempArray[tempCounter] = temp;
                if(tempCounter == 4) {
                    for(int i = 0; i <= 4; i++) {
                        tempAvg = tempAvg + tempArray[i];
                        tempArray[i] = 0;
                    }

                    tempAvg = tempAvg/AVG;
                    char tempChar[5];
                    dtostrf(temp, 2, 1, tempChar);  //3 is mininum width, 2 is precision; float value is copied onto buff
                    String tempString = "";
                    //display character array
                    //Serial.print("charVal: ");
                    //for(int i=0;i<sizeof(charVal);i++)
                    //{
                    //Serial.print(charVal[i]);
                    //}
                    //Serial.println();
                    //convert chararray to string
                    for(int i = 0; i < sizeof(tempChar) - 1; i++) tempString+=tempChar[i];  //-1 to remove trash

                    tempString = tempString + "C";

                    LCD("Temperature", tempString, 3, 5); //if temp isn't visible, make it visible
                    tempCounter = 0;
                    
                }
                //LCD("Temperature", ""+tempa, 3, 5); //if temp isn't visible, make it visible
                //tempDelay = 100; //reset if <=0
                //tempVisible = true; //temp is now visible
                
                
            }
            
            /*else if(tempVisible == false) { //if other message has been shown other than temp, then update the temperature
                tempString = Thermister(); 
                LCD("  Temperature", tempString); //if temp isn't visible, make it visible
            }*/
            /*
            else if(tempDelay != 0 && tempVisible == false) {
                LCD("  Temperature", tempString); //if temp isn't visible, make it visible
            }*/

            
            //tempDelay--; //increment everytime 
             

            break;
    }


    //delay(1000);

}