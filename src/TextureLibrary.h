
#ifndef __TEXTURELIBRARY_H
#define __TEXTURELIBRARY_H

/**
 * TextureLibrary
 * @brief	Singleton. Handles loading and unloading of textures.
 */

#include <map>
#include <string>

#include "Util.h"

typedef std::map<std::string, int> TextureMap;

class TextureLibrary
{
public:
	~TextureLibrary();

	static TextureLibrary* GetInstance();
	RR_RESULT Destroy();

	int AddTexture(std::string a_pathToTexture);

	RR_RESULT DestroyAllTextures();

private:
	TextureLibrary();

	static TextureLibrary* m_pInstance;
	TextureMap m_textures;
};

#endif
