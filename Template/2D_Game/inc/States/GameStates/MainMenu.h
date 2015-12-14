//-----------------------------------------------------------------------------
//Author: Tom Solarino	
//Description: Main Menu State
//-----------------------------------------------------------------------------

#ifndef MAIN_MENU
#define MAIN_MENU

struct GLFWwindow;
class Texture;
class SpriteBatch_Imidiate;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void Initialise(GLFWwindow* a_pWindow);

	void Update(float a_dt);
	void Draw(SpriteBatch_Imidiate *a_SBI);

	void TestDrawing();

private:
	GLFWwindow* m_pWin;
	Texture* m_texture1;
};



#endif