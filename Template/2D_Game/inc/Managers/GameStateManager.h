//-----------------------------------------------------------------------------
//Author: Tom Solarino
//Description: This is a game state manager that controls what state should be updated
//-----------------------------------------------------------------------------

#ifndef GAME_STATE_MANAGER
#define GAME_STATE_MANAGER
#include "glfw3.h"
#include <map>
#include <vector>

struct GLFWwindow;
class SpriteBatch_Imidiate;
class Application;

class IGameState
{
public:
	IGameState(Application *a_appication);
	virtual ~IGameState();

	//virtual void Initialise(GLFWwindow *a_pWindow);
	virtual void Update(float a_dt);
	virtual void Draw(SpriteBatch_Imidiate *a_SBI);

	bool m_blockUpdate;
	bool m_blockDraw;

	int m_windowWidth;
	int m_windowHeight;

protected:
	Application *m_pApplication;
};

class GameStateManager
{
public:
	GameStateManager();
	virtual ~GameStateManager();

	void UpdateGameStates(float dt);
	void DrawGameStates(SpriteBatch_Imidiate *a_SBI);

	void SetState(const char *name, IGameState *pState);
	void PushState(const char *name);
	void PopState();

protected:
	void ProcessCommands();

	//A map of all available states
	std::map< const char *, IGameState * > m_availableStates;

	//The state that we want updated and drawn
	std::vector< IGameState * > m_gameStateStack;

	//Enums
	enum ECommands
	{
		E_PUSH,
		E_POP,
	};

	// a commands structure
	struct SCommands
	{
		const char *name;
		ECommands cmd;
	};

	//Vector of commands
	std::vector< SCommands > m_commands;


private:

};

#endif