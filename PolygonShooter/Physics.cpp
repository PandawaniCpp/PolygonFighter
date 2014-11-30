#include "Physics.h"

void Physics::update(float dt)
{
}

Physics::Physics() : mWorld(b2Vec2(0.0f,0.0f))
{
	cGravity = 9.8123f;

	cWall.SetAsBox(1.0f,1.0f);

	cHuman.m_radius = 0.25f;
}

Physics::~Physics()
{
}
