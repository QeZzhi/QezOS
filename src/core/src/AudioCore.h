// ============================================================
// AudioCore.h — заголовок обёртки над ассемблерным аудио
// Класс AudioCore вызывает asm_audio.h из C++.
// AudioCore.h — wrapper header over assembly audio
// Class AudioCore calls asm_audio.h from C++.
// ============================================================

#ifndef AUDIO_CORE_H // Если AUDIO_CORE_H ещё не определён | If AUDIO_CORE_H is not defined yet
#define AUDIO_CORE_H // Определяем AUDIO_CORE_H | Define AUDIO_CORE_H

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// AudioCore — статический класс-обёртка над asm_audio.h
// Все методы статические — объект создавать не надо
// ------------------------------------------------------------
class AudioCore { // Класс AudioCore | Class AudioCore
public: // Публичные методы | Public methods
    
    // Смешать два сэмпла | Mix two samples
    static int  mix(int a, int b);
    
    // Смешать два буфера | Mix two buffers
    static void mixBuffer(int* out, int* in, int size);
    
    // Квадратная волна | Square wave
    static int  squareWave(int phase, int amplitude);
    
    // Пилообразная волна | Saw wave
    static int  sawWave(int phase, int amplitude);
    
    // Применить громкость к сэмплу | Apply volume to sample
    static int  applyVolume(int sample, int volume);
    
    // Применить громкость к буферу | Apply volume to buffer
    static void applyVolumeBuffer(int* buffer, int size, int volume);
};

} // Конец namespace core | End of namespace core

#endif // Конец include guard | End of include guard