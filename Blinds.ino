#include <VirtualWire.h>
#include <Wire.h> 
//#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>
#include <EEPROM.h>
#include <Time.h>

#include <stdlib.h>


#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();




/*
    struct Shade {
    uint32_t const neutral;
    uint32_t const up;
    uint32_t const down;
    uint32_t const upHalf;
    uint32_t const downHalf;  
 };
*/

struct debugLevel {

    const boolean Blinds = false;
    const boolean Branch = true;
    const boolean Decrypt = false;
    const boolean EEPROMRead = false;
    const boolean EEPROMWrite = false;
    const boolean LCD = false;
    const boolean Photo = false;
    const boolean Relays = true;
    const boolean RxMsg = true;
    const boolean Thermister = false;
    const boolean Time = false;
 
};
 
debugLevel LEVEL;

const boolean DEBUG = true;

/*

struct ledColors {

    const int red = 8;
    const int green = 9;
    const int blue = 10;
    const int off = 0; 

};

#define RED 13
#define GREEN 12
#define BLUE 155
#define NONE 0 
const int RGB[4] = {NONE, RED, GREEN, BLUE};


ledColors LEDPin;

*/

/*
const uint32_t neutral_Shade[5] = {0xAA80C080, 0xAA80E080, 0xAA80F080, 0xAA80F880, 0xAA80FC80};
const uint32_t up_Shade[5] = {0xAA80C0FF, 0xAA80E0FF, 0xAA80F0FF, 0xAA80F8FF, 0xAA80FCFF};
const uint32_t down_Shade[5] = {0xAA80C088, 0xAA80E088, 0xAA80F088, 0xAA80F888, 0xAA80FC88};
const uint32_t upHalf_Shade[5] = {0xAA80C0F0, 0xAA80E0F0, 0xAA80F0F0, 0xAA80F8F0, 0xAA80FCF0};
const uint32_t downHalf_Shade[5] = {0xAA80C08F, 0xAA80E08F, 0xAA80F08F, 0xAA80F88F, 0xAA80FC8F}; 
*/
/*
Array[0] = Shade 0
Array[1] = Shade 1
Array[2] = Shade 2
Array[3] = Shade 3
Array[4] = All Shades 
*/

// const uint32_t shade0[3/*5*/] = {0xAA80C080, 0xAA80C0FF, 0xAA80C088}; //, 0xAA80C0F0, 0xAA80C08F};  //Set database shade 0 - order: neutral, up, down
// const uint32_t shade1[3/*5*/] = {0xAA80E080, 0xAA80E0FF, 0xAA80E088}; //, 0xAA80E0F0, 0xAA80E08F};  //Set database shade 1 - order: neutral, up, down
// const uint32_t shade2[3/*5*/] = {0xAA80F080, 0xAA80F0FF, 0xAA80F088}; //, 0xAA80F0F0, 0xAA80F08F};  //Set database shade 2 - order: neutral, up, down
// const uint32_t shade3[3/*5*/] = {0xAA80F880, 0xAA80F8FF, 0xAA80F888}; //, 0xAA80F8F0, 0xAA80F88F};  //Set database shade 3 - order: neutral, up, down
// const uint32_t shadeAll[3/*5*/] = {0xAA80FC80, 0xAA80FCFF, 0xAA80FC88}; //, 0xAA80FCF0, 0xAA80FC8F};  //Set database all shade - order: neutral, up, down

/*
Array[0] = Neutral
Array[1] = Up
Array[2] = Down
Array[3] = UpHalf
Array[4] = DownHalf 
*/


/*const uint32_t shade0_neutral = 0xAA80C080, shade0_up = 0xAA80C0FF, shade0_down = 0xAA80C088; //, shade0_upHalf = 0xAA80C0F0, shade0_downHalf = 0xAA80C08F; //Set database shade 0
const uint32_t shade1_neutral = 0xAA80E080, shade1_up = 0xAA80E0FF, shade1_down = 0xAA80E088; //, shade1_upHalf = 0xAA80E0F0, shade1_downHalf = 0xAA80E08F; //Set database shade 1
const uint32_t shade2_neutral = 0xAA80F080, shade2_up = 0xAA80F0FF, shade2_down = 0xAA80F088; //, shade2_upHalf = 0xAA80F0F0, shade2_downHalf = 0xAA80F08F; //Set database shade 2
const uint32_t shade3_neutral = 0xAA80F880, shade3_up = 0xAA80F8FF, shade3_down = 0xAA80F888; //, shade3_upHalf = 0xAA80F8F0, shade3_downHalf = 0xAA80F88F; //Set database shade 3
const uint32_t shadeAll_neutral = 0xAA80FC80, shadeAll_up = 0xAA80FCFF, shadeAll_down = 0xAA80FC88; //, shadeAll_upHalf = 0xAA80FCF0, shadeAll_downHalf = 0xAA80FC8F; //Set database all shade*/

