#define pushButton2 23 //GPIO23
#define pushButton1 22 //GPIO22
#define SignalB 21 //GPIO21
#define SignalA 15 //GPIO15


//#define paramMode 2

#define paramBlockSpace

float paramA;
int paramPulses;
float paramB;
float paramD;

int tempParamA;

int signalBDelay=5;

void setup() {

  pinMode(SignalA, OUTPUT); //signalA from 15
  pinMode(SignalB, OUTPUT); //signalB from 21

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(pushButton2, INPUT); //mode selection button

}

void loop() {
   paramB =10;
   paramD=550;
  // put your main code here, to run repeatedly:
  paramA = 80; //non const wait period for signal to be high
  paramPulses = 13; //non const amount of pulses in required loop

  //instatiating pushbutton booleans
  int pushButton2Boolean = 0;
  int pushButton1Boolean = 0;

  //reading both digital values
  pushButton2Boolean = digitalRead(pushButton2);
  pushButton1Boolean = digitalRead(pushButton1);

  Serial.print("push button 2");
  Serial.print(pushButton1Boolean);

  Serial.print("push button 1");
  Serial.print(pushButton1Boolean);

  

  while (pushButton1Boolean == 0) {
    
 
  
    if (pushButton2Boolean) //this is the condition for the mode selection,
    {
      paramB=5;
      paramD=275; //paramD/2 = 5.5/2=2.75
      
      //paramPulses = paramPulses + 3; // if the button is presse then it adds 3 pulses to the amount of iterations required
    } else {
      paramB=10;
      paramD=550;
     // paramPulses = 13;
    }

    digitalWrite(SignalB, HIGH); //starting signal
    delay(signalBDelay); //starting signal
    digitalWrite(SignalB, LOW); //starting signal
    delay(signalBDelay); //starting signal
    
    for (int i = 1; i <= paramPulses; i++) {
      if (i != 1) //since first iteration doesn't need 0.5milliseconds added, it is split into a if/else
      {
        tempParamA = paramA + (5*(i-1)); //adding 0.5milisec for each iteration

      }

      digitalWrite(SignalA, HIGH);
      delay(tempParamA);

      digitalWrite(SignalA, LOW);
      delay(paramB);

    }
    delay(paramD);
    //updating condition for while loop - button pressed
         pushButton2Boolean = digitalRead(pushButton2);
  pushButton1Boolean = digitalRead(pushButton1);
  }
  //    digitalWrite(SignalB, HIGH); //starting signal
   // delay(0.05); //starting signal
    //digitalWrite(SignalB, LOW); //starting signal
   // delay(0.05); //starting signal
}
