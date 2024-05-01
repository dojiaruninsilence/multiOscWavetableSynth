/*
  ==============================================================================

    AudioBufferQueue.h
    Created: 30 Apr 2024 7:29:44pm
    Author:  Zubin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

template <typename SampleType>
class AudioBufferQueue
{
public:
    static constexpr size_t order = 9;
    static constexpr size_t bufferSize = 1U << order;
    static constexpr size_t numBuffers = 5;

    void push(const SampleType* dataToPush, size_t numSamples);
    void pop(SampleType* outputBuffer);

private:
    juce::AbstractFifo abstractFifo{ numBuffers };
    std::array<std::array<SampleType, bufferSize>, numBuffers> buffers;
};