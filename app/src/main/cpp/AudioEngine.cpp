#include <jni.h>
#include "AudioEngine.h"
#include <oboe/Oboe.h>

using namespace oboe;

AudioEngine::AudioEngine() {
    assert(outputChannelCount == inputChannelCount); //asercja do sprawdzenia zgodności kanałów
}

AudioEngine::~AudioEngine() {
    stream->close();
}

void AudioEngine::startRecording(){
    openRecordingStream();
    if (recordingStream) startStream(recordingStream);
    else closeStream(recordingStream);
}

void AudioEngine::stopRecording() {
    stopStream(recordingStream);
    closeStream(recordingStream);
    startPlayingRecorderStream();
}

void AudioEngine::startPlayingRecorderStream(){
    openPlaybackStreamFromRecordedStreamParameters();
    if (playbackStream) startStream(playbackStream);
    else closeStream(playbackStream);
}

void AudioEngine::openPlaybackStreamFromRecordedStreamParameters(){
    oboe::AudioStreamBuilder builder;
    setUpPlaybackStreamParameters(&builder, audioApi, audioFormat, &playingCallback,
                                  playbackDeviceId, sampleRate, outputChannelCount);
    playingCallback.setPlaybackFromFile(false);
    oboe::Result result = builder.openStream(&playbackStream);
    if (result == oboe::Result::OK && playbackStream)
    {
        assert(playbackStream->getChannelCount() == outputChannelCount);
        assert(playbackStream->getFormat() == audioFormat);
        sampleRate = playbackStream->getSampleRate();
        framesPerBurst = playbackStream->getFramesPerBurst();
        playbackStream->setBufferSizeInFrames(framesPerBurst);
    }
    // Set the buffer size to the burst size - this will give us the minimum possible latency
}

oboe::AudioStreamBuilder* AudioEngine::setUpPlaybackStreamParameters(oboe::AudioStreamBuilder *builder, oboe::AudioApi audioApi, oboe::AudioFormat audioFormat, oboe::AudioStreamCallback *audioStreamCallback, int32_t deviceId, int32_t sampleRate, int channelCount){
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

void AudioEngine::openRecordingStream() {
    oboe::AudioStreamBuilder builder;
    setUpRecordingStreamParameters(&builder);
    oboe::Result result = builder.openStream(&recordingStream);
    if (result == oboe::Result::OK && recordingStream)
    {
        assert(recordingStream->getChannelCount() == inputChannelCount);
        sampleRate = recordingStream->getSampleRate();
        audioFormat = recordingStream->getFormat();
    }
}

oboe::AudioStreamBuilder *AudioEngine::setUpRecordingStreamParameters(oboe::AudioStreamBuilder *builder) {
    builder->setAudioApi(audioApi)
            ->setFormat(audioFormat)
            ->setSharingMode(oboe::SharingMode::Exclusive)
            ->setPerformanceMode(oboe::PerformanceMode::LowLatency)
            ->setCallback(&recordingCallback)
            ->setDeviceId(recordingDeviceId)
            ->setDirection(oboe::Direction::Input)
//            ->setSampleRate(sampleRate)
            ->setChannelCount(inputChannelCount);
    return builder;
}

void AudioEngine::startStream(oboe::AudioStream *stream) {
    assert(stream);
    if (stream) oboe::Result result = stream->requestStart();
}

void AudioEngine::stopStream(oboe::AudioStream *stream) {
    if (stream) oboe::Result result = stream->stop(0L);
}

void AudioEngine::closeStream(oboe::AudioStream *stream) {
    if (stream) {
        oboe::Result result = stream->close();
        if (result == oboe::Result::OK) stream = nullptr;
    }
}

