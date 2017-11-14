/*CONFIGURACION PARA MODULO BT HC-05 BY EP FOR TEAMAURA*/
/*ARDUINO NANO*/


const int LED =11;
const int BTPOWER=10;

char NombreBT[12]="TeamAuraBT1";
char pin[5]="4869";
char velocidad='4'; //9600
char modo='1'; //Para indicar que va a ser modo maestro.

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTPOWER, OUTPUT);

  Serial.begin(38400); //velocidad de BT en modo configuracion

  
  digitalWrite(LED, HIGH); // PAra indicar cuando entra en modo configuracion.
  delay(4000);
  digitalWrite(LED, LOW);

  digitalWrite(BTPOWER, HIGH); //Inicializa el proceso de alimentacion.
  delay(2500);
  Serial.print("AT\r\n"); //Para finalizar un comando.

  Serial.print("AT+NAME:"); // Para configurar el nombre, depende de la versión el comando, si no funciona probar con NAME O NAME=
  Serial.print(NombreBT);
  Serial.print("\r\n");

  Serial.print("AT+PIN:"); //PAra configurar el pin, si no funciona probar con AT+PSWD:
  Serial.print(pin);
  Serial.print("\r\n");

  Serial.print("AT+BAUD:"); // Para cambiar la velocidad al modo normal de funcionamiento.
  Serial.print(velocidad);
  Serial.print("\r\n");

  Serial.print("AT+MODE:"); // Para configurar el modo de funcionamiento, 1 para maestro y 0 para esclavo.
  Serial.print(modo);
  Serial.print("\r\n");

  digitalWrite(LED, HIGH); // Cuando todo el proceso de configuracion termine, el led del arduino se encenderá.
  
}

void loop(){
  
}

