int echoPin=8;
int trigger=7;
int distance;
int duration;
int time1,time2;
int value;
void setup() {
  // put your setup code here, to run once:
pinMode(trigger,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger,LOW);
delay(5);

digitalWrite(trigger,HIGH);
delay(10);
digitalWrite(trigger,LOW);

if(digitalRead(echoPin)==HIGH)
time1=micros();
if(digitalRead(echoPin)==LOW)
time2=micros();
duration=time2-time1;
distance=duration*0.034/2;
constrain(distance,0,200);
value=map(distance,0,200,0,20);
Serial.println(value);
delay(200);
}
