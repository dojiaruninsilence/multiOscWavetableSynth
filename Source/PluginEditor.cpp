/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultiOscWavetableSynthAudioProcessorEditor::MultiOscWavetableSynthAudioProcessorEditor (MultiOscWavetableSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), scopeComponent(audioProcessor.getAudioBufferQueue()) {
    addAndMakeVisible(midiKeyboardComponent);
    addAndMakeVisible(scopeComponent);

    setSize (400, 300);

    auto area = getLocalBounds();
    scopeComponent.setTopLeftPosition(0, 80);
    scopeComponent.setSize(area.getWidth(), area.getHeight() - 100);

    midiKeyboardComponent.setMidiChannel(2);
    midiKeyboardState.addListener(&audioProcessor.getMidiMessageCollector());
}

MultiOscWavetableSynthAudioProcessorEditor::~MultiOscWavetableSynthAudioProcessorEditor() {
    midiKeyboardState.removeListener(&audioProcessor.getMidiMessageCollector());
}

//==============================================================================
void MultiOscWavetableSynthAudioProcessorEditor::paint (juce::Graphics& g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MultiOscWavetableSynthAudioProcessorEditor::resized() {
    auto area = getLocalBounds();
    midiKeyboardComponent.setBounds(area.removeFromTop(80).reduced(8));
}
