int motor_left[] = {5, 6};
int motor_right[] = {7, 8};
int state = 0;
int ledPin=12;

// --------------------------------------------------------------------------- Setup
void setup() {
Serial.begin(9600);
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado

// Setup motors
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
}

}

// --------------------------------------------------------------------------- Loop
void loop() {
 //si el modulo a manda dato, guardarlo en estado.
  if(Serial.available() > 0){
       state = Serial.read();
  } // esta parte del código es para solo 1 Carácter o Unidad. 
 
 // si el estado es 0 ese sería Apagado “OFF”
 if (state == '0') {
          digitalWrite(ledPin, HIGH);
    drive_forward();
    Serial.println("LED: off");
 }
 
 // de lo contrario si el estado es 1 ese sería Encendido “ON”
 else
 if (state == '1') {
      digitalWrite(ledPin, LOW);
drive_backward();
Serial.println("LED: on");
 }
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
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
}

void drive_backward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
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


