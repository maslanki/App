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
    OpenRecordingStream();
    if (mRecordingStream) {
        StartStream(mRecordingStream);
    } else {
        CloseStream(mRecordingStream);
    }
}

void AudioEngine::StopRecording() {
    StopStream(mRecordingStream);
    CloseStream(mRecordingStream);
    StartPlayingRecorderStream();
}

void AudioEngine::StartPlayingRecorderStream(){
    OpenPlaybackStreamFromRecordedStreamParameters();
    if (mPlaybackStream) {
        StartStream(mPlaybackStream);
    } else {
        CloseStream(mPlaybackStream);
    }
}

void AudioEngine::OpenPlaybackStreamFromRecordedStreamParameters(){
    oboe::AudioStreamBuilder builder;

    SetUpPlaybackStreamParameters(&builder, mAudioApi, mFormat, &playingCallback, mPlaybackDeviceId, mSampleRate, mOutputChannelCount);

    playingCallback.setPlaybackFromFile(false);

    oboe::Result result = builder.openStream(&mPlaybackStream);
    if (result == oboe::Result::OK && mPlaybackStream) {
        assert(mPlaybackStream->getChannelCount() == mOutputChannelCount);
//        assert(mPlaybackStream->getSampleRate() == mSampleRate);
        assert(mPlaybackStream->getFormat() == mFormat);

        mSampleRate = mPlaybackStream->getSampleRate();

        mFramesPerBurst = mPlaybackStream->getFramesPerBurst();

        // Set the buffer size to the burst size - this will give us the minimum possible latency
        mPlaybackStream->setBufferSizeInFrames(mFramesPerBurst);

    }
}

oboe::AudioStreamBuilder* AudioEngine::SetUpPlaybackStreamParameters(oboe::AudioStreamBuilder *builder, oboe::AudioApi audioApi, oboe::AudioFormat audioFormat, oboe::AudioStreamCallback *audioStreamCallback, int32_t deviceId, int32_t sampleRate, int channelCount){
    builder->setAudioApi(audioApi)
            ->setFormat(audioFormat)
            ->setSharingMode(oboe::SharingMode::Exclusive)
            ->setPerformanceMode(oboe::PerformanceMode::LowLatency)
            ->setCallback(audioStreamCallback)
            ->setDeviceId(deviceId)
            ->setDirection(oboe::Direction::Output)
            ->setSampleRate(sampleRate)
            ->setChannelCount(channelCount);
    return builder;
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
            ->setCallback(&recordingCallback)
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

