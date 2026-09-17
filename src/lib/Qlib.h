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
    //void setColor(uint16_t color);
    //void setCursor(int x, int y);
    //void setTextColor(uint16_t color);
    const char* apps[4] = {"None", "None", "None", "Back to Boot"};
};

extern Q q;

#endif