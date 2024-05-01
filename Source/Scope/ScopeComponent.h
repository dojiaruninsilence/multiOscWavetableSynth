/*
  ==============================================================================

    ScopeComponent.h
    Created: 30 Apr 2024 7:31:14pm
    Author:  Zubin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ScopeComponent  : public juce::Component
{
public:
    ScopeComponent();
    ~ScopeComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScopeComponent)
};
