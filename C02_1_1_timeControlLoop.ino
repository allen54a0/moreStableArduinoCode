/*
Code for  moreStableArduinoCode

Class 2.1.1 Time control Loop

Note            : This version uses Serial plot to demo the task Sequence.....        

author          : allen54a0@gmail.com
compiler        : arduino IDE 1.8.4
lib dependience : none

https://github.com/allen54a0/moreStableArduinoCode
*/

// 定義我們要的控制速度，每秒多少HZ , 下面的範例是每秒跑 10次 主迴圈 --------------->
#define SYS_HZ  10 
#define  SYS_HZ_COUNT  (1000 / SYS_HZ)-1   //這行不要動


//硬體設定定義--------------------------------------------------------------------->

#define arduinoLED 13   // Arduino LED on board

//Global 變數定義--------------------------------------------------------------------->

int ver_10HZ =0;   
int ver_1S   =0;
int ver_10S  =0; 

unsigned long fast_loopTimer;       // Time in miliseconds of main control loop
int mainLoop_count=0;
int secondCounter =0;


// 控制程序


//10HZ 控制程序, 每1秒被呼叫10 次

void doThings_10Hz(){

    //Serial.println("10Hz Loop");
    digitalWrite(arduinoLED,!digitalRead(arduinoLED));    // 用LED燈來顯示
   
     ver_10HZ = ! ver_10HZ ; 
   
        
          
}
// 1 Sec 控制程序，每1秒被呼叫1 次

void  doThings_1sec(){
 
     //Serial.println("1 Sec Loop");

    if(secondCounter%2==0)
      ver_1S=4;
    else
      ver_1S=3;
   
      
}

// 10 Sec 控制程序，每10秒被呼叫1 次

void  doThings_10sec(){

    //Serial.println("10 Sec Loop");
      if(secondCounter%20==0)
      ver_10S=7;
    else
      ver_10S=6;
   
}


void doUpdateStatus(){

     Serial.print("Status,");
     Serial.print(ver_10HZ);
     Serial.print(",");
     Serial.print(ver_1S);
     Serial.print(",");
     Serial.print(ver_10S);
     Serial.println("");
 
}


// 硬體與變數初始化--------------------------------------------------------------------->
void setup() {
  
  // put your setup code here, to run once:

   Serial.begin(115200);          //用來demo 程式的serial port 
   pinMode(arduinoLED,OUTPUT);  //用來demo 程式的LED燈腳位
   Serial.println("C02_1timeControlLoop RUN!");

}

void loop() {
  
  // put your main code here, to run repeatedly:
  
  //下面這個迴圈會每秒跑 SYS_HZ 次 , 這個範例碼是跑 SYS_HZ =10 HZ

   if (millis()-fast_loopTimer > SYS_HZ_COUNT) {

     fast_loopTimer   = millis();
     mainLoop_count++;

//// SYS_HZ lOOP  間隔 (1/SYS_HZ) 秒會跑一次, 這個範例是1/10 秒跑一次-------------------------------->
     
     doThings_10Hz();    
     
 
  

      if(mainLoop_count% SYS_HZ ==0 ){ // 這行不要改動

        secondCounter++;  // 每秒向上加 1 
   
        //// 1 秒迴圈 ,  每1 秒會跑一次  ---------------------------------------------------------------->
         doThings_1sec();   


        if(secondCounter%10==0){   // %10 就是每10秒跑進來一次

                  //// 1 秒迴圈 ,  每10 秒會跑一次  ---------------------------------------------------------------->
                   doThings_10sec();  
        }


    

     }

 
      doUpdateStatus();

   }

  

}
