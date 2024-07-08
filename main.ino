#include <SoftwareSerial.h>
#include "Arduino.h"

const int transistorPin1 = 3;
const int transistorPin2 = 4;
const int transistorPin3 = 5;

const byte transmit = 13; //tx
const byte receive = 12; //rx

SoftwareSerial BTSerial(receive, transmit); //receive, transmit

void setup() {
  pinMode(transmit, OUTPUT);
  pinMode(receive, INPUT);

  BTSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("\n--------------------");
  Serial.println("Program Start");
  Serial.println("--------------------");

  pinMode(transistorPin1, OUTPUT);
  pinMode(transistorPin2, OUTPUT);
  pinMode(transistorPin3, OUTPUT);

  digitalWrite(transistorPin1, LOW);
  digitalWrite(transistorPin2, LOW);
  digitalWrite(transistorPin3, LOW);
}

String messageBuffer = "";
String message = "";

void loop() {
  while (BTSerial.available() > 0) {
    char data = (char)BTSerial.read();
    Serial.print(data);  // Print each received character for debugging
    messageBuffer += data;
    if (data == ';') {
      // Keep only the last two characters
      if (messageBuffer.length() > 2) {
        message = messageBuffer.substring(messageBuffer.length() - 2);
      } else {
        message = messageBuffer;
      }
      messageBuffer = "";
      Serial.print("\nReceived message: ");
      Serial.println(message);  // Print the full received message
      BTSerial.println("You sent" + message);
      if (message == "1;") {
        digitalWrite(transistorPin1, HIGH);
        Serial.println("firing 1");
        BTSerial.println("firing 1");
        delay(5000);
        digitalWrite(transistorPin1, LOW);
        Serial.println("1 has fired");
        BTSerial.println("1 has fired");
      }
      else if (message == "2;") {
        digitalWrite(transistorPin2, HIGH);
        Serial.println("firing 2");
        BTSerial.println("firing 2");
        delay(5000);
        digitalWrite(transistorPin2, LOW);
        Serial.println("2 has fired");
        BTSerial.println("2 has fired");
      }
      else if (message == "3;") {
        digitalWrite(transistorPin3, HIGH);
        Serial.println("firing 3");
        BTSerial.println("firing 3");
        delay(5000);
        digitalWrite(transistorPin3, LOW);
        Serial.println("3 has fired");
        BTSerial.println("3 has fired");
      }
      message = ""; // Clear the message after processing
    }
  }
}
