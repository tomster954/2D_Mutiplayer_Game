//-----------------------------------------------------------------------------
//Author: Tom solarino
//Description: This is the main play state where the game is played
//-----------------------------------------------------------------------------

#ifndef PLAY_STATE
#define PLAY_STATE
#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

class GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class PlayState : public IGameState
{
public:
	PlayState(Application *a_application);
	virtual ~PlayState();
	void Load();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

private:
	void DrawMap();

private:
	Texture *m_backgroundTexture;
	Texture *m_Buttontxture;

	Button *m_pauseButton;

	SpriteBatch_Imidiate *m_SBI;
};

#endif