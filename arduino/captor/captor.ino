

const int captor_input = 0;
int val;

void setup() 
{
  Serial.begin(9600);
  pinMode(captor_input, INPUT); 
  
}


void loop() 
{
  val = analogRead(captor_input);
  Serial.println(val); 
 delay(200);
  
}
