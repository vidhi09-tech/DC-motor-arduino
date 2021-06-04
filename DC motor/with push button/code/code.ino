int speedPin=5;
int dir1=4;
int dir2=3;
int pushB1=8;
int pushB2=9;
int B1Val;
int B2Val;
int mSpeed=0;
int dt=500;
void setup()
{
   pinMode(speedPin, OUTPUT);
   pinMode(dir1, OUTPUT);
   pinMode(dir2, OUTPUT);
   pinMode(pushB1,INPUT);
   pinMode(pushB2,INPUT);
   digitalWrite(pushB1,HIGH);
   digitalWrite(pushB2,HIGH);
   Serial.begin(9600);
}

void loop()
{
  B1Val=digitalRead(pushB1);
  B2Val=digitalRead(pushB2);

  Serial.print("Motor Speed:");
  Serial.println(mSpeed);
  Serial.print("Button 1 value:");
  Serial.println(B1Val);
  Serial.print("Button 2 value:");
  Serial.println(B2Val);
  if(B1Val==0)
  {
    mSpeed=mSpeed-10;
   delay(dt);
  }
  if(B2Val==0)
  {
    mSpeed=mSpeed+10;
    delay(dt);
  }
  if(mSpeed>0 && mSpeed<255)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin,mSpeed);
  }
  if (mSpeed>255)
  {
     digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin,255);
  }
   if(mSpeed>0 && mSpeed>-255)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin,mSpeed);
  }
  if (mSpeed<-255)
  {
     digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin,-255);
  }
  if (mSpeed==10)
  {
     digitalWrite(dir1, LOW);
    digitalWrite(dir2,HIGH);
    analogWrite(speedPin,100);
  }
  if (mSpeed==-10)
  {
     digitalWrite(dir1,LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin,-100);
  }
  if (mSpeed==90 || mSpeed==110)
  {
     digitalWrite(dir1,LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin,0);
  }
   if (mSpeed==-90 || mSpeed==-110)
  {
     digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin,0);
  }
}
