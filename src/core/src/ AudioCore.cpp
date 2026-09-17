#include "AudioCore.h"
#include "core/inc/asm_audio.h"

namespace core {

int AudioCore::mix(int a, int b) {
    return mix_audio_fast(a, b);
}

void AudioCore::mixBuffer(int* out, int* in, int size) {
    mix_buffer_fast(out, in, size);
}

int AudioCore::squareWave(int phase, int amplitude) {
    return square_wave_fast(phase, amplitude);
}

int AudioCore::sawWave(int phase, int amplitude) {
    return saw_wave_fast(phase, amplitude);
}

int AudioCore::applyVolume(int sample, int volume) {
    return apply_volume_fast(sample, volume);
}

void AudioCore::applyVolumeBuffer(int* buffer, int size, int volume) {
    apply_volume_buffer_fast(buffer, size, volume);
}

} // namespace core