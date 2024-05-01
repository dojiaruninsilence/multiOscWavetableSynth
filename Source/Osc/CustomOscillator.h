/*
  ==============================================================================

    CustomOscillator.h
    Created: 30 Apr 2024 7:27:39pm
    Author:  Zubin

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

template <typename Type>
class CustomOscillator {
public:
    CustomOscillator();

    void setFrequency(Type newValue, bool force = false);
    void setLevel(Type newValue);
    void reset() noexcept;

    template <typename ProcessContext>
    void process(const ProcessContext& context) noexcept {
        juce::ignoreUnused(context);
    }

    void prepare(const juce::dsp::ProcessSpec& spec);
private:
};

template class CustomOscillator<float>;