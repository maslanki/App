#ifndef SOUNDAPP_AUDIOENGINE_H
#define SOUNDAPP_AUDIOENGINE_H

#include <oboe/Oboe.h>
#include "RecordingCallback.h"
#include "PlayingCallback.h"
#include <sndfile.h>

class AudioEngine {
public:
    AudioEngine();
    ~AudioEngine();
    void startRecording();
    void stopRecording();
    void startPlayingRecorderStream();

    oboe::AudioStream* stream;
    RecordingCallback recordingCallback = RecordingCallback(&soundRecording);
    PlayingCallback playingCallback = PlayingCallback(&soundRecording, &sndFileHandle);

private:
    void openRecordingStream();
    void startStream(oboe::AudioStream *stream);
    void stopStream(oboe::AudioStream *stream);
    void closeStream(oboe::AudioStream *stream);
    void openPlaybackStreamFromRecordedStreamParameters();
    oboe::AudioStreamBuilder* setUpRecordingStreamParameters(oboe::AudioStreamBuilder* builder);
    oboe::AudioStreamBuilder* setUpPlaybackStreamParameters(oboe::AudioStreamBuilder *builder, oboe::AudioApi audioApi, oboe::AudioFormat audioFormat, oboe::AudioStreamCallback *audioStreamCallback, int32_t deviceId, int32_t sampleRate, int channelCount);

    int32_t inputChannelCount = oboe::ChannelCount::Stereo;
    int32_t outputChannelCount = oboe::ChannelCount::Stereo;
    int32_t recordingDeviceId = oboe::VoiceRecognition;
    int32_t sampleRate = oboe::kUnspecified;
    int32_t playbackDeviceId = 6;
    int32_t framesPerBurst;

    SoundRecording soundRecording;

    oboe::AudioApi audioApi = oboe::AudioApi::AAudio;
    oboe::AudioFormat audioFormat = oboe::AudioFormat::I16;
    oboe::AudioStream *recordingStream = nullptr;
    oboe::AudioStream *playbackStream = nullptr;
    SndfileHandle sndFileHandle;
};


#endif //SOUNDAPP_AUDIOENGINE_H
