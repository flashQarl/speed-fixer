/*******************************/
/******* Pulse simulator *******/
/*******************************/
#define ON 1
#define OFF 0
#define OFF_ANALOG 0
#define ON_ANALOG 100
#define ECU_PIN_PWM_1x 3
#define ECU_PIN_PWM_2x 5 // This PIN is more powerfull
#define LED_PIN_DIGITAL 13
#define PULSE_WIDTH 100

int value = OFF;

void setup() {
  pinMode(LED_PIN_DIGITAL, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = !value;
  if (value == OFF) {
    writeAnalogOutputs(OFF_ANALOG);
    digitalWrite(LED_PIN_DIGITAL, ON);
  }
  else {
    writeAnalogOutputs(ON_ANALOG);
    digitalWrite(LED_PIN_DIGITAL, OFF);
  }

  Serial.print(value);
  Serial.print(" -> ");
  Serial.println(millis());
  delay(PULSE_WIDTH);
}

void writeAnalogOutputs(int value) {
  analogWrite(ECU_PIN_PWM_1x, value);
  analogWrite(ECU_PIN_PWM_2x, value);
}
