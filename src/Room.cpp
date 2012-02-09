
#include "Room.h"
#include "Object.h"

Room::Room()
{

}

Room::~Room()
{

}

/**
 * Add an object for updating and rendering.
 * To remove objects, call RemoveAllObjects or call RemoveFromRoom on the Object itself.
 */
RR_RESULT Room::AddObject(Object* a_pObject)
{
	if( a_pObject )
	{
		m_objects.push_back(a_pObject);
		return RR_RESULT_OK;
	}

        LOG("Could not add object to Room. %s");
	return RR_RESULT_ERROR;
}

/**
 * Remove all objects from the room.
 */
RR_RESULT Room::RemoveAllObjects( bool a_bDestroy = false )
{
	if( m_objects.size() )
	{
		for( ObjectVector::reverse_iterator iter = m_objects.rbegin(); iter != m_objects.rend(); ++iter )
		{
			Object* pObject = *iter;

			if( a_bDestroy )
			{
				pObject->Destroy();
			}

			m_objects.pop_back();
		}
	}
	else
	{
		return RR_RESULT_ERROR;
	}

	return RR_RESULT_OK;
}

