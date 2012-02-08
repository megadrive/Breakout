
#ifndef __MENUSCENE_H
#define __MENUSCENE_H

/**
 * MenuScene
 * @brief	
 */

#include "Util.h"

class MenuScene
{
public:
	MenuScene();
	virtual ~MenuScene();

	virtual RR_RESULT Create();
	virtual RR_RESULT Destroy();
	
	virtual void Update(float a_fDeltaTime);
	virtual void Render();
};

#endif
