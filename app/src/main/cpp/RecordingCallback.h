#ifndef SOUNDAPP_RECORDINGCALLBACK_H
#define SOUNDAPP_RECORDINGCALLBACK_H

#include "../../../../../oboe/include/oboe/AudioStreamCallback.h"
#include "SoundRecording.h"
#include "../../../../../oboe/include/oboe/Definitions.h"
#include <oboe/Oboe.h>

class RecordingCallback : public oboe::AudioStreamCallback {
private:
    const char* TAG = "RecordingCallback:: %s";
    SoundRecording* mSoundRecording = nullptr;

public:
    RecordingCallback() = default;
    explicit RecordingCallback(SoundRecording* recording) { mSoundRecording = recording; }
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames);
    oboe::DataCallbackResult processRecordingFrames(oboe::AudioStream *audioStream, int16_t *audioData, int32_t numFrames);
};

#endif //SOUNDAPP_RECORDINGCALLBACK_H
