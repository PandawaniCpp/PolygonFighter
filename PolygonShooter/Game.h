/** @author adam
 *
 * Top-down survival post-apocalyptic shooter
 * 
 * Abstract class Game:
 * - wraps all methods of state Game
 */

#ifndef GAME_H
#define	GAME_H

#include "State.h"

class Game: public State {
public:
	Game();
	virtual ~Game();
	
	virtual void handleInput() =0;
	virtual void update() =0;
	virtual void render() =0;
	
private:

};

#endif	/* GAME_H */

