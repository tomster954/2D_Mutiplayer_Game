//-----------------------------------------------------------------------------
//Author: Tommas Solarino
//Description: Is called in the Application class
//-----------------------------------------------------------------------------

#ifndef STARTUP
#define STARTUP
#include "States\GameStates\MainMenu.h"

struct GLFWwindow;

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

	float m_currentTime = 0.0f;
	float m_deltaTime = 0.0f;
	float m_lastTime = 0.0f;
};
#endif