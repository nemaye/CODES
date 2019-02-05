
int sw = 12;
int x = A0;
int y = A1;
int left_fwd = 11;
int left_back = 10;
int right_fwd = 6;
int right_back = 5;
int X_read, Y_read;
int x_12, y_12;
int x_34, y_34;
int x_56, y_56;
int x_78, y_78;

void setup() {
  // put your setup code here, to run once:
pinMode(sw, INPUT);
digitalWrite(sw, HIGH);
Serial.begin(9600);
pinMode(left_fwd,OUTPUT);
pinMode(left_back,OUTPUT);
pinMode(right_fwd,OUTPUT);
pinMode(right_back,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
X_read = analogRead(x);
Y_read = analogRead(y);

//Serial.print("X =");
//Serial.print(X_read+'\t');
//Serial.print("  Y =");
//Serial.println(Y_read);
  
  
  while(!((X_read>524||X_read<500)||(Y_read>524||Y_read<500)))
  {
     analogWrite(left_fwd,0);      
     analogWrite(right_fwd,0);
     analogWrite(left_back,0);      
     analogWrite(right_back,0);
     
     X_read = analogRead(x);
     Y_read = analogRead(y);

  }



if ((X_read+Y_read)<=1023&&X_read<=512&&Y_read>=512)
  oct1();

if ((X_read+Y_read)>=1023&&X_read<=512&&Y_read>=512)
  oct2();

if ((X_read-Y_read)<=0&&X_read>=512&&Y_read>=512)
  oct3();

if ((X_read-Y_read)>=0&&X_read>=512&&Y_read>=512)
  oct4();
  
if ((X_read+Y_read)>=1023&&X_read>=512&&Y_read<=512)
  oct5();

if ((X_read+Y_read)<=1023&&X_read>=512&&Y_read<=512)
  oct6();

if ((X_read-Y_read)>=0&&X_read<=512&&Y_read<=512)
  oct7();

if ((X_read-Y_read)<=0&&X_read<=512&&Y_read<=512)
  oct8();
  
//delay(500);
}

void oct1()
{
  x_12 = map(X_read,512,0,0,255);
  y_12 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_fwd , x_12-9);              //lf
  analogWrite(right_back , x_12-y_12);              //rb
  
Serial.print("left_fwd: ");
Serial.print(x_12-9+'\t');
Serial.print("   right_bck: ");
Serial.println(x_12-y_12);
}

void oct2()
{
  x_12 = map(X_read,512,0,0,255);
  y_12 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_fwd , y_12-9);              //lf
  analogWrite(right_fwd , y_12-x_12);             //rf
  
Serial.print("left_fwd: ");
Serial.print(y_12-9+'\t');
Serial.print("   right_fwd: ");
Serial.println(y_12-x_12);
}

void oct3()
{
  x_34 = map(X_read,512,1023,0,255);
  y_34 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_fwd , y_34-x_34-9);               //lf
  analogWrite(right_fwd , y_34);              //rf
  
Serial.print("left_fwd: ");
Serial.print(y_34-x_34-9+'\t');
Serial.print("   right_fwd: ");
Serial.println(y_34);
}

void oct4()
{
  x_34 = map(X_read,512,1023,0,255);
  y_34 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_back , x_34-y_34-9);                //lb
  analogWrite(right_fwd , x_34);              //rf

Serial.print("left_bck: ");
Serial.print(x_34-y_34-9+'\t');
Serial.print("   right_fwd: ");
Serial.println(x_34);
}

void oct5()
{
  x_56 = map(X_read,512,1023,0,255);
  y_56 = map(Y_read,512,0,0,255);
  
  analogWrite(left_back , x_56-9);                //lb
  analogWrite(right_fwd , x_56-y_56);            //rf

Serial.print("left_bck: ");
Serial.print(x_56-9+'\t');
Serial.print("  right_fwd: ");
Serial.println(x_56-y_56);
}

void oct6()
{
  x_56 = map(X_read,512,1023,0,255);
  y_56 = map(Y_read,512,0,0,255);
  
  analogWrite(left_back , y_56-9);                //lb
  analogWrite(right_back , y_56-x_56);            //rb

Serial.print("left_bck: ");
Serial.print(y_56-9+'\t');
Serial.print("  right_bck: ");
Serial.println(y_56-x_56);
}

void oct7()
{
  x_78 = map(X_read,512,0,0,255);
  y_78 = map(Y_read,512,0,0,255);
  
  analogWrite(left_back , y_78-x_78-9);                //lb
  analogWrite(right_back , y_78);            //rb

Serial.print("left_bck: ");
Serial.print(y_78-x_78-9+'\t');
Serial.print("  right_bck: ");
Serial.println(y_78);
}

void oct8()
{
  x_78 = map(X_read,512,0,0,255);
  y_78 = map(Y_read,512,0,0,255);
  
  analogWrite(left_fwd , x_78-y_78-9);                //lf
  analogWrite(right_back , x_78);            //rb

Serial.print("left_fwd: ");
Serial.print(x_78-y_78-9+'\t');
Serial.print("  right_bck: ");
Serial.println(x_78);
}
