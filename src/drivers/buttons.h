#ifndef BUTTONS_H
#define BUTTONS_H

#ifdef __cplusplus
extern "C" {
#endif

// Определяем константы для кнопок, чтобы не использовать магические числа
#define BUTTON_NONE 0
#define BUTTON_A    1
#define BUTTON_B    2

// Функция опроса кнопок. Возвращает нажатую кнопку или BUTTON_NONE
int getButtonPress(void);

#ifdef __cplusplus
}
#endif

#endif // BUTTONS_H