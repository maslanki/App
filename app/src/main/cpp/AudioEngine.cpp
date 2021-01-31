#include <jni.h>
#include "AudioEngine.h"
#include <oboe/Oboe.h>
using namespace oboe;

AudioEngine::AudioEngine() { //test constructor
    int x = 0;
}
void AudioEngine::Start() {
    AudioStreamBuilder builder;
    builder.setDirection(Direction::Input);
    builder.setPerformanceMode(PerformanceMode::LowLatency);
    Result result = builder.openStream(&stream);
    if (result != Result::OK) {
        std::string message = ("Error opening stream: %s", convertToText(result));
        result = stream->requestStart();
    }

    if (result != Result::OK) std::string message = ("Error starting stream: %s", convertToText(result));

}

AudioEngine::~AudioEngine() {
    stream->close();
}


