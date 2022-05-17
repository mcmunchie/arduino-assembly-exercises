void setup() {
  // put setup code here, to run once:
pinMode(13,OUTPUT);
}

void loop() {
  // put main code here, to run repeatedly:
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
delay(20);
}
