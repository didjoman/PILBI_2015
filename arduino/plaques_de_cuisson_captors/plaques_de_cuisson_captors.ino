/* Constante */
const int consoleOutput = 9600;

/* Bouton poussoir */
const int buttonPin = 2;  // Port digital 2
int buttonState = 0;      // Etat courant du bouton

/* Led */
const int ledPin = 11;    // Port digital 11
const int ALARM_HOTEPLATE_LED_PIN = 8; // Port digital 8
bool ledState = false;    // Etat courant de la led

/* Capteur de pression */
const int panPin = A0;
int panValue;
bool isWeighted = false;

/* Dernier état envoyé */
bool lastState[] = {false, false};

/* Variables globales */
char command[500];
int turn = 0;

/* Initialize console output */
void initOutput() {
  Serial.begin(consoleOutput);
}

/* Initialize pins states */
void initPins() {
  pinMode(ledPin, OUTPUT);
  pinMode(ALARM_HOTEPLATE_LED_PIN, OUTPUT);
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

  /* Weight */
  panValue = analogRead(panPin);
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
  
  /* Receive commands */
  if(turn == 3) {
    turn = 0;
    if(Serial.readBytes(command, 10) == 0) {
  	  *command = NULL;
    } else{
  	  char *p = command;
  	  char *str;
  	  // Découpage des commandes
  	  while ((str = strtok_r(p, ";", &p)) != NULL){
  	    //actions
        //digitalWrite(LED_PIN, HIGH);
        
        if(strstr(str, "SET AlarmHotplateLed ON") > 0) {
          digitalWrite(ALARM_HOTEPLATE_LED_PIN, HIGH);
          Serial.println("AlarmHotplateLed On");
        } 
        
        if(strstr(str, "SET AlarmHotplateLed OFF") > 0) {
          digitalWrite(ALARM_HOTEPLATE_LED_PIN, LOW);
          Serial.println("AlarmHotplateLed Off");
        }          
      
        if(strstr(str, "SET HotplateLed ON") > 0) {
          digitalWrite(ledPin, HIGH);
          Serial.println("HotplateLed On");
        } 
        
        if(strstr(str, "SET HotplateLed OFF") > 0) {
          digitalWrite(ledPin, LOW);
          Serial.println("HotplateLed Off");
        }
  	  } // end while
    } // end if readBytes
  } else {
    turn++;
    delay(200);
  }
}

