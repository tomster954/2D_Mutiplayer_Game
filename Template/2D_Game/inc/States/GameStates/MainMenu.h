//-----------------------------------------------------------------------------
//Author: Tom Solarino	
//Description: Main Menu State
//-----------------------------------------------------------------------------

#ifndef MAIN_MENU
#define MAIN_MENU
#include "Managers\GameStateManager.h"

struct GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class MainMenu : public IGameState
{
public:
	MainMenu(Application *a_appication);
	virtual ~MainMenu();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

	void TestDrawing();

private:
	Texture* m_texture1;

	int m_windowWidth;
	int m_windowHeight;
};



#endif