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
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);

while (digitalRead(echoPin)==LOW)
  time1=micros();
while (digitalRead(echoPin)==HIGH)
  time2=micros();
duration=time2-time1;
distance=0.034*duration/2;
Serial.print("dist(in cm): ");
Serial.println(distance);
}
