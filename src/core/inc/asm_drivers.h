// ============================================================
// asm_drivers.h — заголовок ассемблерных драйверов
// Быстрые функции для GPIO, SPI и I2C (написаны на .S).
// asm_drivers.h — assembly drivers header
// Fast functions for GPIO, SPI and I2C (written in .S).
// ============================================================

#ifndef ASM_DRIVERS_H // Если ASM_DRIVERS_H ещё не определён | If ASM_DRIVERS_H is not defined yet
#define ASM_DRIVERS_H // Определяем ASM_DRIVERS_H | Define ASM_DRIVERS_H

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
extern "C" { // Отключаем искажение имён | Disable name mangling
#endif

// ------------------------------------------------------------
// GPIO — управление пинами (вход/выход)
// ------------------------------------------------------------

// Установить пин в 1 (высокий уровень) | Set pin to 1 (high)
void gpio_set_fast(int pin);

// Установить пин в 0 (низкий уровень) | Set pin to 0 (low)
void gpio_clear_fast(int pin);

// Прочитать состояние пина | Read pin state
int gpio_read_fast(int pin);

// ------------------------------------------------------------
// SPI — последовательный интерфейс (для дисплея, SD-карты)
// ------------------------------------------------------------

// Отправить один байт по SPI | Send one byte over SPI
void spi_send_byte_fast(int data);

// ------------------------------------------------------------
// I2C — двухпроводной интерфейс (для датчиков, RTC)
// ------------------------------------------------------------

// Начать передачу I2C | Start I2C transmission
void i2c_start_fast(void);

// Завершить передачу I2C | Stop I2C transmission
void i2c_stop_fast(void);

// Записать один байт по I2C | Write one byte over I2C
void i2c_write_byte_fast(int data);

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
} // Закрываем extern "C" | Close extern "C"
#endif

#endif // Конец include guard | End of include guard