/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 */

#include "Program.h"
#include "GameWindow.h"
#include "ObjectPool.h"
#include "Graphics.h"

Program::Program() {
}

Program::~Program() {
}

const std::string cGameTitle = "PolygonShooter";

void Program::run() {
	GameWindow gameWin;
	Graphics settings;
	sf::Clock gameClock;
	sf::Time frameTime;
	sf::Event eventHandler;
	ObjectPool BgLayer;
	sf::Uint32 winStyle;
	
	winStyle = settings.getFullscreenSet() == true ? sf::Style::Fullscreen : sf::Style::Default;
	gameWin.create(settings.getVideoMode(), cGameTitle, winStyle);
	
	while(gameWin.isOpen()) {
		if(gameWin.pollEvent(eventHandler)) {
			if(eventHandler.type == sf::Event::Closed) {
				gameWin.close();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				gameWin.close();
			}
		}
		
		if(gameClock.getElapsedTime() >= sf::seconds(1.0/settings.getTargetFramerate())) {
			gameWin.display();
		}
	}
}
