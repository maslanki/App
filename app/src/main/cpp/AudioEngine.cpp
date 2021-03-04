#include <jni.h>
#include "AudioEngine.h"
#include <oboe/Oboe.h>
using namespace oboe;

AudioEngine::AudioEngine() {
    assert(mOutputChannelCount == mInputChannelCount); //asercja do sprawdzenia zgodności kanałów
}

AudioEngine::~AudioEngine() {
    stream->close();
}

void AudioEngine::StartRecording(){
    AudioStreamBuilder builder;
    builder.setDirection(Direction::Input);
    builder.setPerformanceMode(PerformanceMode::LowLatency);

    AudioStream *stream;
    Result r = builder.openStream(&stream);
    r = stream->requestStart();
    constexpr  int kMilis = 2;
    const int32_t frames = (int32_t)(kMilis*(stream->getSampleRate()/kMillisPerSecond));
    int32_t  buffer[frames];
    constexpr int64_t timeOut = 3*kNanosPerMillisecond;
    int framesRead = 0;
    do{
        auto result = stream->read(buffer,stream->getBufferSizeInFrames(),0);
        if(result != Result::OK) break;
        framesRead = result.value();
    }while(framesRead != 0);


    auto result = stream->read(buffer,frames,timeOut);
if(result ==Result::OK){
    double x = result.value();
}
//    OpenRecordingStream();
//    if (mRecordingStream) {
//        StartStream(mRecordingStream);
//    } else {
//        CloseStream(mRecordingStream);
//    }
}

void AudioEngine::StopRecording() {
    StopStream(mRecordingStream);
    CloseStream(mRecordingStream);
}

void AudioEngine::OpenRecordingStream() {
    oboe::AudioStreamBuilder builder;
    SetUpRecordingStreamParameters(&builder);
    oboe::Result result = builder.openStream(&mRecordingStream);
    if (result == oboe::Result::OK && mRecordingStream) {
        assert(mRecordingStream->getChannelCount() == mInputChannelCount);
        mSampleRate = mRecordingStream->getSampleRate();
        mFormat = mRecordingStream->getFormat();
    }
}

oboe::AudioStreamBuilder *AudioEngine::SetUpRecordingStreamParameters(oboe::AudioStreamBuilder *builder) {
    builder->setAudioApi(mAudioApi)
            ->setFormat(mFormat)
            ->setSharingMode(oboe::SharingMode::Exclusive)
            ->setPerformanceMode(oboe::PerformanceMode::LowLatency)
            //->setCallback(&recordingCallback)
            ->setDeviceId(mRecordingDeviceId)
            ->setDirection(oboe::Direction::Input)
//            ->setSampleRate(mSampleRate)
            ->setChannelCount(mInputChannelCount);
    return builder;
}

void AudioEngine::StartStream(oboe::AudioStream *stream) {

    assert(stream);
    if (stream) {
        oboe::Result result = stream->requestStart();
    }
}

void AudioEngine::StopStream(oboe::AudioStream *stream) {
    if (stream) {
        oboe::Result result = stream->stop(0L);
    }
}

void AudioEngine::CloseStream(oboe::AudioStream *stream) {
    if (stream) {
        oboe::Result result = stream->close();
        if (result == oboe::Result::OK) stream = nullptr;
    }
}

