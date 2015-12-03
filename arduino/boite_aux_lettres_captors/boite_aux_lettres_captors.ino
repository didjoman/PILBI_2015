/* --------------- Capteur Ultrason --------------- */
int trig = 12;  // Digital 12
int echo = 11;  // Digital 11
long lecture_echo;
long cm;

/* --------------- Capteur de contact --------------- */
/* Accrocher le détecteur au port analogique A0 */
int contact_sensor = 0; // A0
boolean detect_close_door = 0;

/* --------------- Photo resistance --------------- */
const char photo_resistance = 1;
int photo_resistance_value;

/* Constante */
int consoleOutput = 9600;

/* Variable globale */
bool getHauteur = false;

/* Initialize pins states */
void initPins() {
  pinMode(contact_sensor, INPUT);
  pinMode(photo_resistance,OUTPUT);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
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
}

/* Code executed in a loop */
void loop() 
{
  /* Capteur de contact : porte boite aux lettres */
  if(analogRead(A0) == 0) {
    /* Porte ouverte */
    detect_close_door = true;
  }
  if(detect_close_door && analogRead(A0) != 0) {
    /* Porte fermée */
    detect_close_door = false;
    Serial.println("porte");
    getHauteur = true;
  }
  
  /* Photoresistance */
  photo_resistance_value = analogRead(photo_resistance);  
  //Serial.print(photo_resistance_value);
  if (photo_resistance_value < 800) {
    //Serial.println(" - Noir");   
  } else {
    //Serial.println(" - lumineux");  
  }

  /* Capteur Ultrason */
  if(getHauteur) {
    getHauteur = false;
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    lecture_echo = pulseIn(echo, HIGH);
    cm = lecture_echo /100;
    Serial.print("Distance en cm : ");
    Serial.println(cm);
  }

  delay(1000);
}
