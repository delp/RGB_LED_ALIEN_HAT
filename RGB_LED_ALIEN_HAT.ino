boolean mainOn = false;

#define iterNum 40

#define R1 11
#define G1 10
#define B1 9

#define R2 6
#define G2 5
#define B2 3

#define main1 2

void setup() {
  
pinMode(main1, OUTPUT);
 
  pinMode(B2, OUTPUT); 
  pinMode(G2, OUTPUT); 
   pinMode(R2, OUTPUT); 
 pinMode(B1, OUTPUT); 
  pinMode(G1, OUTPUT); 
   pinMode(R1, OUTPUT); 

  digitalWrite(main1, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(G2, HIGH);
  digitalWrite(R2, HIGH);

  digitalWrite(B1, HIGH);
  digitalWrite(G1, HIGH);
  digitalWrite(R1, HIGH);
  
}

void flip()
{
  if(mainOn) {
    digitalWrite(main1, LOW);
    mainOn = false;
  } else {
    mainOn = true;
    digitalWrite(main1, HIGH);
  }
}

  
void clearAll() {
   digitalWrite(G1, HIGH);
   digitalWrite(R1, HIGH);
   digitalWrite(B1, HIGH);
   
   digitalWrite(G2, HIGH);
   digitalWrite(R2, HIGH);
   digitalWrite(B2, HIGH);

}

void fadeUp(int pin) 
{
   for(int i = 255; i >= 0; i--)
   {
     analogWrite(pin, i);
     delay(10);
   }  
}

void fadeDown(int pin)
{
   for(int i = 0; i <= 255; i++) 
   {
     analogWrite(pin, i);
     delay(10);
   }
}

void fadeTwoUp(int pin1, int pin2)
{
   for(int i = 255; i >= 0; i--)
   {
     analogWrite(pin1, i);
     analogWrite(pin2, i);
     delay(10);
   }    
}


void fadeTwoDown(int pin1, int pin2)
{
   for(int i = 0; i <= 255; i++) 
   {
     analogWrite(pin1, i);
     analogWrite(pin2, i);
     delay(10);
   }
}



void loop() {
  for(int i = 0; i < iterNum; i++)
    {
      digitalWrite(G2, LOW);
     digitalWrite(G1, LOW);
    delay(i * 30);
    digitalWrite(G1, HIGH);
    digitalWrite(G2, HIGH);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    delay(i * 30); 
    digitalWrite(R1,HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    delay(i * 30);
    digitalWrite(B2,HIGH);
    digitalWrite(B1, HIGH);
  
      flip();
    }

 
   fadeUp(R1);
   fadeDown(R1);
   fadeTwoUp(R1, R2);
   fadeTwoDown(R1, R2);
   fadeUp(R2);
   fadeDown(R2);
   clearAll();
   
   fadeUp(G1);
   fadeDown(G1);
   fadeTwoUp(G1, G2);
   fadeTwoDown(G1, G2);
   fadeUp(G2);
   fadeDown(G2);
   clearAll();
   
   fadeUp(B1);
   fadeDown(B1);
   fadeTwoUp(B1, B2);
   fadeTwoDown(B1, B2);
   fadeUp(B2);
   fadeDown(B2);
   clearAll();
 
   
}
 
