#ifndef ASM_DRIVERS_H
#define ASM_DRIVERS_H

#ifdef __cplusplus
extern "C" {
#endif

// GPIO
void gpio_set_fast(int pin);
void gpio_clear_fast(int pin);
int  gpio_read_fast(int pin);

// SPI
void spi_send_byte_fast(int data);

// I2C
void i2c_start_fast(void);
void i2c_stop_fast(void);
void i2c_write_byte_fast(int data);

#ifdef __cplusplus
}
#endif

#endif