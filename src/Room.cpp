
#include "Room.h"

Room::Room()
{

}

Room::~Room()
{

}

/**
 * AddObject
 * @brief Add an object for updating and rendering.
 *				To remove objects, call RemoveAllObjects or call RemoveFromRoom on the Object itself.
 * @param	Object a_pObject
 */
RR_RESULT Room::AddObject(Object* a_pObject)
{
	return RR_RESULT_OK;
}

/**
 * RemoveAllObjects
 * @brief Remove all objects from the room.
 */
RR_RESULT Room::RemoveAllObjects()
{
        return RR_RESULT_OK;
}

