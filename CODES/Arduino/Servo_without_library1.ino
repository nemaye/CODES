
int angle;
int servopin=5;
int pwm;


void setup() {
  // put your setup code here, to run once:
pinMode(servopin,OUTPUT);
}

void loop() {
for(angle=0; angle<180; angle+=5)
{
  servo(angle);
}
for(angle=180; angle>0; angle-=5)
{
  servo(angle);
}
}
void servo(int angle)
{
  pwm=map(angle,0,180,500,2500);
  digitalWrite(servopin,HIGH);
  delay(pwm);
  digitalWrite(servopin,LOW);
  delay(50);  
}
