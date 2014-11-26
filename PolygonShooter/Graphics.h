/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Class Graphics:
 * - Allows to manage display parameters
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include <vector>
#include <SFML/Window/VideoMode.hpp>

class Graphics {
public:
	Graphics();
	virtual ~Graphics();
	
	sf::VideoMode getVideoMode();
	void setVideoMode(const sf::VideoMode newMode);
	bool getFullscreenSet();
	void setFullscreenSet(const bool flag);
	float getTargetFramerate();
	void setTargetFramerate(const unsigned int newFramerate);
	
	std::vector<sf::VideoMode> sAvailableModes;
private:
	sf::VideoMode mCurrentVideoMode;
	float mTargetFramerate;
	bool mFullscreenSet;
};

#endif	/* GRAPHICS_H */