const uint16_t /*shade0_neutral = 0x9501,*/ shade0_up = 0x9503, shade0_down = 0x9507; //, shade0_upHalf = 0xAA80C0F0, shade0_downHalf = 0xAA80C08F; //Set database shade 0
const uint16_t /*shade1_neutral = 0x9511,*/ shade1_up = 0x9513, shade1_down = 0x9517; //, shade1_upHalf = 0xAA80E0F0, shade1_downHalf = 0xAA80E08F; //Set database shade 1
const uint16_t /*shade2_neutral = 0x9531,*/ shade2_up = 0x9533, shade2_down = 0x9537; //, shade2_upHalf = 0xAA80F0F0, shade2_downHalf = 0xAA80F08F; //Set database shade 2
const uint16_t /*shade3_neutral = 0x9571,*/ shade3_up = 0x9573, shade3_down = 0x9577; //, shade3_upHalf = 0xAA80F8F0, shade3_downHalf = 0xAA80F88F; //Set database shade 3
const uint16_t shadeAll_neutral = 0x95F1, shadeAll_up = 0x95F3, shadeAll_down = 0x95F7; //, shadeAll_upHalf = 0xAA80FCF0, shadeAll_downHalf = 0xAA80FC8F; //Set database all shade

/*const uint32_t shade0_neutral = 0xAB80C080, shade0_up = 0xF0F0F0FF, shade0_down = 0xF0F0F0EF; //, shade0_upHalf = 0xAA80C0F0, shade0_downHalf = 0xAA80C08F; //Set database shade 0
const uint32_t shade1_neutral = 0xAA80C080, shade1_up = 0x21E1E1E7D, shade1_down = 0x21E1E1E5D; //, shade1_upHalf = 0xAA80E0F0, shade1_downHalf = 0xAA80E08F; //Set database shade 1
const uint32_t shade2_neutral = 0xAC80C080, shade2_up = 0x21E1E1E7B, shade2_down = 0x21E1E1E5B; //, shade2_upHalf = 0xAA80F0F0, shade2_downHalf = 0xAA80F08F; //Set database shade 2
const uint32_t shade3_neutral = 0xAD80C080, shade3_up = 0x21E1E1E79, shade3_down = 0x21E1E1E59; //, shade3_upHalf = 0xAA80F8F0, shade3_downHalf = 0xAA80F88F; //Set database shade 3
const uint32_t shadeAll_neutral = 0xAF80C080, shadeAll_up = 0xAAB, shadeAll_down = 0xAA; //, shadeAll_upHalf = 0xAA80FCF0, shadeAll_downHalf = 0xAA80FC8F; //Set database all shade
*/

//const uint32_t empty = 0x4E2EAF77;

//const uint32_t key[] = {0x4D312855, 0x7A672638, 0x38415D7E, 0x632E6468}; //my own 128bit key, byte 0 to byte 3 left to right

/*
#define ON LOW
#define OFF HIGH
#define UP LOW
#define DOWN HIGH
*/

int rxTimeout = 20;

//uint16_t received;

boolean timerReset = false;

//uint32_t received[2];
//uint32_t received;
/*
Shade shade0 = {0xAA80C080, 0xAA80C0FF, 0xAA80C088, 0xAA80C0F0, 0xAA80C08F};  //Set database shade 0
Shade shade1 = {0xAA80E080, 0xAA80E0FF, 0xAA80E088, 0xAA80E0F0, 0xAA80E08F};  //Set database shade 1
Shade shade2 = {0xAA80F080, 0xAA80F0FF, 0xAA80F088, 0xAA80F0F0, 0xAA80F08F};  //Set database shade 2
Shade shade3 = {0xAA80F880, 0xAA80F8FF, 0xAA80F888, 0xAA80F8F0, 0xAA80F88F};  //Set database shade 3
Shade shadeAll {0xAA80FC80, 0xAA80FCFF, 0xAA80FC88, 0xAA80FCF0, 0xAA80FC8F};  //Set database all shade
*/

const int rxPin = 2;
//const int rxLED = 13;

const int relayPwrPin[4] = {4, 6, 8, 10};
const int relayDirPin[4] = {5, 7, 9, 11};
boolean relaysActive = false;

const int lightLevelPin = 3;

const int tempPin = A0;

//int tempDelay = 0;
//boolean tempVisible = false; //visible after startup
//double oldTemp;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity
String oldTopRow;
String oldBotRow;

