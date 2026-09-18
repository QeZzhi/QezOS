#ifndef DRIVER_CORE_H
#define DRIVER_CORE_H

namespace core {

class DriverCore {
public:
    static void gpioSet(int pin);
    static void gpioClear(int pin);
    static int  gpioRead(int pin);
    
    static void spiSendByte(int data);
    
    static void i2cStart();
    static void i2cStop();
    static void i2cWriteByte(int data);
};

}

#endif