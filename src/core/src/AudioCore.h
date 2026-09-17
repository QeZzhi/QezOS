#ifndef AUDIO_CORE_H
#define AUDIO_CORE_H

namespace core {

class AudioCore {
public:
    static int  mix(int a, int b);
    static void mixBuffer(int* out, int* in, int size);
    static int  squareWave(int phase, int amplitude);
    static int  sawWave(int phase, int amplitude);
    static int  applyVolume(int sample, int volume);
    static void applyVolumeBuffer(int* buffer, int size, int volume);
};

} // namespace core

#endif