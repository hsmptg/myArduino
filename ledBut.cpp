// Must add the .h file of the main project (Ard.h)
#include "main.h"

int but;

void initLedBut() {
	pinMode(BUT, INPUT);
	digitalWrite(BUT, HIGH);
	but = digitalRead(BUT);

	pinMode(LED, OUTPUT);
	digitalWrite(LED, LOW);
}

void cmdLed(char *msg) {
	if (msg[1] == '1') {
		digitalWrite(LED, HIGH);
	}
	else {
		digitalWrite(LED, LOW);
	}
}

void cmdBut(char *msg) {
	if (!but)
		Serial.print("BUT ON\n");
	else
		Serial.print("BUT OFF\n");
}

void procBut() {
	int b = digitalRead(BUT);
	if (b != but) {
		but = b;
		Serial.print((!but) ? "BUT oN\n" : "BUT oFF\n");
	}
}
