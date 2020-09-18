/******************************/
/******* Bypass Digital *******/
/******************************/
#define SENSOR_PIN_DIGITAL 2
#define ECU_PIN_DIGITAL 4

int value = 0;

void setup() {
  pinMode(SENSOR_PIN_DIGITAL, INPUT);
  pinMode(ECU_PIN_DIGITAL, OUTPUT);
}

void loop() {
  value = digitalRead(SENSOR_PIN_DIGITAL);
  digitalWrite(ECU_PIN_DIGITAL, value);
}
