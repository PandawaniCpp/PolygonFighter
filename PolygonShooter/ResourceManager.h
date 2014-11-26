/** @author adam
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Class ResourceManager: 
 * [todo] - cares about loading resources, such as textures, to memory
 * [todo] - organizes objects
 * [todo] - provides adequate access scope for objects
 */

#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include <vector>

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();
	
private:

};

class Resource {
public:
	Resource();
	~Resource();
	
	unsigned int getObjectId();
	
private:
	unsigned int mObjectId;
};

#endif	/* RESOURCEMANAGER_H */
