/*
  ==============================================================================

    CustomOscillator.cpp
    Created: 30 Apr 2024 7:27:39pm
    Author:  Zubin

  ==============================================================================
*/

#include "CustomOscillator.h"

template <typename Type>
CustomOscillator<Type>::CustomOscillator() {

}

template <typename Type>
void CustomOscillator<Type>::setFrequency(Type newValue, bool force) {
    juce::ignoreUnused(newValue, force);
}

template <typename Type>
void CustomOscillator<Type>::setLevel(Type newValue) {
    juce::ignoreUnused(newValue);
}

template <typename Type>
void CustomOscillator<Type>::reset() noexcept {
    
}

template <typename ProcessContext>
void process(const ProcessContext& context)  {
    juce::ignoreUnused(context);
}

template <typename Type>
void CustomOscillator<Type>::prepare(const juce::dsp::ProcessSpec& spec) {
    juce::ignoreUnused(spec);
}