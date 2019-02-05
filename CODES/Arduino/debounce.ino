int ledPin=13;
int button=8;
int count=0;
boolean previous,current;
void setup() {
  // put your setup code here, to run once:
pinMode(button, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
previous=digitalRead(button);
delay(50);
current=digitalRead(button);
 if((previous==LOW&&current==HIGH)||(previous==HIGH&&current==LOW))
 {
  count++;
 }
 if(count==10)
 digitalWrite(ledPin,HIGH);
 Serial.println(count);
 delay(50);
}
