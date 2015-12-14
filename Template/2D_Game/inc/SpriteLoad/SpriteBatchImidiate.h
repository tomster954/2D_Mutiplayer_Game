//-----------------------------------------------------------------------------
//Author: Tom Solarino
//Description: This is a sprite rendering class
//-----------------------------------------------------------------------------

#ifndef SPRITEBATCH_IMIDIATE_H
#define SPRITEBATCH_IMIDIATE_H
class Texture;
struct GLFWwindow;

class SpriteBatch_Imidiate
{
public:

	SpriteBatch_Imidiate(GLFWwindow* a_pWindow);
	~SpriteBatch_Imidiate();

	void Begin();
	void End();

	void DrawSprite(Texture *texture, float xPos, float yPos, float width, float height);

	void DrawLine(float a_pos1X, float a_pos1Y, float a_pos2X, float a_pos2Y);
	void SetColor(float r, float g, float b, float a);

protected:
private:
	GLFWwindow* m_pWindow;

	int m_windowWidth;
	int m_windowHeight;

	float m_red;
	float m_green;
	float m_blue;
	float m_alpha;
};

#endif