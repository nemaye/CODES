int trigger=8;
int echopin=9;
int ledpin1=5;
int ledpin2=6;
int ledpin3=7;
int Time;
int distance;
int value;
void setup() {
  // put your setup code here, to run once:
pinMode(trigger, OUTPUT);
pinMode(echopin, INPUT);
pinMode(ledpin1, OUTPUT);
pinMode(ledpin2, OUTPUT);
pinMode(ledpin3, OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger, HIGH);
delay(10);
digitalWrite(trigger, LOW);
digitalWrite(echopin, HIGH);
Time=pulseIn(echopin,HIGH);
distance=Time*0.034/2;
value=map(distance,0,200,0,5);
Serial.print("Value: ");
Serial.println(value);
if(value==0)
{
  digitalWrite(ledpin1,HIGH);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,LOW);
}

else if(value==1)
{
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,HIGH);
  digitalWrite(ledpin3,LOW);
}

else if(value==2)
{
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,HIGH);
}
else
{
  digitalWrite(ledpin1,HIGH);
  digitalWrite(ledpin2,HIGH);
  digitalWrite(ledpin3,HIGH);
}
}
