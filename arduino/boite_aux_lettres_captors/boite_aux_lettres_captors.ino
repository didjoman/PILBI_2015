#include <NewPing.h>

#include <NewPing.h>
#define PinEcho     11  // broche Echo sur pin Digital 12
#define PinTrigger  12  // broche Trigger sur pin Digital 11

#define distanceMax 100 // définition de la distance maximale de captation en centimètres.

/* Constante */
int consoleOutput = 9600;

/* --------------- Capteur de contact --------------- */
/* Accrocher le détecteur au port analogique A0 */
int contact_sensor = 0; // A0
boolean detect_close_door = 0;

/* --------------- Photo resistance --------------- */
const char photo_resistance = 1;
int photo_resistance_value;

/* --------------- Capteur Ultrason --------------- */
NewPing sonar(PinTrigger, PinEcho, distanceMax); // initialisation de la fonction de sonar de notre bibliothèque
int pingLap = 50; // temps entre chaque pulsation en millisecondes.
long pingTimer;   // minuterie entre chaque pulsation.

/* Initialize pins states */
void initPins() {
  pinMode(contact_sensor, INPUT);
  pinMode(photo_resistance,OUTPUT);
}

/* Initialize console output */
void initOutput() {
  Serial.begin(consoleOutput);
}

/* Code Initialized Once */
void setup() 
{
  initPins();
  initOutput();
  pingTimer = millis(); // initialisation de la minuterie.
}

/* Code executed in a loop */
void loop() 
{
  /* Capteur de contact : porte boite aux lettres */
  if(analogRead(A0) != 0) {
    /* Porte ouverte */
    detect_close_door = true;
  }
  if(detect_close_door && analogRead(A0) == 0) {
    /* Porte fermée */
    detect_close_door = false;
    Serial.println("porte");
  }
  delay(1000);
  /* Photoresistance */
  photo_resistance_value = analogRead(photo_resistance);  
  //Serial.print(photo_resistance_value);
  if (photo_resistance_value < 800) {
    //Serial.println(" - Noir");   
  } else {
    //Serial.println(" - lumineux");  
  }

  /* Capteur Ultrason */
  if (millis() >= pingTimer)
  {
    pingTimer += pingLap;
    sonar.ping_timer(echoSonar); // fonction de vérification des conditions.
  }
}

/* Capteur Ultrason : affichage */
void echoSonar() {
  if (sonar.check_timer()) // fonction de vérification de la minuterie.
  { 
    //Serial.println("Distance à l'obstacle: ");
    //Serial.println(sonar.convert_cm(sonar.ping_result)); // fonction de conversion du delai en microsecondes en distance en cm.
    //Serial.println("cm");
  }
}
