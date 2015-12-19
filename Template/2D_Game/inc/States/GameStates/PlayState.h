//-----------------------------------------------------------------------------
//Author: Tom solarino
//Description: This is the main play state where the game is played
//-----------------------------------------------------------------------------

#ifndef PLAY_STATE
#define PLAY_STATE

class GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class PlayState
{
public:
	PlayState();
	~PlayState();
	void Initialise(GLFWwindow *a_pWindow);

	void Update(float a_dt);

	void Draw(SpriteBatch_Imidiate *a_SBI);

private:
	Texture *m_testBoxText;
	GLFWwindow *m_pWindow;
};

#endif