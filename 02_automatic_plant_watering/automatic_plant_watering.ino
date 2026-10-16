// Automatic Plant Watering System
// Soil moisture sensor -> A0
// Relay module -> Pin 7

const int SOIL_PIN = A0;
const int RELAY_PIN = 7;

const int DRY_THRESHOLD = 600;

// Change this if your relay is active-HIGH.
const bool RELAY_ACTIVE_LOW = true;

void controlPump(bool on) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);

  // Pump remains OFF initially.
  controlPump(false);
}

void loop() {
  int moisture = analogRead(SOIL_PIN);

  Serial.print("Soil Moisture Reading: ");
  Serial.println(moisture);

  if (moisture >= DRY_THRESHOLD) {
    Serial.println("Soil is dry. Pump ON");
    controlPump(true);
  } else {
    Serial.println("Soil is moist. Pump OFF");
    controlPump(false);
  }

  delay(2000);
}
