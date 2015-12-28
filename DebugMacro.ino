#define DEBUG 1
#define DEBUGP(x) if (DEBUG == 1) { x ; }


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println("Program Start");

}

void loop() {
  // put your main code here, to run repeatedly:


  //do something



  //Normal Dump
  Serial.println("Status DUMP");

  //dump debug Message 
  DEBUGP(Serial.println("DEBUG  DUMP"));

 
  delay(1000);



}
