#define pushButton2 23 //GPIO23
#define pushButton1 22 //GPIO22
#define SignalB 21 //GPIO21
#define SignalA 15 //GPIO15



int signalBDelay=5;
int  addition_To_A=5;


float  paramB =10; //100micro
float   paramD=55; //550 micro
float  paramA = 80; //80 micro
int paramPulses = 13; //13 iterations

//settting up temp perameters
int tempParamA;
int tempParamB;
int tempParamD;

void setup() {

  pinMode(SignalA, OUTPUT); //signalA from 15
  pinMode(SignalB, OUTPUT); //signalB from 21

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(pushButton2, INPUT); //mode selection button

}

void loop() {

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
      //following divides the parameters when the mode has been selected
      int tempParamB=paramB/2;
      int tempParamD=paramD/2; //paramD/2 = 5.5/2=2.75
      
      
    } else {
      //the following resets the temp perameters
      int tempParamB=paramB;
      int tempParamD=paramD;
     
    }

    digitalWrite(SignalB, HIGH); //starting signal
    delay(signalBDelay); //starting signal
    digitalWrite(SignalB, LOW); //starting signal
    
    
    for (int i = 1; i <= paramPulses; i++) {
      if (i != 1) //since first iteration doesn't need 0.5milliseconds added, it is split into a if/else
      {
        int tempParamA = paramA + (addition_To_A*(i-1)); //adding 0.5milisec for each iteration

      }
      else{
        int tempParamA=paramA; //makes sure to reset the value of the temp value 
      }
      

      digitalWrite(SignalA, HIGH);
      delay(tempParamA);

      digitalWrite(SignalA, LOW);
      delay(tempParamB);

    }
    delay(tempParamD);
    //updating condition for while loop - button pressed
         pushButton2Boolean = digitalRead(pushButton2);
  pushButton1Boolean = digitalRead(pushButton1);
  }

}
