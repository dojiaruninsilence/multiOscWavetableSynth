/*
  ==============================================================================

    ScopeDataCollector.cpp
    Created: 30 Apr 2024 7:30:33pm
    Author:  Zubin

  ==============================================================================
*/

#include "ScopeDataCollector.h"

template <typename SampleType>
ScopeDataCollector<SampleType>::ScopeDataCollector(AudioBufferQueue<SampleType>& queueToUse)
    : audioBufferQueue(queueToUse){
}

template <typename SampleType>
void ScopeDataCollector<SampleType>::process(const SampleType* data, size_t numSamples) {
    size_t index = 0;

    if (state == State::waitingForTrigger) {
        while (index++ < numSamples) {
            auto currentSample = *data++;

            if (currentSample >= triggerLevel && prevSample < triggerLevel) {
                numCollected = 0;
                state = State::collecting;
                break;
            }

            prevSample = currentSample;
        }
    }

    if (state == State::collecting) {
        while (index++ < numSamples) {
            buffer[numCollected++] = *data++;

            if (numCollected == buffer.size()) {
                audioBufferQueue.push(buffer.data(), buffer.size());
                state = State::waitingForTrigger;
                prevSample = SampleType(100);
                break;
            }
        }
    }
}