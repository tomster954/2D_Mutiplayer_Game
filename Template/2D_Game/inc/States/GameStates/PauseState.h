//-----------------------------------------------------------------------------
//Author: Tom solarino
//Description: This is where players go to join a game
//-----------------------------------------------------------------------------

#ifndef PAUSE_STATE
#define PAUSE_STATE
#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

class GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class PauseState : public IGameState
{
public:
	PauseState(Application *a_application);
	virtual ~PauseState();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

private:
	void DrawBackground();
	void Load();
	void LoadTextures();
	void LoadButtons();
	
private:
	//Background texture
	Texture *m_backgroundTexture;

	//Button Textures
	Texture *m_backButtonTexture;
	Texture *m_tHScores;
	Texture *m_tSettings;
	Texture *m_tInstructions;
	Texture *m_tQuit;

	//Buttons
	Button *m_backButton;
	Button *m_bHScores;
	Button *m_bSettings;
	Button *m_bInstructions;
	Button *m_bQuit;

	//all buttons
	std::vector<Button*> m_allButtons;

	//Sprite batch
	SpriteBatch_Imidiate *m_SBI;
};

#endif