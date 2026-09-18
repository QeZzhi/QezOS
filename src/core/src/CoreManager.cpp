#include "CoreManager.h"
#include "GraphicsCore.h"
#include "MathCore.h"
#include "MemoryCore.h"
#include "AudioCore.h"
#include "DriverCore.h"

namespace core {

void CoreManager::init() {
    GraphicsCore::init();
}

}