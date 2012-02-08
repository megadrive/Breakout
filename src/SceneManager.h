
#ifndef __SCENEMANAGER_H
#define __SCENEMANAGER_H

/**
 * SceneManager
 * @brief	Singleton. Handles pushing, popping and running of scenes.
 */

#include <vector>
#include "Util.h"

// forward declaration
class Scene;
typedef std::vector<Scene*> SceneVector;

class SceneManager
{
public:
	enum STATE
	{
		STATE_OK = 0,
		STATE_POPOFF,
		STATE_PUSHON,
		STATE_UNLOAD,

		STATE_COUNT
	};

	~SceneManager();

	static SceneManager* GetInstance();
	RR_RESULT Destroy();

	RR_RESULT AddScene(Scene* a_pScene);
	RR_RESULT DestroyAllScenes();

	RR_RESULT RunBackScene(float a_fDeltaTime);

	SceneVector m_scenes;

private:
	SceneManager();

	static SceneManager* m_pInstance;
};

#endif
