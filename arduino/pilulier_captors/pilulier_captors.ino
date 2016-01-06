/* Fait clignoter une LED*/

const int LED = 2; //declaration constante de broche
const int consoleOutput = 9600;

void setup()   {

 pinMode(LED, OUTPUT); //met la broche en sortie
 Serial.begin(consoleOutput);

} 

void loop(){ // debut de la fonction loop()
          

Serial.println("Led On");
digitalWrite(LED,HIGH); // met la broche au niveau haut (5V) – allume la LED

delay(500); // pause de 500 millisecondes (ms)

digitalWrite(LED,LOW); // met la broche au niveau bas (0V) – éteint la LED

delay(500); // pause de 500ms

}

