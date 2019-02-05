
int ledpin=13;
int i=1;



void setup() {
  // put your setup code here, to run once:
 pinMode(ledpin,OUTPUT);// predefined function 

}

void loop() {
  // put your main code here, to run repeatedly:
    for(i=1;i<=10;i++)
   { if(i%2==0)
   { digitalWrite(ledpin,HIGH);
    delay(i*1000);}
    else
   { digitalWrite(ledpin,LOW);
    delay(i*1000);}
   }
}
