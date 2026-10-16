# ============================================================
# i2c.S — ассемблерные функции I2C
# Быстрое управление I2C через регистры ESP32.
# i2c.S — assembly I2C functions
# Fast I2C control via ESP32 registers.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# i2c_start_fast — начать передачу I2C (START condition)
# Регистр 0x60013004 — I2C_COMMAND
# Бит 0 — START
# ------------------------------------------------------------
	.global i2c_start_fast          # Делаем символ глобальным | Make symbol global
	.type i2c_start_fast, @function # Тип: функция | Type: function
	
i2c_start_fast:                     # Метка функции | Function label
	movi    a2, 0x60013004        # a2 = адрес регистра команд I2C | a2 = I2C command register address
	movi    a3, 0x00000001        # a3 = 1 (бит START) | a3 = 1 (START bit)
	s32i    a3, a2, 0             # Записываем 1 в регистр (START) | Write 1 to register (START)
	ret                           # Возврат | Return
	
	.size i2c_start_fast, . - i2c_start_fast  # Размер функции | Function size

# ------------------------------------------------------------
# i2c_stop_fast — завершить передачу I2C (STOP condition)
# Регистр 0x60013004 — I2C_COMMAND
# Бит 1 — STOP
# ------------------------------------------------------------
	.align 4
	.global i2c_stop_fast          # Делаем символ глобальным | Make symbol global
	.type i2c_stop_fast, @function # Тип: функция | Type: function
	
i2c_stop_fast:                     # Метка функции | Function label
	movi    a2, 0x60013004        # a2 = адрес регистра команд I2C | a2 = I2C command register address
	movi    a3, 0x00000002        # a3 = 2 (бит STOP) | a3 = 2 (STOP bit)
	s32i    a3, a2, 0             # Записываем 2 в регистр (STOP) | Write 2 to register (STOP)
	ret                           # Возврат | Return
	
	.size i2c_stop_fast, . - i2c_stop_fast  # Размер функции | Function size

# ------------------------------------------------------------
# i2c_write_byte_fast — записать байт по I2C
# Вход: a2 = байт для записи
# Регистр 0x6001301C — I2C_DATA (данные)
# Регистр 0x60013004 — I2C_COMMAND (команда)
# Бит 2 — WRITE
# ------------------------------------------------------------
	.align 4
	.global i2c_write_byte_fast          # Делаем символ глобальным | Make symbol global
	.type i2c_write_byte_fast, @function # Тип: функция | Type: function
	
i2c_write_byte_fast:                     # Метка функции | Function label
	movi    a3, 0x6001301C        # a3 = адрес регистра данных I2C | a3 = I2C data register address
	s32i    a2, a3, 0             # Записываем байт в регистр данных | Write byte to data register
	movi    a3, 0x60013004        # a3 = адрес регистра команд I2C | a3 = I2C command register address
	movi    a4, 0x00000004        # a4 = 4 (бит WRITE) | a4 = 4 (WRITE bit)
	ret                           # Возврат | Return
	
	.size i2c_write_byte_fast, . - i2c_write_byte_fast  # Размер функции | Function size