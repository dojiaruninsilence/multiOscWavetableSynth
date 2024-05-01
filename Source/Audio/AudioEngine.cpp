/*
  ==============================================================================

    AudioEngine.cpp
    Created: 30 Apr 2024 7:29:17pm
    Author:  Zubin

  ==============================================================================
*/

#include "AudioEngine.h"
#include "../Voice/Voice.h"

AudioEngine::AudioEngine() {
    for (auto i = 0; i < maxNumVoices; ++i) {
        addVoice(new Voice);
    }

    setVoiceStealingEnabled(true);
}

void AudioEngine::prepare(const juce::dsp::ProcessSpec& spec) noexcept {
    setCurrentPlaybackSampleRate(spec.sampleRate);

    for (auto* v : voices) {
        dynamic_cast<Voice*>(v)->prepare(spec);
    }
}

void AudioEngine::renderNextSubBlock(juce::AudioBuffer<float>& outputAudio, int startSample, int numSamples) {
    MPESynthesiser::renderNextSubBlock(outputAudio, startSample, numSamples);
}