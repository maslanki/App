#ifndef SOUNDAPP_PLAYINGCALLBACK_H
#define SOUNDAPP_PLAYINGCALLBACK_H

#include "../../../../../oboe/include/oboe/AudioStreamCallback.h"
#include "SoundRecording.h"
#include "../../../../../libsndfile/src/sndfile.hh"
#include "../../../../../../../AppData/Local/Android/Sdk/ndk/21.1.6352462/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/c++/v1/cstdint"
#include "../../../../../oboe/include/oboe/Definitions.h"

class PlayingCallback : public oboe::AudioStreamCallback {

private:
    const char* TAG = "PlayingCallback:: %s";
    SoundRecording* soundRecording = nullptr;
    SndfileHandle* sndFileHandle = nullptr;
    bool isPlaybackFromFile = false;

public:
    PlayingCallback() = default;
    explicit PlayingCallback(SoundRecording* recording, SndfileHandle* handle)
    {
        soundRecording = recording;
        sndFileHandle = handle;
    }
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames); //przykrycie wirtualnych metod
    oboe::DataCallbackResult processPlaybackFrames(oboe::AudioStream *audioStream, int16_t *audioData, int32_t numFrames);

    bool isPlayingFromFile() { return isPlaybackFromFile; }
    void setPlaybackFromFile(bool isFile) { isPlaybackFromFile = isFile; }
};

#endif //SOUNDAPP_PLAYINGCALLBACK_H
