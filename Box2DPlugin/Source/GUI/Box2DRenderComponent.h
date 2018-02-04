/*
  ==============================================================================

    Box2DRenderComponent.h
    Created: 2 Feb 2018 2:31:54am
    Author:  COx2

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "b2SceneBase.h"


class Box2DRenderComponent : public Component
{
public:
	Box2DRenderComponent()
	{
		setOpaque(true);
	}

	void paint(Graphics& g) override
	{
		g.fillAll(Colours::white);

		if (currentScene != nullptr)
		{
			Box2DRenderer renderer;

			renderer.render(g,
				*currentScene->m_world,
				-24.0f, 24.0f, 24.0f, -24.0f,
				getLocalBounds().toFloat().reduced(0.0f)
			);
		}
	}

	virtual void mouseMove(const MouseEvent& event) override
	{
		
		b2Vec2 ps((float32)event.getPosition().getX(), (float32)event.getPosition().getY());
		currentScene->MouseMove(ps);

	};

	virtual void mouseDown(const MouseEvent& event) override 
	{

		b2Vec2 ps((float32)event.getPosition().getX(), (float32)event.getPosition().getY());
		currentScene->MouseMove(ps);

	};

	virtual void mouseUp(const MouseEvent& event) override
	{

		b2Vec2 ps((float32)event.getPosition().getX(), (float32)event.getPosition().getY());
		currentScene->MouseMove(ps);

	};

	ScopedPointer<b2SceneBase> currentScene;
};