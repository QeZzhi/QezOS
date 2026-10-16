// ============================================================
// DriverCore.h — заголовок обёртки над ассемблерными драйверами
// Класс DriverCore вызывает asm_drivers.h из C++.
// DriverCore.h — wrapper header over assembly drivers
// Class DriverCore calls asm_drivers.h from C++.
// ============================================================

#ifndef DRIVER_CORE_H // Если DRIVER_CORE_H ещё не определён | If DRIVER_CORE_H is not defined yet
#define DRIVER_CORE_H // Определяем DRIVER_CORE_H | Define DRIVER_CORE_H

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// DriverCore — статический класс-обёртка над asm_drivers.h
// Все методы статические — объект создавать не надо
// ------------------------------------------------------------
class DriverCore { // Класс DriverCore | Class DriverCore
public: // Публичные методы | Public methods
    
    // --------------------------------------------------------
    // GPIO — управление пинами (вход/выход)
    // --------------------------------------------------------
    
    // Установить пин в 1 (высокий уровень) | Set pin to 1 (high)
    static void gpioSet(int pin);
    
    // Установить пин в 0 (низкий уровень) | Set pin to 0 (low)
    static void gpioClear(int pin);
    
    // Прочитать состояние пина | Read pin state
    static int  gpioRead(int pin);
    
    // --------------------------------------------------------
    // SPI — последовательный интерфейс (для дисплея, SD)
    // --------------------------------------------------------
    
    // Отправить один байт по SPI | Send one byte over SPI
    static void spiSendByte(int data);
    
    // --------------------------------------------------------
    // I2C — двухпроводной интерфейс (для датчиков, RTC)
    // --------------------------------------------------------
    
    // Начать передачу I2C | Start I2C transmission
    static void i2cStart();
    
    // Завершить передачу I2C | Stop I2C transmission
    static void i2cStop();
    
    // Записать один байт по I2C | Write one byte over I2C
    static void i2cWriteByte(int data);
};

} // Конец namespace core | End of namespace core

#endif // Конец include guard | End of include guard