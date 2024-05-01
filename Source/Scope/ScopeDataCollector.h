/*
  ==============================================================================

    ScopeDataCollector.h
    Created: 30 Apr 2024 7:30:33pm
    Author:  Zubin

  ==============================================================================
*/

#pragma once

#include "../Audio/AudioBufferQueue.h"

template <typename SampleType>
class ScopeDataCollector
{
public:
    ScopeDataCollector(AudioBufferQueue<SampleType>& queueToUse);
    void process(const SampleType* data, size_t numSamples);
private:
    AudioBufferQueue<SampleType>& audioBufferQueue;
    std::array<SampleType, AudioBufferQueue<SampleType>::bufferSize> buffer;
    size_t numCollected;
    SampleType prevSample = SampleType(100);

    static constexpr auto triggerLevel = SampleType(0.05);

    enum class State {waitingForTrigger, collecting} state {State::waitingForTrigger};
};