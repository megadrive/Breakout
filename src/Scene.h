#ifndef __SCENE_H
#define __SCENE_H

/**
 * Scene
 * @brief	Describes the base of a Scene. Any other scenes need to be derived off this.
 */

#include "Util.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();
	
	virtual RR_RESULT Create() = 0;
	virtual RR_RESULT Destroy() = 0;

	virtual void Update(float a_fDeltaTime) = 0;
	virtual void Render() = 0;
};

#endif
