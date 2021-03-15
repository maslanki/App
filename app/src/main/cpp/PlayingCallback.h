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
    SoundRecording* mSoundRecording = nullptr;
    SndfileHandle* mFileHandle = nullptr;
    bool isPlaybackFromFile = false;

public:
    PlayingCallback() = default;

    explicit PlayingCallback(SoundRecording* recording, SndfileHandle* handle) {
        mSoundRecording = recording;
        mFileHandle = handle;
    }

    bool isPlayingFromFile() { return isPlaybackFromFile; }
    void setPlaybackFromFile(bool isFile) { isPlaybackFromFile = isFile; }

    oboe::DataCallbackResult
    onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames);

    oboe::DataCallbackResult
    processPlaybackFrames(oboe::AudioStream *audioStream, int16_t *audioData, int32_t numFrames);

};

#endif //SOUNDAPP_PLAYINGCALLBACK_H
