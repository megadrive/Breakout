
#ifndef __MENUSCENE_H
#define __MENUSCENE_H

/**
 * MenuScene
 * @brief	
 */

class MenuScene
{
public:
	MenuScene();
	virtual ~MenuScene();

	virtual void Update(float a_fDeltaTime);
	virtual void Render();
};

#endif
