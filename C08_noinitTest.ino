///This code is from http://forum.arduino.cc/index.php?topic=41088.0 by mem
/// 下面這個程式說明加上__attribute__ ((section(".noinit"))); 陳述的變數，再重新Reset 之後(不掉電的前提下)
/// 是可以保持住重開機之前的數值的

/// 用途
/// 可以用來維護一些隨時間改變，但是不方便放在EEPROM的變數，例如 軟體時間，系統執行狀態等.... 



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
