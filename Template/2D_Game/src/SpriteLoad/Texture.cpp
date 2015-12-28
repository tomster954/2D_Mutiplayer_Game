#include "SpriteLoad\Texture.h"

#include "SpriteLoad\lodepng.h"
#include "glfw3.h"
#include <vector>
Texture::Texture()
{

}

Texture::Texture(const char *filename)
{
	m_repeat = false;
	m_glTextureHandle = LoadTexture(filename, &m_width, &m_height);
	
	m_OriginalWidth = m_width;
	m_OriginalHeight = m_height;
}

Texture::~Texture()
{
	DeleteTexture(m_glTextureHandle);
}

unsigned int Texture::LoadTexture(const char *filename, unsigned int *out_width, unsigned int *out_height)
{
	std::vector<unsigned char> pixels;

	unsigned int w, h;
	lodepng::decode(pixels, w, h, filename);

	if (out_width != NULL)		*out_width = w;
	if (out_height != NULL)		*out_height = h;

	unsigned int textID;

	glGenTextures(1, &textID);
	glBindTexture(GL_TEXTURE_2D, textID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	return textID;
}


void Texture::DeleteTexture(unsigned int textureID)
{
	glDeleteTextures(1, &textureID);
}
