const int LED_PIN1 = 2;
const int LED_PIN2 = 3;
const int PAUSE = 500;
byte byteRead;
char command[500];

void setup() { 
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_PIN1, HIGH); // TEST
  digitalWrite(LED_PIN2, HIGH); // TEST
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
            
            if(strstr(str, "SET Led1 ON") > 0) {
              digitalWrite(LED_PIN1, HIGH);
              Serial.println("Led On");
            } 
            
            if(strstr(str, "SET Led1 OFF") > 0) {
              digitalWrite(LED_PIN1, LOW);
              //Serial.println("Led On");
            } 
            
            if(strstr(str, "SET Led2 ON") > 0) {
              digitalWrite(LED_PIN2, HIGH);
              Serial.println("Led On");
            } 
            
            if(strstr(str, "SET Led2 OFF") > 0) {
              digitalWrite(LED_PIN2, LOW);
              //Serial.println("Led On");
            } 
            
            
	}
  }
    

}



