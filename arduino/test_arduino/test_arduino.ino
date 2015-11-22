const int LED_PIN = 3;
const int PAUSE = 500;
byte byteRead;
char* command;

void setup() { 
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  //digitalWrite(LED_PIN, HIGH); // TEST
}


void loop() {
  //digitalWrite(LED_PIN, HIGH);
  //delay(PAUSE);
  //digitalWrite(LED_PIN, LOW);
  //delay(PAUSE);
  
   /*  check if data has been sent from the computer: */
   /*
  if (Serial.available()) {
    // read the most recent byte
    byteRead = Serial.read();
    Serial.println(byteRead);
    digitalWrite(LED_PIN, HIGH);
  }
  */
  
  if(Serial.readBytes(command, 500) == 0){
	*command = NULL;
  }else{
	  char *p = command;
	  char *str;
	// Découpage des commandes
	  while ((str = strtok_r(p, ";", &p)) != NULL){
	   //actions
            digitalWrite(LED_PIN, HIGH);
            Serial.println("hello");
	}
  }
}



