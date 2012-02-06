
#ifndef __TEXTURELIBRARY_H
#define __TEXTURELIBRARY_H

/**
 * TextureLibrary
 * @brief	Singleton. Handles loading and unloading of textures.
 */

#include <vector>

class TextureLibrary
{
public:
	~TextureLibrary();

	static TextureLibrary* GetInstance();

private:
	TextureLibrary();

	static TextureLibrary* m_pInstance;
};

#endif
