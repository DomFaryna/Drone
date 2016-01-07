// Open a serial connection and flash LED when input is received

void setup(){
  // Open serial connection.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.write('1'); 
}

void loop(){ 
      // if data present, blink
    Serial.println("HAHAHAHAH");
    delay(1000);
  
} 
