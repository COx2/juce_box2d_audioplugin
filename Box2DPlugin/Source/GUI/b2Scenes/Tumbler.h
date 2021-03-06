/*
  ==============================================================================

    Tumbler.h
    Created: 2 Feb 2018 2:40:44am
    Author:  COx2

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../b2SceneBase.h"
#include "../b2Tools/RayCastTools.h"

#include <queue>

class Tumbler : public b2SceneBase
{
public:

	enum
	{
		e_count = 800
	};

	Tumbler()
	{
		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = m_world->CreateBody(&bd);
		}

		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.allowSleep = false;
			bd.position.Set(0.0f, 10.0f);
			b2Body* body = m_world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 10.0f, b2Vec2( 10.0f, 0.0f), 0.0);
			body->CreateFixture(&shape, 5.0f);
			shape.SetAsBox(0.5f, 10.0f, b2Vec2(-10.0f, 0.0f), 0.0);
			body->CreateFixture(&shape, 5.0f);
			shape.SetAsBox(10.0f, 0.5f, b2Vec2(0.0f, 10.0f), 0.0);
			body->CreateFixture(&shape, 5.0f);
			shape.SetAsBox(10.0f, 0.5f, b2Vec2(0.0f, -10.0f), 0.0);
			body->CreateFixture(&shape, 5.0f);

			b2RevoluteJointDef jd;
			jd.bodyA = ground;
			jd.bodyB = body;
			jd.localAnchorA.Set(0.0f, 10.0f);
			jd.localAnchorB.Set(0.0f, 0.0f);
			jd.referenceAngle = 0.0f;
			jd.motorSpeed = 0.05f * b2_pi;
			jd.maxMotorTorque = 1e8f;
			jd.enableMotor = true;
			m_joint = (b2RevoluteJoint*)m_world->CreateJoint(&jd);
		}

		m_count = 0;
	}

	void Update(b2Settings* settings) override
	{
		if (m_count < e_count)
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 10.0f);
			b2Body* body = m_world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.125f, 0.125f);
			body->CreateFixture(&shape, 1.0f);

			particle_refs.push(body);

			++m_count;

		}
		
		if (m_count > 300) {
			b2Body* target = particle_refs.front();
			m_world->DestroyBody(target);
			particle_refs.pop();

			--m_count;
		}

		m_world->Step(1.0/settings->hz, settings->velocityIterations, settings->positionIterations);

	}

	void MouseDown(const b2Vec2& point) override
	{
		RayCastBodyCallback callback;
		b2Vec2 delta(2.0, 2.0);
		b2Vec2 point1(0.0f, 0.0f);
		m_world->RayCast(&callback, point, point1);

		if (callback.m_body) 
		{
//			m_world->DestroyBody(callback.m_body);
			callback.m_body->ApplyForce(point, point1);
		}

	};

	static b2SceneBase* Create()
	{
		return new Tumbler;
	}

	b2RevoluteJoint* m_joint;
	int32 m_count;

	std::queue<b2Body*> particle_refs;
};