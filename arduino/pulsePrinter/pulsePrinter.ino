/*****************************/
/******* Pulse printer *******/
/*****************************/
#define ON 1
#define OFF 0
#define SENSOR_PIN_ANALOG A0
#define LED_PIN_DIGITAL 13

int value = OFF;
int pulse = value;
unsigned long startOff = 0;
unsigned long startOn = 0;

void setup() {
  pinMode(LED_PIN_DIGITAL, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogToDigital(analogRead(SENSOR_PIN_ANALOG));
  if (value == ON) {
    if (pulse == OFF) {
      pulse = ON;
      startOn = millis();
      printPulseTime(OFF, startOn - startOff);
      digitalWrite(LED_PIN_DIGITAL, ON);
    }
  }
  else if (pulse == ON) {
    pulse = OFF;
    startOff = millis();
    printPulseTime(ON, startOff - startOn);
    digitalWrite(LED_PIN_DIGITAL, OFF);
  }
}

int analogToDigital(int analogValue) {
  return analogValue > 50
    ? HIGH
    : LOW;
}

void printPulseTime(int value, int milliseconds) {
  Serial.print(value);
  Serial.print(" -> ");
  Serial.println(milliseconds);
}
