
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
 * Gets the instance of the SceneManager. If it doesn't exist, create it.
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
 * Destroys the instance of SceneManager if it exists.
 * Also destroys any still-loaded Scenes.
 * @return RR_RESULT_OK if successful, RR_RESULT_ERROR otherwise.
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
                                if( pScene->Destroy() == RR_RESULT_ERROR )
                                        break;
				delete pScene;
			}

			m_scenes.clear();

			return RR_RESULT_OK;
		}
	}

	return RR_RESULT_ERROR;
}

/**
 * Adds a Scene to the SceneManager if non-NULL.
 * @return RR_RESULT_OK if successful, RR_RESULT_WARNING otherwise.
 */

RR_RESULT SceneManager::AddScene( Scene* a_pScene )
{
	if( a_pScene )
	{
		m_scenes.push_back(a_pScene);
		return RR_RESULT_OK;
	}

	return RR_RESULT_WARNING;
}

/**
 * Destroys all scenes.
 */

RR_RESULT SceneManager::DestroyAllScenes()
{
        int iNumScenes = m_scenes.size();

	SceneVector::iterator interScene = m_scenes.begin();
	for(int i = 0; interScene != m_scenes.end(); ++interScene, ++i)
	{
		Scene* pScene = *interScene;
                if( pScene->Destroy() == RR_RESULT_ERROR )
                        break;
		delete pScene;
		*interScene = NULL;
	}

        if( iNumScenes == i )
        	m_scenes.clear();

	if( m_scenes.size() == 0 )
	{
		return RR_RESULT_OK;
	}

	return RR_RESULT_ERROR;
}

/**
 * Runs the Scene on the back of the vector.
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
