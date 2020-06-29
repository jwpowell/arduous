
int pwm_pin2 = 2;

// The PWM duty cycle (0: 0%, 256: 100%)
int level = 0;

// Amount to change level per loop
// When delta == 1, we're increasing brightness. When delta == -1, we're decreasing brightness
int delta = 1;

void setup() {
  // no setup 
}

void loop() {
  analogWrite(pwm_pin2, level);

  level += delta;

  // If we hit the top or bottom, change directions
  if (level >= 256) {
    delta = -1;
    level = 255;
  } else if (level <= 0) {
    delta = 1;
    level = 0;
  }

  // run the loop every 5 milliseconds. That means we get through a full LED brightness
  // cycle in (256 * 2 * 5) = 2560 miliseoconds. Roughly.
  delay(5);
}
