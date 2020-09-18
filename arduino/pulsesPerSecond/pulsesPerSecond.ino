/*********************************/
/******* Pulses per second *******/
/*********************************/
#define SENSOR_PIN_ANALOG A0
#define FRAMES_PER_SECOND 150
#define TIME_FOR_CALC 100
#define CONVERSION_FACTOR 1000/TIME_FOR_CALC

int value = LOW;
int prevValue = value;
int pulses = 0;
int pulsesPerSecond = 0;
unsigned int currentTime;
unsigned int lastCalcPulsesTime = 0;
unsigned int lastPrintTime = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogToDigital(analogRead(SENSOR_PIN_ANALOG));
  if (value != prevValue) {
    prevValue = value;
    pulses++;
  }
  
  currentTime = millis();

  if (currentTime >= (lastCalcPulsesTime + TIME_FOR_CALC)) {
    pulsesPerSecond = pulses * CONVERSION_FACTOR;
    pulses = 0;
    lastCalcPulsesTime = millis();
  }

  if (currentTime > (lastPrintTime + FRAMES_PER_SECOND)) {
    Serial.print(currentTime);
    Serial.print(" - ");
    Serial.println(pulsesPerSecond);
    lastPrintTime = millis();
  }
}

int analogToDigital(int analogValue) {
  return analogValue > 50
    ? HIGH
    : LOW;
}
