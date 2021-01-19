
#include "AudioEngine.h"
#include <oboe/Oboe.h>
#include <android/log.h>
using namespace oboe;
void AudioEngine::Start() {
    AudioStreamBuilder builder;
    builder.setDirection(Direction::Input);
    builder.setPerformanceMode(PerformanceMode::LowLatency);
    Result result = builder.openStream(&stream);
    if (result != Result::OK) {
        std::string message = ("Error opening stream: %s", convertToText(result));
        //dopisać console.log dla komunikatu
    }
    result = stream->requestStart();
    if (result != Result::OK) {
        std::string message = ("Error starting stream: %s", convertToText(result));
    }
}
AudioEngine::~AudioEngine() {
    stream->close();
}


