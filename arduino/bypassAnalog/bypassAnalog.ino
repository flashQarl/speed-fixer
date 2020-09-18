/*****************************/
/******* Bypass Analog *******/
/*****************************/
#define SENSOR_PIN_ANALOG A0
#define ECU_PIN_PWM_1x 3
#define ECU_PIN_PWM_2x 5 // This PIN is more powerfull

int value;

void setup() {
}

void loop() {
  value = analogRead(SENSOR_PIN_ANALOG) / 4;
  analogWrite(ECU_PIN_PWM_1x, value);
  analogWrite(ECU_PIN_PWM_2x, value);
}
