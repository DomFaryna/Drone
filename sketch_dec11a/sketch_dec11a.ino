


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, INPUT);
Serial.write('1');

}

void loop() {
  int count = 0;
  int ones = 0;
  
  // put your main code here, to run repeatedly:
  while(count < 100){
    int value = digitalRead(13);
    Serial.println(value);
    //Serial.write('0');
    count++;
    if(value == 1){
      ones++;
    }
    delay(100);
  }
  
  Serial.println("Total: " + String(count) + "         Ones: " + String(ones));
  
  delay(10000000);
  
  
  
  
  //Serial.println("Hello");
  //delay(1000);
}
