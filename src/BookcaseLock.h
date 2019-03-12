#ifndef BOOKCASE_LOCK_H
#define BOOKCASE_LOCK_H

#include "Arduino.h"

class BookcaseLock {
public:
    BookcaseLock();
    BookcaseLock(uint32_t timeout);
    virtual ~BookcaseLock();
    void Unlock();
    void UpdateState();

private:
    enum LockState {
        Opening = 1,
        Open = 2,
        Closing = 3,
        Closed = 4
    };
    static const uint8_t led_pin = 1;
    static const uint8_t lock_pin = 3;
    uint64_t lastStateChangeTime = 0;
    uint32_t lockOpenTimeout = 1200;
    LockState lockState = Closed;

    void OpenLock();
    void CloseLock();
};


#endif //BOOKCASE_LOCK_H
