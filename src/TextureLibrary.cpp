
#include "TextureLibrary.h"

/* static */ TextureLibrary* TextureLibrary::m_pInstance = 0;

TextureLibrary::TextureLibrary()
{

}

TextureLibrary::~TextureLibrary()
{

}

/* static */ TextureLibrary* TextureLibrary::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new TextureLibrary;
	}

	return m_pInstance;
}
