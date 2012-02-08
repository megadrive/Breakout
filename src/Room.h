
#ifndef __ROOM_H
#define __ROOM_H

/**
 * Room
 * @brief Describes a room. A room consists of Objects.
 */

#include <vector>
#include "Util.h"

// forward declaration
class Object;
typedef std::vector<Object*> ObjectVector;

class Room
{
public:
	Room();
	~Room();

	RR_RESULT AddObject( Object* a_pObject );
	
protected:
	ObjectVector m_objects;
};

#endif
