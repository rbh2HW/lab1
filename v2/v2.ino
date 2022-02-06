#define pushButton2 23 //GPIO23
#define pushButton1 22 //GPIO22
#define SignalB 21 //GPIO21
#define SignalA 15 //GPIO15

#define paramB 0.1
#define paramMode 2

#define paramBlockSpace

float paramA;
int paramPulses;

void setup() {

  pinMode(SignalA, OUTPUT); //signalA from 15
  pinMode(SignalB, OUTPUT); //signalB from 21

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(pushButton2, INPUT); //mode selection button

}

void loop() {
  // put your main code here, to run repeatedly:
  paramA = 0.8; //non const wait period for signal to be high
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
      paramPulses = paramPulses + 3; // if the button is presse then it adds 3 pulses to the amount of iterations required
    } else {
      paramPulses = 13;
    }

    digitalWrite(SignalB, HIGH); //starting signal
    delay(0.5); //starting signal
    digitalWrite(SignalB, LOW); //starting signal

    for (int i = 1; i <= paramPulses; i++) {
      if (i != 1) //since first iteration doesn't need 0.5milliseconds added, it is split into a if/else
      {
        paramA = paramA + 0.5; //adding 0.5milisec for each iteration

      }

      digitalWrite(SignalA, HIGH);
      delay(paramA);

      digitalWrite(SignalA, LOW);
      delay(paramB);

    }

    //updating condition for while loop - button pressed
    pushButton1Boolean = digitalRead(pushButton1);
  }
}
