#include "SoundRecording.h"
#include "Utils.h"

int32_t SoundRecording::write(const int16_t *sourceData, int32_t numSamples) {
    // Check that data will fit, if it doesn't then create new array,
    // copy over old data to new array then delete old array and
    // point mData to new array.
    if (mWriteIndex + numSamples > (kMaxSamples * mIteration))
    {
        mIteration++;
        int32_t newSize = kMaxSamples * mIteration;
        auto * newData = new int16_t[newSize] { 0 };
        std::copy(mData, mData + mTotalSamples, newData);
        delete[] mData;
        mData = newData;
    }

    for (int i = 0; i < numSamples; ++i) mData[mWriteIndex++] = sourceData[i] * gain_factor;
    mTotalSamples += numSamples;
    return numSamples;
}

int32_t SoundRecording::read(int16_t *targetData, int32_t numSamples) {
    int32_t framesRead = 0;
    float totalSamples = static_cast<float >(numSamples);
    while (framesRead < numSamples && mReadIndex < mTotalSamples) {
        targetData[framesRead++] = mData[mReadIndex++] * sin(2.0 * static_cast<float>(framesRead) * M_PI/ totalSamples);
        if (mIsLooping && mReadIndex == mTotalSamples) mReadIndex = 0;
    }
    return framesRead;
}

SndfileHandle SoundRecording::createFile(const char *outfilename, int32_t outputChannels, int32_t sampleRate) {
    SndfileHandle file;
    int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    file = SndfileHandle (outfilename, SFM_WRITE, format, outputChannels, sampleRate);
    return file;
}

void SoundRecording::writeFile(SndfileHandle sndfileHandle) {
    int32_t framesRead = 0, bufferLength = mTotalSamples / 3;
    sf_count_t framesWrite = 0;
    auto *buffer = new int16_t[bufferLength];
    fillArrayWithZeros(buffer, bufferLength);
    while ((framesRead = read(buffer, bufferLength)) > 0) framesWrite = sndfileHandle.write(buffer, framesRead);
}

void SoundRecording::readFileInfo(const char * fileName) {
    SndfileHandle file;
    file = SndfileHandle(fileName) ;
}

void SoundRecording::initiateWritingToFile(const char *outfilename, int32_t outputChannels, int32_t sampleRate) {
    SndfileHandle handle = createFile(outfilename, outputChannels, sampleRate);
    writeFile(handle);
    readFileInfo(outfilename);
}