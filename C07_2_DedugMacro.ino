/*  DedugMacro.ino
 *   除錯訊息開關範例
 *   使用時機 : 部分除錯訊息不想在正式執行輸出，可以用這個小技巧
 *   使用方法 :  設定  " #define DEBUG X "  , X ==0  不印出訊息，X==1 印出訊息    
 *   
 *   引用來源 : C 教科書衍生
 *      
 *   Author : allen54a0
 *   DATE: 2015 1229
 * 
 */



//
//#define DEBUG 0         // 藉由定義 0 或 1 來關閉或開啟除錯訊息
//#define DEBUGP(x) if (DEBUG == 1) { x ; }


#define DEBUG 0
#if(DEBUG)
#define DEBUGP(x) Serial.println(x)
#else
#define DEBUGP(x) 
#endif


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println("DEBUG_MACRO_TEST_02");

}

void loop() {
  //  


  //do something, 一般的程式操作



  //Normal Dump ,一般需要輸出的訊息
  Serial.println("Status DUMP");

  //dump debug Message  , 僅有除錯時要印出輸出的訊息，正式執行時不輸出
  DEBUGP("DEBUG02  DUMP000");
  DEBUGP("DEBUG02  DUMP001");
  DEBUGP("DEBUG02  DUMP002");
  DEBUGP("DEBUG02  DUMP003");
  DEBUGP("DEBUG02  DUMP004");

 
  delay(1000);



}
