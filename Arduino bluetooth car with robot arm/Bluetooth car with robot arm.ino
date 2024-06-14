// Starting of Program
#include<Servo.h> // The file was added for servo motors.

// servo motors are defined as follow
Servo servo_a;
Servo servo_b;
Servo servo_c;

int pos;
int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
char val;

void setup() 
{  
servo_a.attach(3); //Pin 3 in arduino board
servo_b.attach(7); //pin 7 in arduino board
servo_c.attach(6); //pin 6 in arduino board 

pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
  
    else if(val == 'R') //Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    else if(val == 'L') //Left
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
  else if(val == 'G') //Forward Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'H') //Backward Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
   else if(val == 'I') //Forward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'J') //Backward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH); 
    }

//servo motors controlling panel

   //Servo motors rest part
   else if(val == 'A') // rotate to 180 degrees, left
   {
     if(pos <= 180)
     {
      pos++;
      servo_a.write(pos);
      delay(20);
      }     
    }

    else if( val == 'X') //rotate to rotate 0 degree, right
    {
      if(pos <= 0 )
      {
        pos++;
        servo_a.write(pos);
        delay(20);
       }
     
    }

    else if (val == 'P')
    {
       if( pos <= 90)
       {
        pos++;
        servo_a.write(pos);
        delay(20);
        }  
     }

    else if(val == 'Y')
    {  
      servo_b.write(65);
      
      }
  
    else if( val == 'U')
    {
     servo_b.write(10);
    }
    
//for servo_c
    
    else if(val == 'Z')
    {

       if (pos <= 100 )
      {

        pos ++;
        servo_c.write(pos);
        delay(20);
         
        }    
    }
  
   
    else if ( val == 'W')
    {

        if (pos >= 20 )
      {

        pos --;
        servo_c.write(pos);
        delay(20);
        
        
        }    
      
    }

    
}
