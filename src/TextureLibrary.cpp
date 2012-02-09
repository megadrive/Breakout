
#include "TextureLibrary.h"

/* static */ TextureLibrary* TextureLibrary::m_pInstance = 0;

TextureLibrary::TextureLibrary()
{

}

TextureLibrary::~TextureLibrary()
{

}

/**
 * Gets the instance of TextureLibrary. If it doesn't exist, create it.
 */
/* static */ TextureLibrary* TextureLibrary::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new TextureLibrary;
	}

	return m_pInstance;
}

/**
 * Destroys the instance of TextureLibrary if it exists.
 */
RR_RESULT TextureLibrary::Destroy()
{
	if( m_pInstance )
	{
		if( RR_RESULT_OK == DestroyAllTextures() )
		{
			delete m_pInstance;
			m_pInstance = 0;
		}

		return RR_RESULT_OK;
	}

        LOG("Could not destroy TextureLibrary instance.");
	return RR_RESULT_ERROR;
}

/**
 * Adds a texture to the TextureLibrary.
 * TODO: This should have a validation before adding it to the map.
 */
int TextureLibrary::AddTexture( std::string a_pathToTexture )
{
	TextureMap::iterator interTexture = m_textures.find(a_pathToTexture);

	if( interTexture == m_textures.end() )
	{
		m_textures.insert( std::make_pair(a_pathToTexture, 0) );
		return (m_textures.find(a_pathToTexture))->second;
	}

	return interTexture->second;
}

/**
 * Destroys all textures.
 */
RR_RESULT TextureLibrary::DestroyAllTextures()
{
	int* pTextures = (int*)malloc(sizeof(int) * m_textures.size());

	TextureMap::iterator interTexture = m_textures.begin();
	for(int i = 0; interTexture != m_textures.end(); ++interTexture, ++i)
	{
		pTextures[i * sizeof(int)] = interTexture->second;
	}

	m_textures.clear();

	//glDeleteTextures(pTextures, m_textures.size());
	free(pTextures);
	pTextures = NULL;

	if( m_textures.size() == 0 )
	{
		return RR_RESULT_OK;
	}

        LOG("Could not destroy all Textures");
	return RR_RESULT_ERROR;
}

/**
 * Destroys a_iSize number of textures, as defined in aiTextureIds.
 * a_aiTextureIds is an array of integers.
 */
RR_RESULT TextureLibrary::DestroyTextureByIds(int* a_aiTextureIds, int a_iSize)
{
        if( a_iSize <= 0 )
        {
                LOG("Size is <0.");
                return RR_RESULT_ERROR;
        }

        if( a_aiTextureIds == NULL )
        {
                LOG("TextureIds is NULL");
                return RR_RESULT_ERROR;
        }


}
