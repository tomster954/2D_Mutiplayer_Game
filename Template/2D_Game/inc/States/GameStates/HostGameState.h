//-----------------------------------------------------------------------------
//Author: Tom solarino
//Description: This is where players go to host a game
//-----------------------------------------------------------------------------

#ifndef HOST_GAME_STATE
#define HOST_GAME_STATE
#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

class GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class HostGameState : public IGameState
{
public:
	HostGameState(Application *a_application);
	virtual ~HostGameState();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

private:
	void Load();
	void DrawBackground();

private:
	Texture *m_backgroundTexture;
	Texture *m_backButtonTexture;

	Button *m_backButton;

	std::vector<Button*> m_allButtons;

	SpriteBatch_Imidiate *m_SBI;
};

#endif