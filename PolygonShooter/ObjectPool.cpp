/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 */

#include "ObjectPool.h"

std::vector<ProgramObject*> sGlogalObject;

ProgramObject::ProgramObject() {
	this->mObjectId = sGlogalObject.size();
	sGlogalObject.push_back(this);
}

ProgramObject::~ProgramObject() {

}

unsigned int ProgramObject::getObjectId() {
	return this->mObjectId;
}

void ProgramObject::handleInput(sf::Event &eventHandler) {

}

void ProgramObject::update() {

}

void ProgramObject::render() {

}
