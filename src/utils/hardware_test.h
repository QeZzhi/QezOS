// ============================================================
// hardware_test.h — заголовок теста железа QezOS
// Объявляет функции для проверки экрана, кнопок, звука, памяти.
// hardware_test.h — QezOS hardware test header
// Declares functions for checking screen, buttons, sound, memory.
// ============================================================

#pragma once // Включить этот файл только один раз | Include this file only once

// ------------------------------------------------------------
// runHardwareTest — запустить все тесты по очереди
// Вызывает testScreen, testButtons, testSound, testMemory
// ------------------------------------------------------------
void runHardwareTest(); // Запуск всех тестов | Run all tests

// ------------------------------------------------------------
// Отдельные тесты
// ------------------------------------------------------------

// Тест экрана (заливка цветами) | Screen test (fill with colors)
void testScreen();

// Тест кнопок (просит нажать A и B) | Button test (asks to press A and B)
void testButtons();

// Тест звука (проигрывает тона) | Sound test (plays tones)
void testSound();

// Тест памяти (RAM и Flash) | Memory test (RAM and Flash)
void testMemory();