#include "Arduino.h"
#include "BookcaseLock.h"

BookcaseLock lock;
static const uint8_t key_pin = 2;


void setup()
{
    lock = BookcaseLock();
    pinMode(key_pin, INPUT);
}


void loop()
{
    if (digitalRead(key_pin) == HIGH)
        lock.Unlock();

    lock.UpdateState();
}
