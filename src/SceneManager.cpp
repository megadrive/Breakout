
#include "SceneManager.h"
#include "Scene.h"

/* static */ SceneManager* SceneManager::m_pInstance = 0;

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

/**
 *
 */
/* static */ SceneManager* SceneManager::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new SceneManager;
	}

	return m_pInstance;
}

/**
 *
 */

RR_RESULT SceneManager::Destroy()
{
	if( RR_RESULT_OK == DestroyAllScenes() )
	{

		if( m_scenes.size() )
		{
			SceneVector::iterator iterScene = m_scenes.begin();
			for(; iterScene != m_scenes.end(); ++iterScene)
			{
				Scene* pScene = *iterScene;
				delete pScene;
			}

			m_scenes.clear();

			return RR_RESULT_OK;
		}
	}

	return RR_RESULT_ERROR;
}

/**
 *
 */

RR_RESULT SceneManager::AddScene( Scene* a_pScene )
{
	if( a_pScene )
	{
		m_scenes.push_back(a_pScene);
		return RR_RESULT_OK;
	}

	return RR_RESULT_ERROR;
}

/**
 *
 */

RR_RESULT SceneManager::DestroyAllScenes()
{
	SceneVector::iterator interScene = m_scenes.begin();
	for(int i = 0; interScene != m_scenes.end(); ++interScene, ++i)
	{
		Scene* pScene = *interScene;
		delete pScene;
		*interScene = NULL;
	}

	m_scenes.clear();

	if( m_scenes.size() == 0 )
	{
		return RR_RESULT_OK;
	}

	return RR_RESULT_ERROR;
}

/**
 * RunBackScene
 * @brief Runs the Scene on the back of the vector.
 */
RR_RESULT SceneManager::RunBackScene( float a_fDeltaTime )
{
	if( m_scenes.size() )
	{
		STATE eSceneState = m_scenes.back()->Run(a_fDeltaTime);

		if( eSceneState == STATE_OK )
		{
			return RR_RESULT_OK;
		}
	}

	return RR_RESULT_ERROR;
}
