
#define pushButton2 23//GPIO23
#define pushButton1 22//GPIO22
#define SignalB 21//GPIO21
#define SignalA 15//GPIO15



//GND
//V5



void setup() {
  // put your setup code here, to run once:
pinMode(SignalA, OUTPUT);
pinMode(SignalB, OUTPUT);
pinMode(pushButton1, INPUT);
pinMode(pushButton2, INPUT);

int pushButton2Boolean=0;
int pushButton1Boolean=0;

}

void loop() {
  // put your main code here, to run repeatedly:
  
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
  digitalWrite(SignalA, HIGH);
  }
  else if (pushButton2Boolean==1)
  {
  digitalWrite(SignalB, HIGH);
  }
  else
  {

   digitalWrite(SignalA, LOW);
    digitalWrite(SignalB, LOW);
  }
}
