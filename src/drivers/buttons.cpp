#include "buttons.h"
#include <M5Unified.h>

int getButtonPress() {
    M5.update();
    if (M5.BtnA.wasPressed()) return BUTTON_A;
    if (M5.BtnB.wasPressed()) return BUTTON_B;
    return BUTTON_NONE;
}
