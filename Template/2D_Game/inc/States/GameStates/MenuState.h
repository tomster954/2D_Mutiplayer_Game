//-----------------------------------------------------------------------------
//Author: Tom Solarino	
//Description: Main Menu State
//-----------------------------------------------------------------------------

#ifndef MENU_STATE
#define MENU_STATE
#include "Managers\GameStateManager.h"

struct GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class MenuState : public IGameState
{
public:
	MenuState(Application *a_appication);
	virtual ~MenuState();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

	void TestDrawing();

private:
	Texture* m_texture1;

	int m_windowWidth;
	int m_windowHeight;
};



#endif