#include <Servo.h>

int motor_left[] = {5, 6};
int motor_right[] = {7, 8};
int state = 0;
int ledPin=12;
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
const int buzzerPin = 9;
Servo servo;

// --------------------------------------------------------------------------- Setup
void setup() {
Serial.begin(9600);
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado
    pinMode(buzzerPin, OUTPUT);
  

// Setup motors
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
}

//Setup Servo
 servo.attach(10);
 
}

// --------------------------------------------------------------------------- Loop
void loop() {
 //si el modulo a manda dato, guardarlo en estado.
  if(Serial.available() > 0){
       state = Serial.read();
  } // esta parte del código es para solo 1 Carácter o Unidad. 
 
 // si el estado es 0 ese sería Apagado “OFF”
 if (state == '0') {
          digitalWrite(ledPin, LOW);
    drive_forward();
 }
 
 // de lo contrario si el estado es 1 ese sería Encendido “ON”
 if (state == '1') {
      digitalWrite(ledPin, HIGH);
drive_backward();
 }
  if (state == '2') {
turn_left();
 }
  if (state == '3') {
turn_right();
 }
  if (state == '4') {
motor_stop();
 }

 if (state == '5') {
firstSection();
 }
 if (state == '6') {
servo1();
 }
 if (state == '7') {
servo2();
 }

 
 state=-1;
}

// --------------------------------------------------------------------------- Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

void drive_backward(){
  
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 

}


void turn_left(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

// --------------------------------------------------------------------------- Buzzer
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
   delay(duration);
  //Stop tone on buzzerPin
  noTone(buzzerPin);
  delay(50);
  
}
 
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
  state=-1;
}
 

// --------------------------------------------------------------------------- Fire


void servo1(){
 servo.write(105);
} 

void servo2(){
 servo.write(0);
} 
  
