// Do not remove the include below
#include "main.h"

void setup() {
	initLedBut();

	Serial.begin(115200);
	Serial.println("ButLed v1.0");
}

#define CMD_SIZE 10

char *getMsg(void) {
	int c;
	int static index;
	char static cmd[CMD_SIZE+1];

	if ((c = Serial.read()) != -1) {
		if (index && ((char) c == '\r')) {
			cmd[index] = '\0';
			index = 0;
			return cmd;
		}
		else {
			if (index < CMD_SIZE)
				cmd[index++] = (char) c;
			return 0;
		}
	}
	return 0;
}

void procMsg(char *msg) {
	switch(msg[0]) {
		case 'l':
			cmdLed(msg);
			break;
		case 'b':
			cmdBut(msg);
			break;
	}
}

void loop() {
	char *msg;
	if ((msg = getMsg()) != 0) {
		procMsg(msg);
	}

	procBut();
}
