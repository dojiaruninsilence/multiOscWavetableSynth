/*
  ==============================================================================

    AudioEngine.h
    Created: 30 Apr 2024 7:29:17pm
    Author:  Zubin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AudioEngine : public juce::MPESynthesiser
{
public:
    static constexpr auto maxNumVoices = 4;

    AudioEngine();

    void prepare(const juce::dsp::ProcessSpec& spec) noexcept;

private:
    void renderNextSubBlock(juce::AudioBuffer<float>& outputAudio, int startSample, int numSamples) override;
};