/*
Code for  moreStableArduinoCode


Class 3. Watching DOG
Note            : NEED UNO BOARD or MEGA Board, or  had burnned the optiboot bootloader into your legecy board (mini, nano, duemilanove)        
author          : allen54a0@gmail.com
compiler        : arduino IDE 1.8.4
lib dependience :  

#include <SerialCommand.h>
#include <avr/wdt.h>

https://github.com/allen54a0/moreStableArduinoCode
*/




#include <SerialCommand.h>
 #include <avr/wdt.h>
 
 

#define SYS_HZ  20 
//DOn;t Touch Variable 
#define  SYS_HZ_COUNT  (1000 / SYS_HZ)-1
 
  

#define arduinoLED 13   // Arduino LED on board

SerialCommand SCmd;   // The demo SerialCommand object

 

unsigned long fast_loopTimer;       // Time in miliseconds of main control loop
int mainLoop_count=0;
int secondCounter =0;
  

void  doIOCheck(){

  //Do Somethong Here ..... called SYS_HZ times per Sec.... 
  Serial.print(":)_");

}


   
 
 
void WDT_TEST()
{
   Serial.println("WDT TEST"); 
   while(1){

    Serial.print("XD ");
    delay(500);
   }
}
 

 

// This gets set as the default handler, and gets called when no other command matches. 
void unrecognized()
{
  Serial.println("What?"); 
}


 



 

void setup()
{  



  pinMode(arduinoLED,OUTPUT);      // Configure the onboard LED for output
  digitalWrite(arduinoLED,LOW);    // default to LED off

  
  Serial.begin(9600); 

  /// Add command Here 
  // Setup callbacks for SerialCommand commands 

  SCmd.addCommand("WDT",WDT_TEST);    //WDT TEST, go into while(1) Loop
  SCmd.addDefaultHandler(unrecognized);  //   Handler for command that isn't matched  (says "What?") 
  Serial.println("\n\n\n\n moreStableArduinoCode WDT Example\n\n\n\n\ ");
     
 
 

  //Enable WDT ------------------->>>>>>

  wdt_enable(WDTO_4S);

}


 


 void loop()
 {  

   //Reset DWT  ------------------->>>>>>>
   wdt_reset();



   SCmd.readSerial();     // We don't do much, just process serial commands


   // n HZ system Loop 

   if (millis()-fast_loopTimer > SYS_HZ_COUNT) {

     fast_loopTimer   = millis();
     mainLoop_count++;


     doIOCheck();    
 
 

     //// 1 min Counter , can usd to other Hz..... 

  

     if(mainLoop_count% SYS_HZ ==0 ){

     //   DEBUGN("DEBUG ENABLE~~~");
       secondCounter++;
        

          if(secondCounter%2==0){
            digitalWrite(arduinoLED,HIGH);    // default to LED off
          }else{
            digitalWrite(arduinoLED,LOW);    // default to LED off
          }

          
          Serial.println("$");
         
        }

       

 

   }



 }
 
