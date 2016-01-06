/* Fait clignoter une LED*/
const int LED = 2; //declaration constante de broche
const int consoleOutput = 9600;

/* --------------- Capteur de contact --------------- */
/* Accrocher le détecteur au port analogique A0 */
int contact_sensor = 3; //A3
boolean box_open = false;

/* Variables globales */
char command[500];
int state = 0;


/* Initialize console output */
void initOutput() {
  Serial.begin(consoleOutput);
}

/* Initialize pins states */
void initPins() {
  pinMode(LED, OUTPUT);
  pinMode(contact_sensor, INPUT);
}

/* Code Initialized Once */
void setup()
{
  initPins();
  initOutput();
}

void loop(){ // debut de la fonction loop()
  /*LED pour le warning */
  if (state == 1)
    clignote();
  if (Serial.readBytes(command, 10) == 0) {
    *command = NULL;
  } else {
    char *p = command;
    char *str;
    //Découpage des commandes
    while ((str = strtok_r(p, ";", &p)) != NULL) {
      //actions
      if (strstr(str, "CLIGNOTE") > 0) {
        state = 1;        
      }
    }
  }
  
  /* Capteur de contact sur la pillbox pour détecter prise de médicaments */
  Serial.println(analogRead(A3));
  if(!box_open && analogRead(A3) == 0) {
    /* Boite ouverte */
    box_open = true;
    Serial.println("Boite ouverte"); 
  }
  if(analogRead(A3) != 0) {
    /* Boite fermée */
    box_open = false;       
  }
}

void clignote() {
  Serial.println("Clignote");
  digitalWrite(LED,HIGH); // met la broche au niveau haut (5V) – allume la LED
  delay(500); // pause de 500 millisecondes (ms)
  digitalWrite(LED,LOW); // met la broche au niveau bas (0V) – éteint la LED
  delay(500); // pause de 500ms
}

