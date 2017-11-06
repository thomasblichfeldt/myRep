/*
  This is a very basic example that sets up the Alphasense OPC-N2, turns it on,
  and reads the histogram at 0.2 Hz. For a more detailed explanation, check out
  the full documentation.
  Written by David H Hagan, June 2016
  Modified by Marcelo Yungaicela, May 2017
*/
#include "opcn2.h"       
//#include <LoRa.h>
#define CS 9
#include<SoftwareSerial.h>

OPCN2 alpha;
HistogramData hist;
SoftwareSerial logger(4,3);

int counter = 0;
int fileNumber;
char buff[50];

const int sampleRate = 5000;

const int loraCsPin = 10;          
const int resetPin = 8;
const int resetOpenLog = 5; 
const int intPin = 3; 
const int LEDPin = 7;


void setup(){
    
    Serial.begin(9600);

    logger.begin(9600);

    alpha.setup(CS);

    pinMode(LEDPin, OUTPUT);

    Serial.println("Testing OPC-N2 v" + String(alpha.firm_ver.major) + "." + String(alpha.firm_ver.minor));
    
    // Read and print the configuration variables
    /*LoRa.setPins(loraCsPin, resetPin, intPin);

    if (!LoRa.begin(868E6)) {             // initialize ratio at 915 MHz
    Serial.println("LoRa init failed. Check your connections.");
    }else{
    Serial.println("LoRa is ON!");  
    }
    */
    alpha.toggle_fan(true);
    delay(500);
    alpha.on();
    delay(500);
}

void loop(){

    hist = alpha.read_histogram();

    digitalWrite(LEDPin, HIGH);

    if (counter >= 3){

      // Print out the histogram data
      Serial.print("\nSampling Period:\t"); Serial.println(hist.period);
      Serial.println("");
      Serial.println("--PM values--");
      Serial.print("PM1: "); Serial.println(hist.pm1);
      Serial.print("PM2.5: "); Serial.println(hist.pm25);
      Serial.print("PM10: "); Serial.println(hist.pm10);
      Serial.println("");
      Serial.println("--bin values--");
      Serial.print("bin1: "); Serial.println(hist.bin0);
      Serial.print("bin2: "); Serial.println(hist.bin1);
      Serial.print("bin3: "); Serial.println(hist.bin2);
      Serial.print("bin4: "); Serial.println(hist.bin3);
      Serial.print("bin5: "); Serial.println(hist.bin4);
      Serial.print("bin6: "); Serial.println(hist.bin5);
      Serial.print("bin7: "); Serial.println(hist.bin6);
      Serial.print("bin8: "); Serial.println(hist.bin7);
      Serial.print("bin9: "); Serial.println(hist.bin8);
      Serial.print("bin10: "); Serial.println(hist.bin9);
      Serial.print("bin11: "); Serial.println(hist.bin10);
      Serial.print("bin12: "); Serial.println(hist.bin11);
      Serial.print("bin13: "); Serial.println(hist.bin12);
      Serial.print("bin14: "); Serial.println(hist.bin13);
      Serial.print("bin15: "); Serial.println(hist.bin14);
      Serial.print("bin16: "); Serial.println(hist.bin15);
      Serial.println("");

      logger.print("\nSampling Period:\t"); Serial.println(hist.period);
      logger.println("");
      logger.println("--PM values--");
      logger.print("PM1: "); Serial.println(hist.pm1);
      logger.print("PM2.5: "); Serial.println(hist.pm25);
      logger.print("PM10: "); Serial.println(hist.pm10);
      logger.println("");
      logger.println("--bin values--");
      logger.print("bin1: "); Serial.println(hist.bin0);
      logger.print("bin2: "); Serial.println(hist.bin1);
      logger.print("bin3: "); Serial.println(hist.bin2);
      logger.print("bin4: "); Serial.println(hist.bin3);
      logger.print("bin5: "); Serial.println(hist.bin4);
      logger.print("bin6: "); Serial.println(hist.bin5);
      logger.print("bin7: "); Serial.println(hist.bin6);
      logger.print("bin8: "); Serial.println(hist.bin7);
      logger.print("bin9: "); Serial.println(hist.bin8);
      logger.print("bin10: "); Serial.println(hist.bin9);
      logger.print("bin11: "); Serial.println(hist.bin10);
      logger.print("bin12: "); Serial.println(hist.bin11);
      logger.print("bin13: "); Serial.println(hist.bin12);
      logger.print("bin14: "); Serial.println(hist.bin13);
      logger.print("bin15: "); Serial.println(hist.bin14);
      logger.print("bin16: "); Serial.println(hist.bin15);
      logger.println("");
      
    }else{
      Serial.print("Sensor waking up");
      Serial.println("");
      counter++;  
      }
     
    delay(sampleRate);  
}

