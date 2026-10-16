// ============================================================
// asm_audio.h — заголовок ассемблерных функций для аудио
// Объявляет быстрые функции для работы со звуком (написаны на .S).
// asm_audio.h — assembly audio functions header
// Declares fast audio functions (written in .S).
// ============================================================

#ifndef ASM_AUDIO_H // Если ASM_AUDIO_H ещё не определён | If ASM_AUDIO_H is not defined yet
#define ASM_AUDIO_H // Определяем ASM_AUDIO_H | Define ASM_AUDIO_H

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
extern "C" { // Отключаем искажение имён (name mangling) | Disable name mangling
#endif

// ------------------------------------------------------------
// Микширование (смешивание двух аудиопотоков)
// ------------------------------------------------------------

// Смешать два сэмпла (усреднение) | Mix two samples (averaging)
int mix_audio_fast(int a, int b);

// Смешать два буфера | Mix two buffers
void mix_buffer_fast(int* out, int* in, int size);

// ------------------------------------------------------------
// Генерация волн
// ------------------------------------------------------------

// Квадратная волна | Square wave
int square_wave_fast(int phase, int amplitude);

// Пилообразная волна | Saw wave
int saw_wave_fast(int phase, int amplitude);

// ------------------------------------------------------------
// Громкость
// ------------------------------------------------------------

// Применить громкость к одному сэмплу | Apply volume to one sample
int apply_volume_fast(int sample, int volume);

// Применить громкость к буферу | Apply volume to buffer
void apply_volume_buffer_fast(int* buffer, int size, int volume);

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
} // Закрываем extern "C" | Close extern "C"
#endif

#endif // Конец include guard | End of include guard