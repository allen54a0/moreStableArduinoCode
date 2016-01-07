/*  C08_noinitTest.ino
 *   noinit Section 使用範例
 *   使用時機 : 系統Reset 或是當機之後，需要取得當機前的一些特定數值
 *   使用方法 : 可以用來維護一些隨時間改變，但是不方便放在EEPROM的變數，例如 軟體時間，系統執行狀態等....  
 *               加上   __attribute__ ((section(".noinit"))); 來宣告特定變數在硬體初始化時不被清除
 
 *   引用來源 : This code is from http://forum.arduino.cc/index.php?topic=41088.0 by mem
 *      
 *   Author : allen54a0
 *   DATE: 2016 0107
 * 
 */



int savedFlag __attribute__ ((section(".noinit")));

int i =0;

void setup() {
 Serial.begin(9600);
 Serial.print("Old: ");
 Serial.println(savedFlag,DEC); // note this prints the decimal value of the integer

 i++;
  Serial.print("Local Variable: ");
  Serial.println(i,DEC); // note this prints the decimal value of the integer
 
 savedFlag = savedFlag+i;
 Serial.print("New: ");
 Serial.println(savedFlag,DEC);
}

void loop() {
}
