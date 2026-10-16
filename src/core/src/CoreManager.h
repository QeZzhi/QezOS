// ============================================================
// CoreManager.h — заголовок менеджера ядра QezOS
// Класс CoreManager инициализирует все модули ядра.
// CoreManager.h — QezOS core manager header
// Class CoreManager initializes all core modules.
// ============================================================

#ifndef CORE_MANAGER_H // Если CORE_MANAGER_H ещё не определён | If CORE_MANAGER_H is not defined yet
#define CORE_MANAGER_H // Определяем CORE_MANAGER_H | Define CORE_MANAGER_H

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// CoreManager — статический класс для инициализации ядра
// Вызывает init() у каждого модуля (графика, математика, ...)
// ------------------------------------------------------------
class CoreManager { // Класс CoreManager | Class CoreManager
public: // Публичные методы | Public methods
    
    // Инициализировать все модули ядра | Initialize all core modules
    static void init();
};

} // Конец namespace core | End of namespace core

#endif // Конец include guard | End of include guard