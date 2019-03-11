#include "BookcaseLock.h"


BookcaseLock::BookcaseLock()
{
    pinMode(led_pin, OUTPUT);
    pinMode(lock_pin, OUTPUT);
}


BookcaseLock::~BookcaseLock() { }


void BookcaseLock::Unlock()
{
    if (lockState != Open)
        lockState = Opening;
}


void BookcaseLock::UpdateState()
{
    switch(lockState)
    {
        case Opening: {
            lastStateChangeTime = millis();
            lockState = Open;
            break;
        }
        case Open: {
            OpenLock();
            if (millis() - lastStateChangeTime > 2000)
                lockState = Closing;
            break;
        }
        case Closing: {
            CloseLock();
            lastStateChangeTime = 0;
            break;
        }
        case Closed: break;
    }
}


void BookcaseLock::OpenLock()
{
    digitalWrite(lock_pin, HIGH);
    digitalWrite(led_pin, HIGH);
}


void BookcaseLock::CloseLock()
{
    digitalWrite(lock_pin, LOW);
    digitalWrite(led_pin, LOW);
}
