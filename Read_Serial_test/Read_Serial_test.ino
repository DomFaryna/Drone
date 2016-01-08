/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
String rea = "foo";
char cha;
int timer = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  while (Serial.available()){ // Serial available works when there is something that is suppose to be sent to the arduino
      
      timer++;
      //Serial.println(Serial.available());
      Serial.read();
      
  }if (!Serial.available()){
         if (timer != 0){
         Serial.println(timer);
         timer = 0;
         delay (500);
        }
      }
  
  
    
  
}



