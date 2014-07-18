#ifndef LEDBUT_H_
#define LEDBUT_H_

#define LED 13
#define BUT 8

void initLedBut();
void cmdLed(char *msg);
void cmdBut(char *msg);
void procBut();

#endif /* LEDBUT_H_ */
