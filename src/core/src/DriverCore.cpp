// ============================================================
// DriverCore.cpp — обёртка над ассемблерными драйверами
// Класс DriverCore вызывает asm_drivers.h из C++.
// DriverCore.cpp — wrapper over assembly drivers
// Class DriverCore calls asm_drivers.h from C++.
// ============================================================

#include "DriverCore.h"           // Объявление класса DriverCore | DriverCore class declaration
#include "core/inc/asm_drivers.h" // Ассемблерные драйверы | Assembly drivers

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// DriverCore::gpioSet — установить пин в 1
// ------------------------------------------------------------
void DriverCore::gpioSet(int pin) { // Установить пин | Set pin
    gpio_set_fast(pin); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// DriverCore::gpioClear — установить пин в 0
// ------------------------------------------------------------
void DriverCore::gpioClear(int pin) { // Очистить пин | Clear pin
    gpio_clear_fast(pin); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// DriverCore::gpioRead — прочитать состояние пина
// ------------------------------------------------------------
int DriverCore::gpioRead(int pin) { // Прочитать пин | Read pin
    return gpio_read_fast(pin); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// DriverCore::spiSendByte — отправить байт по SPI
// ------------------------------------------------------------
void DriverCore::spiSendByte(int data) { // Отправить байт SPI | Send SPI byte
    spi_send_byte_fast(data); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// DriverCore::i2cStart — начать передачу I2C
// ------------------------------------------------------------
void DriverCore::i2cStart() { // Начать I2C | Start I2C
    i2c_start_fast(); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// DriverCore::i2cStop — завершить передачу I2C
// ------------------------------------------------------------
void DriverCore::i2cStop() { // Завершить I2C | Stop I2C
    i2c_stop_fast(); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// DriverCore::i2cWriteByte — записать байт по I2C
// ------------------------------------------------------------
void DriverCore::i2cWriteByte(int data) { // Записать байт I2C | Write I2C byte
    i2c_write_byte_fast(data); // Вызываем ассемблерную функцию | Call assembly function
}

} // Конец namespace core | End of namespace core