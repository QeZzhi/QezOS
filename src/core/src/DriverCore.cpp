#include "DriverCore.h"
#include "core/inc/asm_drivers.h"

namespace core {

void DriverCore::gpioSet(int pin) {
    gpio_set_fast(pin);
}

void DriverCore::gpioClear(int pin) {
    gpio_clear_fast(pin);
}

int DriverCore::gpioRead(int pin) {
    return gpio_read_fast(pin);
}

void DriverCore::spiSendByte(int data) {
    spi_send_byte_fast(data);
}

void DriverCore::i2cStart() {
    i2c_start_fast();
}

void DriverCore::i2cStop() {
    i2c_stop_fast();
}

void DriverCore::i2cWriteByte(int data) {
    i2c_write_byte_fast(data);
}

}