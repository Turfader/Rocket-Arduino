// C++ code
//

#define LED_SAFETY 12
#define SAFETY_OUT 8
#define SAFETY_IN 7

#define LED_SWITCH 11
#define SWITCH_OUT 6
#define SWITCH_IN 5

#define LED_READY_TO_FIRE 0

void setup()
{
	Serial.begin(9600);
 	Serial.println();
	pinMode(LED_SAFETY, OUTPUT);
 	pinMode(SAFETY_OUT, OUTPUT);
	pinMode(SAFETY_IN, INPUT);
  
  	pinMode(LED_SWITCH, OUTPUT);
  	pinMode(SWITCH_OUT, OUTPUT);
  	pinMode(SWITCH_IN, INPUT);
  
  	pinMode(LED_READY_TO_FIRE, OUTPUT);
}

void loop()
{
	digitalWrite(LED_SAFETY, HIGH);
	digitalWrite(SAFETY_OUT, HIGH);
  
  	digitalWrite(LED_SWITCH, HIGH);
    digitalWrite(SWITCH_OUT, HIGH);
  
  	digitalWrite(LED_READY_TO_FIRE, LOW);
  	
  	if(!digitalRead(SAFETY_IN) == LOW)
    {
    	Serial.println("SAFETY ON");
      	delay(100);
      	return;
    }
 	Serial.println("SAFETY OFF");
	digitalWrite(LED_SAFETY, LOW);
	
  	if(!digitalRead(SWITCH_IN) == LOW)
    {
    	Serial.println("SWITCH OFF");
    	delay(100);
      	return;
    }
  	Serial.println("SWITCH ON");
  	digitalWrite(LED_SWITCH, LOW);
  
    delay(100);
}
