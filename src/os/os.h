// ============================================================
// os.h — заголовок логики загрузки QezOS
// Объявляет три функции загрузки: Standard, Advanced, Secure.
// os.h — QezOS boot logic header
// Declares three boot functions: Standard, Advanced, Secure.
// ============================================================

#pragma once // Включить этот файл только один раз | Include this file only once

// ------------------------------------------------------------
// Три режима загрузки QezOS
// Каждая функция показывает экран загрузки и запускает меню
// ------------------------------------------------------------

// Стандартная загрузка | Standard boot
void StandartBoot();

// Расширенная загрузка | Advanced boot
void AdvancedOptionsBoot();

// Безопасная загрузка | Secure boot
void SecureBoot();