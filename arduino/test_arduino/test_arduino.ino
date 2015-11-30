const int LED_PIN = 4;
const int PAUSE = 500;
byte byteRead;
char command[500];

void setup() { 
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  //digitalWrite(LED_PIN, HIGH); // TEST
}


void loop() {
  //digitalWrite(LED_PIN, HIGH);
  //delay(PAUSE);
  
  if(Serial.readBytes(command, 500) == 0){
	*command = NULL;
  }else{
	  char *p = command;
	  char *str;
	// Découpage des commandes
	  while ((str = strtok_r(p, ";", &p)) != NULL){
	   //actions
            //digitalWrite(LED_PIN, HIGH);
            
            if(strstr(str, "SET Led ON") > 0) {
              digitalWrite(LED_PIN, HIGH);
              Serial.println("Led On");
            } 
            
            if(strstr(str, "SET Led OFF") > 0) {
              digitalWrite(LED_PIN, LOW);
              //Serial.println("Led On");
            } 
            
            
	}
  }
  

}



