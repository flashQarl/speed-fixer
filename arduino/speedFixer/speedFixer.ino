#define HALL_PIN_DIGITAL 2
#define ECU_PIN_DIGITAL 4

volatile unsigned long interruptTime = 0;
unsigned long lastInterruptTime = 0;
unsigned long previousInterruptTime = 0;
unsigned long timeOfLastCommunication = 0;
unsigned long pulseWidth = 0;
bool value = false;

void setup() {
  attachInterrupt(digitalPinToInterrupt(HALL_PIN_DIGITAL), hallPinChanged, CHANGE);
}

void loop() {
  previousInterruptTime = lastInterruptTime;
  noInterrupts();
  lastInterruptTime = interruptTime;
  interrupts();

  if (tryToUpdatePulseWidth(previousInterruptTime, lastInterruptTime, &pulseWidth) &&
      micros() > timeOfLastCommunication + pulseWidth) {
    value = !value;
    sendValueToECU(value, &timeOfLastCommunication);
  }
}

void hallPinChanged() {
  interruptTime = micros();
}

bool tryToUpdatePulseWidth(unsigned long start, unsigned long finish, unsigned long *pulseWidth) {
  if (start == finish) {
    return false;
  }

  *pulseWidth = finish - start;
  return true;
}

void sendValueToECU(bool value, unsigned long *communicationTime) {
  *communicationTime = micros();
  digitalWrite(ECU_PIN_DIGITAL, value);
}
