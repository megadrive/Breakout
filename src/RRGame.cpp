
#include "RRGame.h"
#include "Util.h"

#include "SceneManager.h"
#include "TextureLibrary.h"

/**
 * 
 */
RRGame::RRGame()
{
	Create();
}

/**
 * 
 */
RRGame::~RRGame()
{
	Destroy();
}

/**
 * Creates the initial game state.
 */
void RRGame::Create()
{
	// Create singletons.
	SceneManager::GetInstance();
	TextureLibrary::GetInstance();

	m_bRunning = true;
}

/**
 * 
 */
void RRGame::Destroy()
{
	SceneManager::GetInstance()->Destroy();
	TextureLibrary::GetInstance()->Destroy();

	m_bRunning = false;
}

/**
 * Run
 * The main game loop.
 */
RR_RESULT RRGame::Run()
{
	while( SceneManager::GetInstance()->m_scenes.size() )
	{
		if( SceneManager::GetInstance()->RunBackScene(0.0f) )
	}

	return RR_RESULT_OK;
}
