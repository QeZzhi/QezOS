#ifndef QLIB_H
#define QLIB_H
#include <string>
#include <M5Unified.h>

class Q {
public:
    void wait(int time);
    void print(const char* text);
    void println(const char* text);
    bool boot_select[3];
};

extern Q q;

#endif