#ifndef _PHYSICS_H_
#define _PHYSICS_H

#include <Box2D/Box2D.h>

/*
	Maciej Bartłomiej Kruk
	m.b.kruk@gmail.com
*/

class Physics {

private:

	b2World mWorld;

	float cGravity;

	b2PolygonShape cWall;
	b2CircleShape cHuman;

public:

	float getGroundFriction(b2Vec2 pos);

	inline float getGravity()
	{
		return cGravity;
	}

	inline void setGravity(float g)
	{
		cGravity = g;
	}

	class Object
	{
	private:
		b2Body *pBody;
		b2Vec2 mLegsSpeed;
		float cMaxSpeed;
		float cFriction;
		float cRestitution;
	public:

		void createAsWall();
		void createAsHuman();

		inline b2Vec2 getPosition()
		{
			if(pBody)
				return pBody->GetPosition();
			return b2Vec2(0,0);
		}

		inline void setPosition(b2Vec2 p)
		{
			if(pBody)
				pBody->SetTransform(p,pBody->GetAngle());
		}
	};

	void update(float dt);

	Physics();
	~Physics();
};

#endif
