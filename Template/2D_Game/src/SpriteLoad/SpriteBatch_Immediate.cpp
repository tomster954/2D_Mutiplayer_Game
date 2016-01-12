#include "SpriteLoad\SpriteBatch_Immediate.h"
#include "SpriteLoad\Texture.h"
#include "Matrix3.h"
#include "Vec2.h"

#include "glfw3.h"

SpriteBatch_Imidiate::SpriteBatch_Imidiate(GLFWwindow* a_pWindow)
{
	m_pWindow = a_pWindow;
	glfwGetWindowSize(m_pWindow, &m_windowWidth, &m_windowHeight);

	m_red	= 255.f;
	m_green	= 255.f;
	m_blue	= 255.f;
	m_alpha = 255.f;
}

SpriteBatch_Imidiate::~SpriteBatch_Imidiate()
{

}

void SpriteBatch_Imidiate::Begin()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION); // DEPRECIATED: shaders used instead - user to provide projection matrix to the shader
	glLoadIdentity();			 // sets the GL_PROJECTION matrix to the identity matrix

	// setup orthographic projection (for rendering 2D)
	// DEPRECIATED: the projection matrix would be sent to the active shader
	glOrtho(0.0f, m_windowWidth, m_windowHeight, 0, -1, 1);		// WINDOW ORIGIN: Top Left
	//	glOrtho(0.0f, windowWidth, 0, windowHeight, -1, 1);		// WINDOW ORIGIN: Bottom Left

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// DEPRECIATED: pixel shaders define the final color after rasterization step in the graphics pipeline
	glEnable(GL_TEXTURE_2D);

	// DEPRECIATED: again, Matrices do not exist on future versions of OpenGL.
	// a model view matrix would be sent to the shader... 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SpriteBatch_Imidiate::End()
{
	// if this was non-imidiate mode
	// we would need to finish rendering stuff here...
}

void SpriteBatch_Imidiate::DrawLine(float a_pos1X, float a_pos1Y, float a_pos2X, float a_pos2Y)
{
	//float x1 = Pos1.x;
	//float x2 = Pos2.x;
	//float y1 = Pos1.y;
	//float y2 = Pos2.y;

	glDisable(GL_TEXTURE_2D);
	glColor4f(m_red / 255.0f, m_green / 255.0f, m_blue / 255.0f, m_alpha / 255.0f);
	glBegin(GL_LINES);

	glVertex2f(a_pos1X, a_pos1Y);
	glVertex2f(a_pos2X, a_pos2Y);

	glEnd();
	glEnable(GL_TEXTURE_2D);

}

void SpriteBatch_Imidiate::SetColor(float r, float g, float b, float a)
{
	m_red = r;
	m_green = g;
	m_blue = b;
	m_alpha = a;
}

void SpriteBatch_Imidiate::DrawSprite(Texture *a_texture, const Mat3 a_transform, const Vec2 a_size)
{
	//repeats the texture however much
	float repeatX = 1.0f;
	float repeatY = 1.0f;

	float halfWidth = a_size.x	* 0.5f;
	float halfHeight = a_size.y	* 0.5f;

	//will repeat the texture if required
	if (a_texture->m_repeat)
	{
		repeatX = a_size.x / a_texture->GetOriginalSize().x;
		repeatY = a_size.y / a_texture->GetOriginalSize().y;
	}

	//Corners of the quad based of the image size
	Vec2 tl(-halfWidth, halfHeight);
	Vec2 tr(halfWidth, halfHeight);
	Vec2 br(halfWidth, -halfHeight);
	Vec2 bl(-halfWidth, -halfHeight);

	//Move the corner to the right pos
	tl = tl * a_transform;
	tr = tr * a_transform;
	br = br * a_transform;
	bl = bl * a_transform;

	if (a_texture != NULL)
	{
		glBindTexture(GL_TEXTURE_2D, a_texture->GetTextureHandle());
		glColor4f(m_red, m_green, m_blue, m_alpha);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0f,		repeatY);	glVertex2f(tl.x, tl.y);
		glTexCoord2f(repeatX,	repeatY);	glVertex2f(tr.x, tr.y);
		glTexCoord2f(repeatX,	0.0f);		glVertex2f(br.x, br.y);
		glTexCoord2f(0.0f,		0.0f);		glVertex2f(bl.x, bl.y);

		glEnd();
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glColor4f(m_red, m_green, m_blue, m_alpha);

		glBegin(GL_QUADS);

		glVertex2f(tl.x, tl.y);
		glVertex2f(tr.x, tr.y);
		glVertex2f(br.x, br.y);
		glVertex2f(bl.x, bl.y);

		glEnd();
		glEnable(GL_TEXTURE_2D);
	}
}

void SpriteBatch_Imidiate::DrawSprite(Texture *a_texture, Vec2 a_pos, Vec2 a_size)
{
	//repeats the texture however much
	float repeatX = 1.0f;
	float repeatY = 0.0f;

	//will repeat the texture if required
	if (a_texture->m_repeat)
	{
		repeatX = a_size.x / a_texture->GetOriginalSize().x;
		repeatY = a_size.y / a_texture->GetOriginalSize().y;
	}

	float xPos = a_pos.x;
	float yPos = a_pos.y;

	float width = a_size.x;
	float height = a_size.y;

	//If a width and height wasnt specified
	if (xPos == NULL)
		xPos = a_texture->GetSize().x;
	if (yPos == NULL)
		yPos = a_texture->GetSize().y;

	//If the texture is valid
	if (a_texture != NULL)
	{
		glBindTexture(GL_TEXTURE_2D, a_texture->GetTextureHandle());
		glColor4f(m_red, m_green, m_blue, m_alpha);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0f,		repeatY);	glVertex2f(xPos, yPos);
		glTexCoord2f(repeatX,	repeatY);	glVertex2f(xPos + width, yPos);
		glTexCoord2f(repeatX,	1.0f);		glVertex2f(xPos + width, yPos + height);
		glTexCoord2f(0.0f,		1.0f);		glVertex2f(xPos, yPos + height);

		glEnd();
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glColor4f(m_red, m_green, m_blue, m_alpha);

		glBegin(GL_QUADS);

		glVertex2f(xPos, yPos);
		glVertex2f(xPos + width, yPos);
		glVertex2f(xPos + width, yPos + height);
		glVertex2f(xPos, yPos + height);

		glEnd();
		glEnable(GL_TEXTURE_2D);
	}
}

