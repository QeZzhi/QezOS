#include <M5Unified.h>
#include "drivers/display.h"
#include <drivers/buttons.h>
#include "lib/Qlib.h"

    void RunStandartMenu() 
    {
        clear();
        M5.Lcd.setTextColor(TFT_CYAN);
        M5.Lcd.setCursor(20, 50);
        q.println("|-----Apps Menu-----|");
        q.println("| ");
        delay(2000);
    }
