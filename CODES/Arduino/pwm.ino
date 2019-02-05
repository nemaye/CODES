int ledPin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin, HIGH);
delayMicroseconds(500);
digitalWrite(ledPin, LOW);
delayMicroseconds(8000);
}
