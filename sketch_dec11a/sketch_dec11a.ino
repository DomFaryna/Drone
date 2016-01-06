void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
Serial.write('1');
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() > 0){
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  Serial.write('0');
  }
}
