
#include "MenuScene.h"

MenuScene::MenuScene()
{
	Create();
}

MenuScene::~MenuScene()
{
	Destroy();
}

/**
 * Create
 * @brief Fires when an object is created. Initialise object-specific variables in here.
 */
RR_RESULT MenuScene::Create()
{
	return RR_RESULT_OK;
}

/**
 * Destroy
 * @brief Fires when an object is destroyed. Uninitialise anything you did in Create.
 */
RR_RESULT MenuScene::Destroy()
{
	return RR_RESULT_OK;
}

/**
 * Update
 * @brief	Updates this object based on the Delta time.
 * @param	float	a_fDeltaTime
 */
void MenuScene::Update( float a_fDeltaTime )
{

}

/**
 * Render
 * @brief Renders this object to the buffer.
 * TODO: Add deferred rendering by adding each object to a queue.
 * TODO: Possibly define this in Object then only override if the Object requires a custom Render.
 */
void MenuScene::Render()
{

}
