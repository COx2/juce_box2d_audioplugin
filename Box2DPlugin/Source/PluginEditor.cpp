/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "GUI/b2Scenes/Tumbler.h"

//==============================================================================
Box2dpluginAudioProcessorEditor::Box2dpluginAudioProcessorEditor (Box2dpluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p),
	keyboardComponent(p.keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);

	addAndMakeVisible(keyboardComponent);

	addAndMakeVisible(renderComponent);
	renderComponent.currentScene = new Tumbler();

	keyboardComponent.setBoundsRelative(0.0, 0.8, 1.0, 0.2);
	renderComponent.setBoundsRelative(0.02, 0.02, 0.96, 0.76);

	startTimerHz(60);
}

Box2dpluginAudioProcessorEditor::~Box2dpluginAudioProcessorEditor()
{
}

//==============================================================================
void Box2dpluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void Box2dpluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	keyboardComponent.setBoundsRelative(0.0, 0.7, 1.0, 0.3);
	
	renderComponent.setBoundsRelative(0.02, 0.02, 0.86, 0.66);

}

void Box2dpluginAudioProcessorEditor::timerCallback()
{
	if (renderComponent.currentScene == nullptr)
		return;

	//grabKeyboardFocus();
	//checkKeys();
	
	renderComponent.currentScene->Update(&myb2Settings);
	repaint();
}
