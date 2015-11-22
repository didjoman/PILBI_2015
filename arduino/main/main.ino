

const int captor_input = 6;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(captor_input, INPUT); 
  
}


void loop() {
  val = digitalRead(captor_input);
  Serial.print(val);  
  
}
