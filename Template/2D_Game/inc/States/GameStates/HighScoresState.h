//-----------------------------------------------------------------------------
//Author: Tom solarino
//Description: This is where players go to join a game
//-----------------------------------------------------------------------------

#ifndef HIGH_SCORES_STATE
#define HIGH_SCORES_STATE
#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

class GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class HighScoresState : public IGameState
{
public:
	HighScoresState(Application *a_application);
	virtual ~HighScoresState();
	void Load();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

	void DrawBackground();

private:
	Texture *m_backgroundTexture;
	Texture *m_backButtonTexture;

	Button *m_backButton;

	std::vector<Button*> m_allButtons;

	SpriteBatch_Imidiate *m_SBI;
};

#endif