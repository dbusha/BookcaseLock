int led_pin = 1;
int magnet_sensor = 2;
int lock_pin = 3;
int state = HIGH;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(magnet_sensor, INPUT);
  pinMode(lock_pin, OUTPUT);
}

void loop() {
  int sensor = digitalRead(magnet_sensor);
  if (sensor != state) {
    digitalWrite(lock_pin, HIGH);
    digitalWrite(led_pin, HIGH);
    state = sensor;
    delay(2000);
  }
  else {
    digitalWrite(lock_pin, LOW);
    digitalWrite(led_pin, LOW);
  }
}
