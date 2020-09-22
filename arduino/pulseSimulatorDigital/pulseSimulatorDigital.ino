/***************************************/
/******* Pulse simulator digital *******/
/***************************************/
#define ON 1
#define OFF 0
#define ECU_PIN_DIGITAL 4

bool value = OFF;

void setup() {
  pinMode(ECU_PIN_DIGITAL, OUTPUT);
}

void loop() {
  value = !value;
  digitalWrite(ECU_PIN_DIGITAL, value);
  delayMicroseconds(50);
}
