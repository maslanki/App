#include <jni.h>
#include "AudioEngine.h"
#include <oboe/Oboe.h>
using namespace oboe;

void AudioEngine::Start() {
    AudioStreamBuilder builder;
    builder.setDirection(Direction::Input);
    builder.setPerformanceMode(PerformanceMode::LowLatency);
    Result result = builder.openStream(&stream);
    if (result != Result::OK) {
        std::string message = ("Error opening stream: %s", convertToText(result));
        return;
    }
    else
    {
        std::string message = ("Stream opened properly: %s", convertToText(result));
        result = stream->requestStart();
    }
}

AudioEngine::~AudioEngine() {
    stream->close();
}