const int lastDay = 255;



//byte lastDirection[4];

void setup() {
    mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2

    //int i;
    //delay(500);
    
    lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
    lcd.home();
        // ------- Quick 3 blinks of backlight  -------------
    /*for(i = 0; i< 3; i++) {
        lcd.backlight();
        delay(250);
        lcd.noBacklight();
        delay(250);
    }*/
    lcd.backlight(); // finish with backlight on  

    Serial.begin(9600);	// Debugging only
    while (!Serial) {
        ; // wait for serial port to connect.
    }
    Serial.println("Home Automation 1.0");
    Serial.println("ECU0: Blinds");
    Serial.println("By: Lukas Foughman");
    Serial.println("2015-01-02");
    Serial.println("Written for Arduino UNO R3");
    Serial.println();
    Serial.println();

    LCD("Home", " Automation 1.0", 6, 0);
    delay(2000);
    /*LCD("ECU0: Blinds");
    delay(2000);
    LCD("Written by:", " Lukas Foughman", 2, 0);
    delay(2000);*/
    lcd.clear();

    //digitalWrite(12, HIGH);

    //pinMode(rxPin, INPUT); // Input of 433 MHz receiver


    for(int i = 0; i< 3; i++) {   
        pinMode(relayPwrPin[i], OUTPUT);
        pinMode(relayDirPin[i], OUTPUT);
        digitalWrite(relayPwrPin[i], HIGH); //set power OFF
        digitalWrite(relayDirPin[i], HIGH); //set direction LEFT (open)
    }
    pinMode(lightLevelPin, INPUT);

    pinMode(tempPin, INPUT);

    //for(i = 0; i <4; i++) lastDirection[i] = EEPROMRead(i); //Read all shades last message received

    //EEPROMWrite(lastDay, day());
    //Serial.print("day");
    //Serial.println(day());
}

void loop() {    


    
    uint16_t msg;
    //String tempString;
    double temp;
    int light;


    
    //vw_rx_start();

    //delay(100);

    light = Photo(); //Check lighting in environment
    temp = Thermister(); 


    msg = RxMsg(light); //needed!!!!!!!!!

    //Serial.println(msgx);  good to have

    //delay(100);

   /* if(shadeTimeout.TimeCheck(0, 0, 0) == true) {
        shadeTimeout.StopTimer();
        Serial.print("Blinds::shadeTimeout.TimeCheck(0, 0, 0)=");
        Serial.println(shadeTimeout.TimeCheck(0, 0, 0));
        Serial.println("Blinds::shadeTimeout.StopTimer()");
        received = shadeAll_neutral;
    }*/



    Branch(msg, temp);

    //Time();

    //Serial.println(second());




/*
    if(encryptMsgRx[0] == 0xC11360A1 || encryptMsgRx[0] == 0x8FABFA55) {
        Serial.print("encryptMsgRx[0] = ");
        Serial.println(encryptMsgRx[0], HEX);
        Serial.print("encryptMsgRx[0] = ");
        Serial.println(encryptMsgRx[0], HEX);
    }
    else if(encryptMsgRx[1] == 0xC11360A1 || encryptMsgRx[1] == 0x8FABFA55) {
        Serial.print("encryptMsgRx[1] = ");
        Serial.println(encryptMsgRx[1], HEX);
        Serial.print("encryptMsgRx[1] = ");
        Serial.println(encryptMsgRx[1], HEX);
    }
    delay(1000);
    if(encryptMsgRx[1] == 0xC11360A1) {
        decryptMsg = Decrypt(encryptMsgRx, key);
        Serial.print("Decrypted msg = ");
        Serial.println(decryptMsg[0], HEX);
    }
    else {
        Serial.print("encryptMsgRx[0] = ");
        Serial.println(encryptMsgRx[0], HEX);       
    }
    Serial.print("encryptMsgRx[0] = ");
    Serial.println(encryptMsgRx[0], HEX);
    Serial.print("encryptMsgRx[1] = ");
    Serial.println(encryptMsgRx[1], HEX);

    if(encryptMsgRx[0] == 0xC11360A1) {
        Serial.print("encryptMsgRx = ");
        Serial.println(encryptMsgRx[0], HEX);
        //encryptMsgRx[1] = 0x8FABFA55;

        decryptMsg = Decrypt(encryptMsgRx, key);
        Serial.print("Decrypted msg = ");
        Serial.println(decryptMsg[0], HEX);
    }

    
    delay(500);
    if(RxMsg() > 0) decryptMsg = Decrypt(encryptMsgRx, key);  
    else;

    delay(2000);
    Encrypt(msg, key);
*/    
}
