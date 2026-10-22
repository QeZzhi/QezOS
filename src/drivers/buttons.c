#include "buttons.h"
#include "m5_shim/m5_shim.h"

int getButtonPress(void) {
    if (qz_btn_a_wasPressed()) return BUTTON_A;
    if (qz_btn_b_wasPressed()) return BUTTON_B;
    return BUTTON_NONE;
}