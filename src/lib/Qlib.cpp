#include <M5Unified.h>
#include "Qlib.h"
#include <iostream>
#include "drivers/display.h"

void Q::wait(int time) {
    delay(time);
}

void Q::print(const char *text) {
     q.println(text);
}

void Q::println(const char *text) {
    q.println(text);
}

Q q;