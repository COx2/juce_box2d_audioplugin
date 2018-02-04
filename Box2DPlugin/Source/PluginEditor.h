/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#include "GUI/Box2DRenderComponent.h"

//==============================================================================
/**
*/
class Box2dpluginAudioProcessorEditor  : public AudioProcessorEditor, private Timer
{
public:
    Box2dpluginAudioProcessorEditor (Box2dpluginAudioProcessor&);
    ~Box2dpluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Box2dpluginAudioProcessor& processor;

	MidiKeyboardComponent keyboardComponent;

	Box2DRenderComponent renderComponent;
	b2Settings myb2Settings;
	void timerCallback() override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Box2dpluginAudioProcessorEditor)
};
