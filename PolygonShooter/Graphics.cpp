/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Class Graphics:
 * - manages display settings for game (to be controlled through menu)
 */

#include "Graphics.h"

const float cDefaultFramerate = 60;
const bool cDefaultFullscreenSet = false;

Graphics::Graphics():
	mCurrentVideoMode(sf::VideoMode::getDesktopMode()),
	mTargetFramerate(cDefaultFramerate),
	mFullscreenSet(cDefaultFullscreenSet) {
	this->sAvailableModes = sf::VideoMode::getFullscreenModes();
}

Graphics::~Graphics() {
}

bool Graphics::getFullscreenSet() {
	return this->mFullscreenSet;
}

float Graphics::getTargetFramerate() {
	return this->mTargetFramerate;
}

sf::VideoMode Graphics::getVideoMode() {
	return this->mCurrentVideoMode;
}

void Graphics::setFullscreenSet(const bool flag) {
	this->mFullscreenSet = flag;
}

void Graphics::setTargetFramerate(const unsigned int newFramerate) {
	this->mTargetFramerate = newFramerate;
}

void Graphics::setVideoMode(const sf::VideoMode newMode) {
	this->mCurrentVideoMode = newMode;
}
