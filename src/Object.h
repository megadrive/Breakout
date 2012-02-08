
#ifndef __OBJECT_H
#define __OBJECT_H

/**
 * Object
 * @brief	Used as a basis of all things in each room. All objects should derive off this.
 *				Doesn't have a constructor because it's meant to be derived from.
 */

#include "Util.h"

class Object
{
public:
	enum TYPE
	{
		TYPE_UNASSIGNED = 0,
		TYPE_STATIC,
		TYPE_PLAYERCONTROLLED,
		TYPE_ENEMY,
		TYPE_TRIGGER,

		TYPE_COUNT
	};

	virtual ~Object();

	virtual RR_RESULT Create();
	virtual RR_RESULT Destroy();

        virtual RR_RESULT RemoveFromRoom();

protected:
	
};

#endif
