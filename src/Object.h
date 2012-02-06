
#ifndef __OBJECT_H
#define __OBJECT_H

/**
 * Object
 * @brief	Used as a basis of all things in each room. All objects should derive off this.
 *			Doesn't have a constructor because it's meant to be derived from.
 */

class Object
{
	enum TYPE
	{
		TYPE_UNASSIGNED = 0,
		TYPE_PLAYERCONTROLLED,
		TYPE_ENEMY,
		TYPE_TRIGGER
	};

	virtual ~Object();
};

#endif
