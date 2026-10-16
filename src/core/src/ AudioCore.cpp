// ============================================================
// AudioCore.cpp — обёртка над ассемблерными аудиофункциями
// Класс AudioCore вызывает asm_audio.h из C++.
// AudioCore.cpp — wrapper over assembly audio functions
// Class AudioCore calls asm_audio.h from C++.
// ============================================================

#include "AudioCore.h"              // Объявление класса AudioCore | AudioCore class declaration
#include "core/inc/asm_audio.h"     // Ассемблерные аудиофункции | Assembly audio functions

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// AudioCore::mix — смешать два сэмпла
// ------------------------------------------------------------
int AudioCore::mix(int a, int b) { // Смешать | Mix
    return mix_audio_fast(a, b); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// AudioCore::mixBuffer — смешать два буфера
// ------------------------------------------------------------
void AudioCore::mixBuffer(int* out, int* in, int size) { // Смешать буферы | Mix buffers
    mix_buffer_fast(out, in, size); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// AudioCore::squareWave — сгенерировать квадратную волну
// ------------------------------------------------------------
int AudioCore::squareWave(int phase, int amplitude) { // Квадратная волна | Square wave
    return square_wave_fast(phase, amplitude); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// AudioCore::sawWave — сгенерировать пилообразную волну
// ------------------------------------------------------------
int AudioCore::sawWave(int phase, int amplitude) { // Пилообразная волна | Saw wave
    return saw_wave_fast(phase, amplitude); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// AudioCore::applyVolume — применить громкость к сэмплу
// ------------------------------------------------------------
int AudioCore::applyVolume(int sample, int volume) { // Громкость | Volume
    return apply_volume_fast(sample, volume); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// AudioCore::applyVolumeBuffer — применить громкость к буферу
// ------------------------------------------------------------
void AudioCore::applyVolumeBuffer(int* buffer, int size, int volume) { // Громкость буфера | Buffer volume
    apply_volume_buffer_fast(buffer, size, volume); // Вызываем ассемблерную функцию | Call assembly function
}

} // Конец namespace core | End of namespace core