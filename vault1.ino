int Button1 = 2;
int Button2 = 3;
int Button3 = 4;

int ButtonState = 0;
int ButtonState2 = 0;
int ButtonState3 = 0;

int Correct = 0;
int Wrong = 0;

int Combination = 10;

int Red = 11;
int Green = 10;
int Blue = 9;

int Open = 5;
int Close = 6;


void Setcolor  ( int Redv , int Greenv , int Bluev)

{analogWrite (Red,Redv);
 analogWrite (Blue,Bluev); 
 analogWrite (Green,Greenv);
}


void setup()
{
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  
  pinMode(Open, OUTPUT);
  pinMode(Close, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  ButtonState  = digitalRead(Button1);
  ButtonState2 = digitalRead(Button2);
  ButtonState3 = digitalRead(Button3);
  

  
  Serial.print("  Button1:  ");
  Serial.print(ButtonState);
  
  Serial.print("  Button2:   ");
  Serial.print(ButtonState2);
  
  Serial.print("  Button3:   ");
  Serial.println(ButtonState3);
  
  
  if (ButtonState == 1 && ButtonState2 == 0 && ButtonState3 == 0 && Correct == 0)
  {
    Correct = Correct + 1;
    Setcolor ( 255 ,0 ,0 );
      
  }
  
  else if (Correct == 1 && ButtonState2 == 1 && ButtonState3 == 0 && ButtonState == 0)
  {
    Correct = Correct + 2;
    Setcolor ( 255, 106 , 0);
      
  }
  
  else if (Correct == 3 && ButtonState == 1 && ButtonState2 == 0 && ButtonState3 == 0)
  {
    Correct = Correct + 3;
    Setcolor (246 , 255 , 0);
      
  }
  
  else if (Correct == 6 && ButtonState == 0 && ButtonState2 == 0 && ButtonState3 == 1)
  {
    Correct = Correct + 4;
    ( 0 , 255 , 0);
      
  }
  
  if (Correct == 10)
  {
    Setcolor (0 , 255 , 0);
    digitalWrite( Open, 255);
    digitalWrite( Close, 0);
    delay(200);
    digitalWrite (Open, 0);
    digitalWrite (Close, 0);
    
    
  }
  
  
   if (Correct == 10 && ButtonState == 1 && ButtonState2 == 1 && ButtonState3 == 1)
  {
    Setcolor (0 , 255 , 0);
    delay(2000);
    Setcolor (255 , 0 , 0 );
    
    Serial.print("       ");
    Serial.print(" Vault Locked");
    Serial.print("       ");
    Serial.end();
     
    digitalWrite( Open, 0);
    digitalWrite( Close, 255);
    delay(200);
    digitalWrite (Open, 0);
    digitalWrite (Close, 0);
    
  }
  
  if ( ButtonState == 1 && ButtonState2 == 1 && ButtonState3 == 0)
  {
    digitalWrite (Open, 0);
    digitalWrite (Close, 0);
    
  }
  
  Serial.print(" CorrectNUmbers :    ");
  Serial.print(Correct);
  
  
  
 
  
}