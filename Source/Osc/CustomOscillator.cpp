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
    auto& osc = processorChain.template get<oscIndex>();
    osc.initialise([](Type x) {return std::sin(x);}, 128);
}

template <typename Type>
void CustomOscillator<Type>::setFrequency(Type newValue, bool force) {
    auto& osc = processorChain.template get<oscIndex>();
    osc.setFrequency(newValue, force);
}

template <typename Type>
void CustomOscillator<Type>::setLevel(Type newValue) {
    auto& gain = processorChain.template get<gainIndex>();
    gain.setGainLinear(newValue);
}

template <typename Type>
void CustomOscillator<Type>::reset() noexcept {
    processorChain.reset();
}

template <typename Type>
void CustomOscillator<Type>::prepare(const juce::dsp::ProcessSpec& spec) {
    processorChain.prepare(spec);
}