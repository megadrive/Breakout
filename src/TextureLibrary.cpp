
#include "TextureLibrary.h"

/* static */ TextureLibrary* TextureLibrary::m_pInstance = 0;

/**
 * 
 */
TextureLibrary::TextureLibrary()
{

}

/**
 * 
 */
TextureLibrary::~TextureLibrary()
{

}

/**
 *
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
 *
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

	return RR_RESULT_ERROR;
}

/**
 *
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
 *
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

	return RR_RESULT_ERROR;
}
