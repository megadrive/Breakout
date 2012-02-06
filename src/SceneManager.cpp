
#include "SceneManager.h"

/* static */ SceneManager* SceneManager::m_pInstance = 0;

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

/* static */ SceneManager* SceneManager::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new SceneManager;
	}

	return m_pInstance;
}
