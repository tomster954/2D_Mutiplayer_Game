//-----------------------------------------------------------------------------
//Author: Tom Solarino	
//Description: Main Menu State
//-----------------------------------------------------------------------------

#ifndef MENU_STATE
#define MENU_STATE
#include "Managers\GameStateManager.h"
#include <vector>
struct GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;
class Button;

class MenuState : public IGameState
{
public:
	MenuState(Application *a_application);
	virtual ~MenuState();

	void LoadTextures();
	void LoadButtons();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

	void TestDrawing();
	
private:
	Texture* m_tSinglePlayer;
	Texture* m_tJoinGame;
	Texture* m_tHostGame;
	Texture* m_tInstructions;
	Texture* m_tSettings;
	Texture* m_tHScores;
	Texture* m_tQuit;

	Button* m_bSinglePlayer;
	Button* m_bJoinGame;
	Button* m_bHostGame;
	Button* m_bInstructions;
	Button* m_bSettings;
	Button* m_bHScores;
	Button* m_bQuit;

	std::vector<Button*> m_buttons;

	int m_windowWidth;
	int m_windowHeight;
};



#endif