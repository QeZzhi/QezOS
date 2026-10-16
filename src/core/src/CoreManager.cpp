// ============================================================
// CoreManager.cpp — менеджер ядра QezOS
// Инициализирует все модули ядра (графика, математика, память, ...).
// CoreManager.cpp — QezOS core manager
// Initializes all core modules (graphics, math, memory, ...).
// ============================================================

#include "CoreManager.h"      // Объявление CoreManager | CoreManager declaration
#include "GraphicsCore.h"     // GraphicsCore::init | GraphicsCore::init
#include "MathCore.h"         // MathCore (пока не используется) | MathCore (unused yet)
#include "MemoryCore.h"       // MemoryCore (пока не используется) | MemoryCore (unused yet)
#include "AudioCore.h"        // AudioCore (пока не используется) | AudioCore (unused yet)
#include "DriverCore.h"       // DriverCore (пока не используется) | DriverCore (unused yet)

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// CoreManager::init — инициализировать ядро QezOS
// Сейчас инициализирует только графику
// ------------------------------------------------------------
void CoreManager::init() { // Инициализация ядра | Init core
    GraphicsCore::init(); // Инициализируем графику | Initialize graphics
}

} // Конец namespace core | End of namespace core