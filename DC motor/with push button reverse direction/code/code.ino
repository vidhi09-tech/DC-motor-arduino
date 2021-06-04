int md1Pin = 6;
int md2Pin = 7; 
int lButton = 9; 
int rButton = 8; 
int lButtonState=0;
int rButtonState=0;
void setup()
{
   pinMode(md1Pin, OUTPUT); 
   pinMode(md2Pin, OUTPUT); 
   pinMode(lButton, INPUT_PULLUP); 
   pinMode(rButton, INPUT_PULLUP);
}

void loop()
{
  lButtonState = digitalRead(lButton); 
   rButtonState = digitalRead(rButton); 
   if (rButtonState == LOW) {  
      digitalWrite(md1Pin, HIGH); 
      digitalWrite(md2Pin, LOW); 
   }
   else if (lButtonState == LOW) { 
      digitalWrite(md1Pin, LOW); 
      digitalWrite(md2Pin, HIGH); 
   }
   else { 
      digitalWrite(md1Pin, LOW); 
      digitalWrite(md2Pin, LOW); 
   } 

}
