//-----------------------------------------------------------------------------
//Author: Tom solarino
//Description: This is where players go to join a game
//-----------------------------------------------------------------------------

#ifndef SETTINGS_STATE
#define SETTINGS_STATE
#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

struct GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class SettingsState : public IGameState
{
public:
	SettingsState(Application *a_application);
	virtual ~SettingsState();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);
	
private:
	void DrawBackground();
	void Load();

private:
	Texture *m_backgroundTexture;
	Texture *m_backButtonTexture;

	Button *m_backButton;

	std::vector<Button*> m_allButtons;

	SpriteBatch_Imidiate *m_SBI;
};

#endif