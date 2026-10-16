# ============================================================
# spi.S — ассемблерные функции SPI
# Быстрая отправка байта по SPI через регистры ESP32.
# spi.S — assembly SPI functions
# Fast byte sending over SPI via ESP32 registers.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# spi_send_byte_fast — отправить один байт по SPI
# Вход: a2 = байт для отправки
# Регистры:
#   0x3F000080 — SPI_W0 (данные для отправки)
#   0x3F000024 — SPI_MISO_DLEN (длина данных в битах)
#   0x3F000000 — SPI_CMD (команда: начать передачу)
# ------------------------------------------------------------
	.global spi_send_byte_fast          # Делаем символ глобальным | Make symbol global
	.type spi_send_byte_fast, @function # Тип: функция | Type: function
	
spi_send_byte_fast:                     # Метка функции | Function label
	movi    a3, 0x3F000080        # a3 = адрес регистра SPI_W0 (данные) | a3 = SPI_W0 register address (data)
	s32i    a2, a3, 0             # Записываем байт в SPI_W0 | Write byte to SPI_W0
	movi    a3, 0x3F000024        # a3 = адрес SPI_MISO_DLEN (длина) | a3 = SPI_MISO_DLEN address (length)
	movi    a4, 7                 # a4 = 7 (7 бит = 8 бит минус 1) | a4 = 7 (7 bits = 8 bits minus 1)
	s32i    a4, a3, 0             # Записываем длину (7) | Write length (7)
	movi    a3, 0x3F000000        # a3 = адрес SPI_CMD (команда) | a3 = SPI_CMD address (command)
	movi    a4, 0x00000001        # a4 = 1 (бит USR — начать передачу) | a4 = 1 (USR bit — start transfer)
	s32i    a4, a3, 0             # Запускаем передачу | Start transfer
	ret                           # Возврат | Return
	
	.size spi_send_byte_fast, . - spi_send_byte_fast  # Размер функции | Function size