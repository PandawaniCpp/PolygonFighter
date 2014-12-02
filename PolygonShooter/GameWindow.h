/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Class GameWindow:
 * - draws and handles basic tasks related to main window
 */

#ifndef GAMEWINDOW_H
#define	GAMEWINDOW_H

#include "Game.h"
#include "ObjectPool.h"
#include <SFML/Graphics.hpp>

class GameWindow: public sf::RenderWindow {
public:
	GameWindow();
	virtual ~GameWindow();
	
private:

};

#endif	/* GAMEWINDOW_H */
