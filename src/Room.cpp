
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
	if( a_pObject )
	{
		m_vObjects.push_back(a_pObject);
		return RR_RESULT_OK;
	}

	return RR_RESULT_ERROR;
}

/**
 * RemoveAllObjects
 * @brief Remove all objects from the room.
 */
RR_RESULT Room::RemoveAllObjects( bool a_bDestroy = false )
{
	if( m_vObjects.size() )
	{
		for( ObjectVector::iterator iter = m_vObjects.end(); iter != m_vObjects.start(); --iter )
		{
			if( a_bDestroy )
			{
				Object* pObject = *iter;
				pObject->Destroy();
				m_vObjects.pop_back();
			}
		}
	}
	else
	{
		return RR_RESULT_ERROR;
	}

        return RR_RESULT_OK;
}

