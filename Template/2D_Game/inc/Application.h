//-----------------------------------------------------------------------------
//Author: Tommas Solarino
//Description: Is called in the Application class
//-----------------------------------------------------------------------------

#ifndef STARTUP
#define STARTUP
#include "States\GameStates\MainMenu.h"

struct GLFWwindow;
class SpriteBatch_Imidiate;

class Application
{
public:
	Application();
	~Application();

	//Set up GLFW
	void SetUpGLFW();

	void Update();
	void Draw();

	void Run();
private:
	GLFWwindow* m_pWindow;
	MainMenu m_menuState;
	SpriteBatch_Imidiate* m_SBI;
	
	float m_currentTime = 0.0f;
	float m_deltaTime = 0.0f;
	float m_lastTime = 0.0f;
};
#endif