#ifndef ASM_AUDIO_H
#define ASM_AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

int  mix_audio_fast(int a, int b);
void mix_buffer_fast(int* out, int* in, int size);

int square_wave_fast(int phase, int amplitude);
int saw_wave_fast(int phase, int amplitude);

int  apply_volume_fast(int sample, int volume);
void apply_volume_buffer_fast(int* buffer, int size, int volume);

#ifdef __cplusplus
}
#endif

#endif