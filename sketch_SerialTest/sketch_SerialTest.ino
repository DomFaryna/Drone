// Open a serial connection and flash LED when input is received
String ha = "ha";

void setup(){
  // Open serial connection.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.write('1'); 
  
}

void loop(){ 
      // if data present, blink
    Serial.println(ha);
    delay(1000);
    ha+= "hahahahahahahahaha";
  
} 
