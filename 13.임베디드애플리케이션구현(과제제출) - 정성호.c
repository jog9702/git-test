// C++ code
//

int PIN_LED8 = 8;
int PIN_LED9 = 9;
int PIN_LED10 = 10;
int PIN_LED11 = 11;
int PIN_TRIGER = 3;
int PIN_ECHO = 2;

void setup()
{
  pinMode(PIN_LED8, OUTPUT);
  pinMode(PIN_LED9, OUTPUT);
  pinMode(PIN_LED10, OUTPUT);
  pinMode(PIN_LED11, OUTPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
  
  distance = pulseIn(PIN_ECHO, HIGH);

  int cm = distance / 57;
  
  // Serial.println(cm);
  
  if(cm > 200){
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED11, LOW);
  }else if(cm <= 200 && cm > 175){
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED11, HIGH);
  }else if(cm <= 175 && cm > 150){
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED10, HIGH);
    digitalWrite(PIN_LED11, LOW);
  }else if(cm <= 150 && cm > 125){
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED11, LOW);
  }else if(cm <= 125 && cm > 100){
    digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED11, LOW);
  }else{
	digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED10, HIGH);
    digitalWrite(PIN_LED11, HIGH);
  }

}