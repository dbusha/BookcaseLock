int led_pin = 1;
int magnet_sensor = 2;
int lock_pin = 3;
unsigned long ellapsed = 0;
unsigned long startTime = 0;
int state = LOW;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(magnet_sensor, INPUT);
  pinMode(lock_pin, OUTPUT);
}

void loop() {
  if (startTime == 0 && digitalRead(magnet_sensor) == state) {
    digitalWrite(lock_pin, HIGH);
    digitalWrite(led_pin, HIGH);
    startTime = millis();
    state = state == HIGH ? LOW : HIGH;
  }
  if (startTime > 0 && ellapsed <= 1500) {
    ellapsed = millis() - startTime;
    digitalWrite(lock_pin, HIGH);
    digitalWrite(led_pin, HIGH);
  }
  if (startTime == 0 || ellapsed > 1500) {
    ellapsed = 0;
    startTime = 0;
    digitalWrite(lock_pin, LOW);
    digitalWrite(led_pin, LOW);
  }
}
