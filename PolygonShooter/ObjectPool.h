/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Class ObjectPool:
 * - provides cool access to objects
 */

#ifndef OBJECTPOOL_H
#define	OBJECTPOOL_H

#include <vector>
#include "Game.h"

class GameObject;

class ObjectPool {
public:
	ObjectPool();
	~ObjectPool();

	std::vector<GameObject*> gameObject;
};

class GameObject: public Game {
public:
	GameObject();
	~GameObject();
	
	//void handleInput();
	//void update();
	//void render();
	
	unsigned int getObjectId();
private:
	unsigned int mObjectId;
};

#endif	/* OBJECTPOOL_H */

