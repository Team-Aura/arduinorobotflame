#include <SoftwareSerial.h>
#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  13  
#define ECHO_PIN     9  
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

SoftwareSerial BT(2, 3); // RX | TX

int Motor11 = 10;
int Motor12 = 7;
char a;

int Motor21 = 4;
int Motor22 = 8;

int Led = 5;
int Arc = 12;

Servo servo;
Servo servo1;

void setup() {
  pinMode(Motor11, OUTPUT);
  pinMode(Motor12, OUTPUT);

  pinMode(Motor21, OUTPUT);
  pinMode(Motor22, OUTPUT);
  
  pinMode(Led, OUTPUT);
  pinMode(Arc, OUTPUT);
  servo.attach(6);
  servo.write(153);
  //servo1.attach(11);
  
  Serial.begin(115200);
  BT.begin(9600);
  BT.println("Hello from Arduino");

}

int vitesse = 500;
  
void forward() {
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, HIGH);
  
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, HIGH);
}

void backward() {
  digitalWrite(Motor11, HIGH);
  digitalWrite(Motor12, LOW);
  
  digitalWrite(Motor21, HIGH);
  digitalWrite(Motor22, LOW);
}

void left() {
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, HIGH);
}

void right() {
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, HIGH);
}

void stopped() {
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, LOW);
  
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, LOW);
}

void distance() {
  unsigned int uS = sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
}

void look() {
  servo.write(45);
  delay(1000);
  servo.write(135);
  delay(1000);
}

unsigned long time = millis();
int on = 0;
void fire() {
  if(millis() - time > 1200)
  {
    time = millis();
    if(on == 0)
    {
      on = 1;
      digitalWrite(Arc, LOW);
      servo.write(153);
      digitalWrite(Led, LOW);
    }
    else
    {
      on = 0;
      digitalWrite(Arc, HIGH);
      servo.write(105);
      digitalWrite(Led, HIGH);
    } 
  }
}

int state = 0;
void light() {
  if(state == 0)
  {
    state = 1;
    digitalWrite(Led, HIGH);
  }
  else
  {
    state = 0;
    digitalWrite(Led, LOW);
  }
}

void blink() {
  for(int i=0; i < 4 ; i++)
  {
    digitalWrite(Led, HIGH);
    delay(500);
    digitalWrite(Led, LOW);
    delay(500);
  }
}

void loop() {
  if (BT.available())
  {
    //
    a=(BT.read());
    // 1 avancer
    // 2 arrière
    // 3 Gauche
    // 4 Droite
    // 5 Select
    // 6 Start
    // 7 Triangle
    // 8 Square
    // 9 X
    // A Ball
    if (a=='1')
    {
      forward();
    }
    else if (a=='2')
    {
      backward();
    }
    else if (a=='3')
    {
      left();
    }
    else if (a=='4')
    {
      right();
    }
    else if (a=='0')
    {
      stopped();
    }
    else if (a=='8')
    {
      fire();
     delay(500);
    }
    else if (a=='9')
    {
      blink();
      delay(500);
    }
    else if (a=='7')
    {
      light();
      delay(500);
    }  
  }
  
}
