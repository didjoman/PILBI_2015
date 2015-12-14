/* Constante */
const int consoleOutput = 9600;

/* Bouton poussoir */
const int buttonPin = 2;  // Port digital 2
int buttonState = 0;      // Etat courant du bouton

/* Led */
const int ledPin = 13;    // Port digital 13
bool ledState = false;    // Etat courant de la led

/* Capteur de pression */
const int panPin = A0;
int panValue;
bool isWeighted = false;

/* Dernier état envoyé */
bool lastState[] = {false, false};

/* Initialize console output */
void initOutput() {
  Serial.begin(consoleOutput);
}

/* Initialize pins states */
void initPins() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
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
  /* On - Off */
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH) {
    if(ledState) {
      digitalWrite(ledPin, LOW);
      ledState = false;
    } else {
      digitalWrite(ledPin, HIGH);
      ledState = true;
    }
  }

  /* Weight */
  panValue = analogRead(panPin);
  /*Serial.print("poids : ");
  Serial.println(panValue);*/
  if(panValue > 0) {
    isWeighted = true;
  } else {
    isWeighted = false;
  }

  /* Send information */
  if(ledState && isWeighted != lastState[1]) {
    if(isWeighted) {
      Serial.println("HotWithPan");
    } else {
      Serial.println("HotWithoutPan");
    }
  }
  
  /* Update current state */
  lastState[0] = ledState;
  lastState[1] = isWeighted;

  delay(250);
}

