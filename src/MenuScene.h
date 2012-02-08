
#ifndef __MENUSCENE_H
#define __MENUSCENE_H

/**
 * MenuScene
 * @brief	
 */

#include "Scene.h"
#include "Util.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	virtual ~MenuScene();

	virtual RR_RESULT Create();
	virtual RR_RESULT Destroy();
	
	virtual SceneManager::STATE Update(float a_fDeltaTime);
	virtual void Render();
	virtual SceneManager::STATE Run(float a_fDeltaTime);
};

#endif
