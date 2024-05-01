/*
  ==============================================================================

    Voice.h
    Created: 30 Apr 2024 7:28:41pm
    Author:  Zubin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "../Osc/CustomOscillator.h"

class Voice : public juce::MPESynthesiserVoice
{
public:
    Voice();
    void prepare(const juce::dsp::ProcessSpec& spec);
    void noteStarted() override;
    void notePitchbendChanged() override;
    void noteStopped(bool) override;

    void notePressureChanged() override;
    void noteTimbreChanged() override;
    void noteKeyStateChanged() override;

    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
private:
    juce::HeapBlock<char> heapBlock;
    juce::dsp::AudioBlock<float> tempBlock;

    enum {
        osc1Index,
        masterGainIndex
    };

    juce::dsp::ProcessorChain<CustomOscillator<float>, juce::dsp::Gain<float>> processorChain;

    static constexpr size_t lfoUpdateRate = 100;
};