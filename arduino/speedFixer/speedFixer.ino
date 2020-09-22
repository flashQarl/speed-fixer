#define HALL_PIN_DIGITAL 2
#define ECU_PIN_DIGITAL 4

volatile unsigned long interruptTime = 0;
unsigned long lastInterruptTime = 0;
unsigned long previousInterruptTime = 0;

unsigned long pulseStartTime = 0;
unsigned long pulseWidth = 0;

bool value = false;

void setup() {
  attachInterrupt(digitalPinToInterrupt(HALL_PIN_DIGITAL), hallPinChanged, CHANGE);
}

void loop() {
  if(micros() > pulseStartTime + getCurrentPulseWidth()) {
     value = !value;
     digitalWrite(ECU_PIN_DIGITAL, value);
  }
}

void hallPinChanged() {
  interruptTime = micros();
}

unsigned long getCurrentPulseWidth() {
  previousInterruptTime = lastInterruptTime;
  
  noInterrupts();
  lastInterruptTime = interruptTime;
  interrupts();

  if (previousInterruptTime != lastInterruptTime) {
    pulseWidth = lastInterruptTime - previousInterruptTime;
  }
  
  return pulseWidth;
}
