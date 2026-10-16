# ============================================================
# gpio.S — ассемблерные функции управления GPIO (пинами)
# Быстрое управление пинами через регистры ESP32.
# gpio.S — assembly GPIO (pin) control functions
# Fast pin control via ESP32 registers.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# gpio_set_fast — установить пин в 1 (высокий уровень)
# Вход: a2 = номер пина
# Регистр 0x60004008 — W1TS (Write 1 To Set)
# ------------------------------------------------------------
	.global gpio_set_fast          # Делаем символ глобальным | Make symbol global
	.type gpio_set_fast, @function # Тип: функция | Type: function
	
gpio_set_fast:                     # Метка функции | Function label
	movi    a3, 0x60004008        # a3 = адрес регистра W1TS | a3 = W1TS register address
	movi    a4, 1                 # a4 = 1 (бит для установки) | a4 = 1 (bit to set)
	ssl     a2                    # Устанавливаем shift amount = pin | Set shift amount = pin
	sll     a4, a4                # a4 = 1 << pin (сдвигаем бит) | a4 = 1 << pin (shift bit)
	s32i    a4, a3, 0             # Записываем a4 в регистр (устанавливаем пин) | Write a4 to register (set pin)
	ret                           # Возврат | Return
	
	.size gpio_set_fast, . - gpio_set_fast  # Размер функции | Function size

# ------------------------------------------------------------
# gpio_clear_fast — установить пин в 0 (низкий уровень)
# Вход: a2 = номер пина
# Регистр 0x6000400C — W1TC (Write 1 To Clear)
# ------------------------------------------------------------
	.align 4
	.global gpio_clear_fast          # Делаем символ глобальным | Make symbol global
	.type gpio_clear_fast, @function # Тип: функция | Type: function
	
gpio_clear_fast:                     # Метка функции | Function label
	movi    a3, 0x6000400C        # a3 = адрес регистра W1TC | a3 = W1TC register address
	movi    a4, 1                 # a4 = 1 | a4 = 1
	ssl     a2                    # shift amount = pin | shift amount = pin
	sll     a4, a4                # a4 = 1 << pin | a4 = 1 << pin
	s32i    a4, a3, 0             # Записываем в регистр (очищаем пин) | Write to register (clear pin)
	ret                           # Возврат | Return
	
	.size gpio_clear_fast, . - gpio_clear_fast  # Размер функции | Function size

# ------------------------------------------------------------
# gpio_read_fast — прочитать состояние пина
# Вход: a2 = номер пина
# Выход: a2 = 0 или 1
# Регистр 0x6000403C — GPIO_IN (вход)
# ------------------------------------------------------------
	.align 4
	.global gpio_read_fast          # Делаем символ глобальным | Make symbol global
	.type gpio_read_fast, @function # Тип: функция | Type: function
	
gpio_read_fast:                     # Метка функции | Function label
	movi    a3, 0x6000403C        # a3 = адрес регистра GPIO_IN | a3 = GPIO_IN register address
	l32i    a4, a3, 0             # a4 = значение всех пинов | a4 = value of all pins
	movi    a5, 1                 # a5 = 1 | a5 = 1
	ssl     a2                    # shift amount = pin | shift amount = pin
	sll     a5, a5                # a5 = 1 << pin (маска пина) | a5 = 1 << pin (pin mask)
	and     a2, a4, a5            # a2 = a4 & a5 (выделяем бит) | a2 = a4 & a5 (extract bit)
	ret                           # Возврат | Return
	
	.size gpio_read_fast, . - gpio_read_fast  # Размер функции | Function size