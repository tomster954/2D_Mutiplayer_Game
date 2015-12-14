//-----------------------------------------------------------------------------
//Author: Tom Solarino	
//Description: Main Menu State
//-----------------------------------------------------------------------------

#ifndef MAIN_MENU
#define MAIN_MENU

struct GLFWwindow;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void Initialise(GLFWwindow* a_pWindow);

	void Update(float a_dt);
	void Draw();

	void TestDrawing();

private:
	GLFWwindow* m_pWin;
};



#endif