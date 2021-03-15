//
// Created by User on 19.01.2021.
//

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
    void StartRecording();
    void StopRecording();
    void StartPlayingRecorderStream();
    oboe::AudioStream* stream;
    RecordingCallback recordingCallback = RecordingCallback(&mSoundRecording);
    PlayingCallback playingCallback = PlayingCallback(&mSoundRecording, &sndFileHandle);


private:
    int32_t mInputChannelCount = oboe::ChannelCount::Stereo;
    int32_t mOutputChannelCount = oboe::ChannelCount::Stereo;
    int32_t mRecordingDeviceId = oboe::VoiceRecognition;
    int32_t mSampleRate = oboe::kUnspecified;
    int32_t mPlaybackDeviceId = 6;
    int32_t mFramesPerBurst;

    SoundRecording mSoundRecording;

    oboe::AudioApi mAudioApi = oboe::AudioApi::AAudio;
    oboe::AudioFormat mFormat = oboe::AudioFormat::I16;
    oboe::AudioStream *mRecordingStream = nullptr;
    oboe::AudioStream *mPlaybackStream = nullptr;
    SndfileHandle sndFileHandle;

    void OpenRecordingStream();
    oboe::AudioStreamBuilder* SetUpRecordingStreamParameters(oboe::AudioStreamBuilder* builder);
    void StartStream(oboe::AudioStream *stream);
    void StopStream(oboe::AudioStream *stream);
    void CloseStream(oboe::AudioStream *stream);
    void OpenPlaybackStreamFromRecordedStreamParameters();
    oboe::AudioStreamBuilder* SetUpPlaybackStreamParameters(oboe::AudioStreamBuilder *builder, oboe::AudioApi audioApi, oboe::AudioFormat audioFormat, oboe::AudioStreamCallback *audioStreamCallback, int32_t deviceId, int32_t sampleRate, int channelCount);

};


#endif //SOUNDAPP_AUDIOENGINE_H
