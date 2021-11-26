#include<Servo.h>
Servo s;
void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);    // set arduino pin 7 to output mode
  pinMode(5, INPUT);    // set arduino pin 5 to input mode
  s.attach(2);            // attaches the servo on pin 2 to the servo object
  s.write(0);
}

void loop()
{
  digitalWrite(7, HIGH);
  delayMicroseconds(10); 
  digitalWrite(7, LOW);    // generate 10-microsecond pulse to TRIG pin

  float dur = pulseIn(5, HIGH);
  float dis = (dur*0.0343)/2;    // calculate the distance


  if(dis <200)
      s.write(90);    // rotate servo motor to 90 degree to open garage door
 
  delay(2000);
  s.write(0);        // rotate servo motor to 0 degree to close garage door

  Serial.print("Distance in cm: ");
  Serial.println(dis);
}