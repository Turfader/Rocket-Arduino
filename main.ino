// The main file that the arduino will run off of. Keep this file clean. Don't push anything broken to this file plz. Leave comments plz.

#define LED 12
#define SAFETY_OUT 8
#define SAFETY_IN 7

void setup()
{
	Serial.begin(9600);
 	Serial.println();
	pinMode(LED, OUTPUT);
 	pinMode(SAFETY_OUT, OUTPUT);
	pinMode(SAFETY_IN, INPUT);
}

void loop()
{
  // Safety system. Do not break. Am thinking of changing to a while loop for extra security. 
  //Anyway, as long as there is a wire connecting pins 7 and 8, nothing should happen.
	digitalWrite(LED, HIGH);
	digitalWrite(SAFETY_OUT, HIGH);
  	if(digitalRead(SAFETY_IN) == LOW)
    {
      Serial.println("SAFETY OFF");
      digitalWrite(LED, LOW);
    }
  	else
    {
      Serial.println("SAFETY ON");
    }
  	delay(100);
}
