#include "PlayingCallback.h"
#include "Utils.h"
#include "oboe/AudioStream.h"

oboe::DataCallbackResult PlayingCallback::onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames)
{
    return processPlaybackFrames(audioStream, static_cast<int16_t *>(audioData), numFrames * audioStream->getChannelCount());
}

oboe::DataCallbackResult PlayingCallback::processPlaybackFrames(oboe::AudioStream *audioStream, int16_t *audioData, int32_t numFrames)
{
    fillArrayWithZeros(audioData, numFrames);
    int64_t framesWritten = 0;

    if (!isPlayingFromFile()) framesWritten = soundRecording->read(audioData, numFrames);
    else framesWritten = static_cast<sf_count_t>(sndFileHandle->read(audioData, numFrames));

    if (framesWritten == 0) {
        audioStream->requestStop();
        return oboe::DataCallbackResult::Stop;
    }
    return oboe::DataCallbackResult::Continue;
}