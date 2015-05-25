//ICARUS ONE CONTROL UNIT

#include <Servo.h> 
 
Servo myservo;  

int triggerpin = 5;
int offpin = 2;
int dot = 7;
int longdot = 8;

int buttonState;            
int lastButtonState = LOW;   
int button2State;             
int lastButton2State = LOW;   
int button3State;             
int lastButton3State = LOW;   
int button4State;
int lastButton4State = LOW;


void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(triggerpin, INPUT);
  pinMode(offpin, INPUT);
  pinMode(dot, INPUT);
  pinMode(longdot, INPUT);  
} 
 
 
void loop() 
{ 
  buttonState = digitalRead(triggerpin);
  button2State = digitalRead(offpin);
  button3State = digitalRead(dot);
  button4State = digitalRead(longdot);

//On Off Spray 
  if ((buttonState != lastButtonState || button2State != lastButton2State)) {
    if (buttonState == HIGH) {
      myservo.write(90);
    delay(15);
    } 
    else if (button2State == HIGH) {
       myservo.write(0);
    delay(15);
    }
  }

//Short Dot Spray 
  if (button3State != lastButton3State && button3State == HIGH){
    myservo.write(0);
    delay(500);
     myservo.write(100);
  }
 
//Long Dot Spray
  if (button4State != lastButton4State && button4State == HIGH){
    myservo.write(0);
    delay(1500);
     myservo.write(100);
  }
 
  lastButtonState = buttonState;
  lastButton2State = button2State;
  lastButton3State = button3State;
  lastButton4State = button4State;
  delay(1);
}
