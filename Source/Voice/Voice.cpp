/*
  ==============================================================================

    Voice.cpp
    Created: 30 Apr 2024 7:28:41pm
    Author:  Zubin

  ==============================================================================
*/

#include "Voice.h"

Voice::Voice() {
    auto& masterGain = processorChain.get<masterGainIndex>();
    masterGain.setGainLinear(0.7f);
}

void Voice::prepare(const juce::dsp::ProcessSpec& spec) {
    tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
    processorChain.prepare(spec);
}

void Voice::noteStarted() {
    auto velocity = getCurrentlyPlayingNote().noteOnVelocity.asUnsignedFloat();
    auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();

    processorChain.get<osc1Index>().setFrequency(freqHz, true);
    processorChain.get<osc1Index>().setLevel(velocity);
}

void Voice::notePitchbendChanged() {
    auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();
    processorChain.get<osc1Index>().setFrequency(freqHz);
}

void Voice::noteStopped(bool) {
    clearCurrentNote();
}

void Voice::notePressureChanged() {

}

void Voice::noteTimbreChanged() {

}

void Voice::noteKeyStateChanged() {

}

void Voice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {
    auto block = tempBlock.getSubBlock(0, (size_t)numSamples);
    block.clear();
    juce::dsp::ProcessContextReplacing<float>context(block);
    processorChain.process(context);

    juce::dsp::AudioBlock<float>(outputBuffer).getSubBlock((size_t)startSample, (size_t)numSamples).add(tempBlock);
}