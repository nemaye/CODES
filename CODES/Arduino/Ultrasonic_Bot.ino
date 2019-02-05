
int echoPin1=3; 
int trigger1=5;
int echoPin2=2;
int trigger2=4;
//int led1=10,led2=11;
int t1,t11,t12;   
int t2,t21,t22;
int distance1,distance2;
int left_front=10, left_back=11;
int right_front=8, right_back=9;
int check11, check12, check13;
int check21, check22, check23;
//void ultrasonic();

void setup() {
  // put your setup code here, to run once:
pinMode(echoPin1,INPUT);
pinMode(trigger1,OUTPUT);
pinMode(echoPin2,INPUT);
pinMode(trigger2,OUTPUT);
pinMode(left_front,OUTPUT);
pinMode(left_back,OUTPUT);
pinMode(right_front,OUTPUT);
pinMode(right_back,OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

straight();

if(distance1<=25&&distance2>=25)
  right();

if(distance1>=25&&distance2<=25)
  left();

if(distance1<=15&&distance2<=15)
  reverse();
}

void straight()
{
   ultrasonic();

if(distance1>=25&&distance2>=25) 
 {
  digitalWrite(left_front,HIGH);
  digitalWrite(left_back,LOW);
  digitalWrite(right_front,HIGH);
  digitalWrite(right_back,LOW);

Serial.print("dist1_for_straight");
Serial.println(distance1);

Serial.print("dist2_for_straight");
Serial.println(distance2);
 }
}

void right()
{  
  digitalWrite(left_front,HIGH);
  digitalWrite(left_back,LOW);
  digitalWrite(right_front,LOW);
  digitalWrite(right_back,LOW);
}

void left()
{
  digitalWrite(left_front,LOW);
  digitalWrite(left_back,LOW);
  digitalWrite(right_front,HIGH);
  digitalWrite(right_back,LOW);
}

void reverse()
{
  digitalWrite(left_front,LOW);
  digitalWrite(left_back,HIGH);
  digitalWrite(right_front,LOW);
  digitalWrite(right_back,HIGH);
//delay(1000);                             
sharp_turn();
}

void ultrasonic()
{
digitalWrite(trigger1,HIGH);
delayMicroseconds(10);
digitalWrite(trigger1,LOW);

while (digitalRead(echoPin1)==LOW)
  t11=micros();
while (digitalRead(echoPin1)==HIGH)
  t12=micros();
t1=t12-t11;
distance1=0.034*t1/2;

digitalWrite(trigger2,HIGH);
delayMicroseconds(10);
digitalWrite(trigger2,LOW);

while (digitalRead(echoPin2)==LOW)
  t21=micros();
while (digitalRead(echoPin2)==HIGH)
  t22=micros();
t2=t22-t21;
distance2=0.034*t2/2;

}

void sharp_turn()
{
  digitalWrite(left_front,HIGH);
  digitalWrite(left_back,LOW);
  digitalWrite(right_front,LOW);
  digitalWrite(right_back,HIGH);  
delay(1000);
}
