//
// Created by User on 19.01.2021.
//

#ifndef SOUNDAPP_AUDIOENGINE_H
#define SOUNDAPP_AUDIOENGINE_H
#include <oboe/Oboe.h>
class AudioEngine {
public:
    AudioEngine();
    oboe::AudioStream* stream;
    void Start();
    ~AudioEngine();
};


#endif //SOUNDAPP_AUDIOENGINE_H
