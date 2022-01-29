
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
pinMode(pushButton1, OUTPUT);
pinMode(pushButton2, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(SignalA, HIGH);
  delay(1000) ;
  digitalWrite(SignalA, LOW);
    delay(1000) ;
}
