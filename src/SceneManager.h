
#ifndef __SCENEMANAGER_H
#define __SCENEMANAGER_H

/**
 * SceneManager
 * @brief	Singleton. Handles pushing, popping and running of scenes.
 */

#include <vector>

// forward declaration
class Scene;
typedef std::vector<Scene*> SceneVector;

class SceneManager
{
public:
	~SceneManager();

	static SceneManager* GetInstance();

	SceneVector m_vScenes;

private:
	SceneManager();

	static SceneManager* m_pInstance;
};

#endif
