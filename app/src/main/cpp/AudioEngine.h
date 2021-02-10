//
// Created by User on 19.01.2021.
//

#ifndef SOUNDAPP_AUDIOENGINE_H
#define SOUNDAPP_AUDIOENGINE_H
#include <oboe/Oboe.h>
//#include <sndfile.h> -> to install

class AudioEngine {
public:
    AudioEngine();
    ~AudioEngine();
    void StartRecording();
    void StopRecording();
    oboe::AudioStream* stream;
private:
    int32_t mInputChannelCount = oboe::ChannelCount::Stereo;
    int32_t mOutputChannelCount = oboe::ChannelCount::Stereo;
    int32_t mRecordingDeviceId = oboe::VoiceRecognition;
    int32_t mSampleRate = oboe::kUnspecified;

    oboe::AudioApi mAudioApi = oboe::AudioApi::AAudio;
    oboe::AudioFormat mFormat = oboe::AudioFormat::I16;
    oboe::AudioStream *mRecordingStream = nullptr;
    oboe::AudioStream *mPlaybackStream = nullptr;
  //  SndFileHandle sndFileHandle;

    void OpenRecordingStream();
    oboe::AudioStreamBuilder* SetUpRecordingStreamParameters(oboe::AudioStreamBuilder* builder);
    void StartStream(oboe::AudioStream *stream);
    void StopStream(oboe::AudioStream *stream);
    void CloseStream(oboe::AudioStream *stream);

};


#endif //SOUNDAPP_AUDIOENGINE_H
