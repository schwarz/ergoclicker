int pin = A0; // Analog pin with our FSR
int value = 0; // Sensor value
int oldValue = 0; // Previous sensor value

int lower = 900; // Below we hold
int upper = 1000; // Above we release

void setup() {}

void loop() {
  // read the value from the sensor:
  oldValue = value;
  value = analogRead(pin);
  if (value < upper && value >= lower) {
    // neutral
    if (oldValue >= upper) {
      // now neutral, set to unpressed
      Mouse.set_buttons(0, 0, 0);
    }
  } else if (value >= upper) {
    // released
    if (oldValue < upper) {
      Mouse.click();
    }
  } else {
    // held
    Mouse.set_buttons(1, 0, 0);
  }
  // Uncomment for debugging
  //Serial.println(value);
  //delay(1000);
}
