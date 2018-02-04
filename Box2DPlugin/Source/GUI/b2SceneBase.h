/*
  ==============================================================================

    b2SceneBase.h
    Created: 2 Feb 2018 2:35:46am
    Author:  COx2

  ==============================================================================
*/

#pragma once

// (These classes and random functions are used inside the 3rd-party Box2D demo code)
inline float32 RandomFloat() { return Random::getSystemRandom().nextFloat() * 2.0f - 1.0f; }
inline float32 RandomFloat(float32 lo, float32 hi) { return Random::getSystemRandom().nextFloat() * (hi - lo) + lo; }

struct b2Settings
{
	b2Vec2 viewCenter{ 0.0f, 20.0f };
	float32 hz = 60.0f;
	int velocityIterations = 8;
	int positionIterations = 3;
	int drawShapes = 1;
	int drawJoints = 1;
	int drawAABBs = 0;
	int drawPairs = 0;
	int drawContactPoints = 0;
	int drawContactNormals = 0;
	int drawContactForces = 0;
	int drawFrictionForces = 0;
	int drawCOMs = 0;
	int drawStats = 0;
	int drawProfile = 0;
	int enableWarmStarting = 1;
	int enableContinuous = 1;
	int enableSubStepping = 0;
	int pause = 0;
	int singleStep = 0;
};

class b2SceneBase
{
public:
    // Construct with default gravity.
	b2SceneBase() : m_world(new b2World(b2Vec2(0.0f, -10.0f))) {}
	
	virtual ~b2SceneBase() {}

	virtual void Keyboard(unsigned char /*key*/) {}
	virtual void KeyboardUp(unsigned char /*key*/) {}
	virtual void MouseDown(const b2Vec2& p) {};
	virtual void MouseUp(const b2Vec2& p) {};
	virtual void MouseMove(const b2Vec2& p) {};
	virtual void Update(b2Settings* settings) {};

	ScopedPointer<b2World> m_world;

private:
};