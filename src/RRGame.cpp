
#include "RRGame.h"
#include "Util.h"

#include "SceneManager.h"
#include "TextureLibrary.h"

RRGame::RRGame()
{
	Create();
}

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
 * Destroys all initialised objects.
 * Typically anything created in Create() should be destroyed here.
 */
void RRGame::Destroy()
{
	SceneManager::GetInstance()->Destroy();
	TextureLibrary::GetInstance()->Destroy();

	m_bRunning = false;
}

/**
 * The main game loop.
 */
RR_RESULT RRGame::Run()
{
        int i = 0;
	while( SceneManager::GetInstance()->m_scenes.size() )
	{
                // TODO: Temporary stuff.
                if( i < 10 )
                {
                        printf("Game is running.\n");
                        ++i;
                }
	}

	return RR_RESULT_OK;
}
