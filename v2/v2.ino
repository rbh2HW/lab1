
#define pushButton2 23//GPIO23
#define pushButton1 22//GPIO22
#define SignalB 21//GPIO21
#define SignalA 15//GPIO15

#define paramB 0.1
#define paramMode 2

#define paramBlockSpace 

//GND
//V5
float paramA;
int paramPulses;


void setup() {
  // put your setup code here, to run once:
pinMode(SignalA, OUTPUT);
pinMode(SignalB, OUTPUT);
pinMode(pushButton1, INPUT);
pinMode(pushButton2, INPUT);

//int pushButton2Boolean=0;
//int pushButton1Boolean=0;


}

void loop() {
  // put your main code here, to run repeatedly:
 paramA =0.8;
 paramPulses =13;


int pushButton2Boolean=0;
int pushButton1Boolean=0;

  pushButton2Boolean=digitalRead(pushButton2);
  pushButton1Boolean=digitalRead(pushButton1);

  Serial.print("push button 2");
  Serial.print(pushButton1Boolean);

  Serial.print("push button 1");
  Serial.print(pushButton1Boolean);
  
  
  if (pushButton1Boolean==1)
  {
    //disable stream of pulses
    return;
  }
  

  
  else
  {
    
    if (pushButton2Boolean) //this is the condition for the mode selection
{
  paramPulses=paramPulses+3;
}else
{
  paramPulses=13;
}
    
    digitalWrite(SignalB, HIGH);
    delay(0.5);
    digitalWrite(SignalB, LOW);

    
    for (int i = 1; i <= paramPulses; i++) {
    if (i==1)
    {
    digitalWrite(SignalA, HIGH);
      
  delay(paramA);
  
  digitalWrite(SignalA, LOW);
  delay(paramB);
      
    }else{
      
    
    paramA=paramA+0.5;
    digitalWrite(SignalA, HIGH);
      
  delay(paramA);
  
  digitalWrite(SignalA, LOW);
  delay(paramB);
   }

  }
  

 
  }
 

  
}
