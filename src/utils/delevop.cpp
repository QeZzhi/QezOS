#include <M5Unifed>
#include "lib/Qlib.h"
#include "delevop.h"

void delevop() {
    q.println("This function in delevop...");
    while (true) {
        q.wait(1000);
    }
}