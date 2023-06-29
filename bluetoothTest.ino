//Define the variable that contains the led
#define ledPin 7
int state = 0;
void setup() {
  //Setting the pin mode and initial LOW
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate
}
void loop() {
  // Checks if the data is coming from the serial port
  if(Serial.available() > 0){
    state = Serial.read(); // Read the data from the serial port
 }
 Deciding functions for LED on and off
 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  // Send back, to the phone, the String "LED: ON"
  Serial.println("LED: OFF");
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 }
}
