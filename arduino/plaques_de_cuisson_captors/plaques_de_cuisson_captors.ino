/* Constante */
const int consoleOutput = 9600;

/* Bouton poussoir */
const int buttonPin = 2;  // Port digital 2
int buttonState = 0;      // Etat courant du bouton

/* Led */
const int ledPin = 13;    // Port digital 13
bool ledState = false;    // Etat courant de la led

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
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if(buttonState == HIGH) {
    if(ledState) {
      digitalWrite(ledPin, LOW);
      ledState = false;
    } else {
      digitalWrite(ledPin, HIGH);
      ledState = true;
    }
  }

  delay(250);
}

