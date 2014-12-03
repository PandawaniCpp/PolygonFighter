/** @author Adam Olękiewicz
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
#include <SFML/Graphics.hpp>

class ProgramObject {
public:
	ProgramObject();
	virtual ~ProgramObject();

	virtual void handleInput(sf::Event &eventHandler) =0;
	virtual void update() =0;
	virtual void render() =0;

	unsigned int getObjectId();
private:
	unsigned int mObjectId;
};

extern std::vector<ProgramObject*> sGlogalObject;

#endif	/* OBJECTPOOL_H */

