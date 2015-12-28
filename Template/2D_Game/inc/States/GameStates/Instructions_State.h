//-----------------------------------------------------------------------------
//Author: Tom Solarino
//Description: This is the instructions state that shows player controls ect.
//-----------------------------------------------------------------------------

#ifndef INSTRUCTIONS_STATE
#define INSTRUCTIONS_STATE
#include "Managers\GameStateManager.h"

class Instructions_State : public IGameState
{
public:
	Instructions_State(Application *a_application);
	virtual ~Instructions_State();

	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

private:
	int m_windowWidth;
	int m_windowHeight;
};

#endif