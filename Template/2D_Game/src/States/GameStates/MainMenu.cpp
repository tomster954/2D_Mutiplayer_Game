#include "GameStates\MainMenu.h"
#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatchImidiate.h"

#include <glfw3.h>
#include "stdlib.h"

MainMenu::MainMenu()
{
	
}

MainMenu::~MainMenu()
{
	delete m_texture1;
}

void MainMenu::Initialise(GLFWwindow* a_pWindow)
{
	m_pWin = a_pWindow;
	m_texture1 = new Texture("./Images/images.png");
}

void MainMenu::Update(float a_dt)
{

}

void MainMenu::Draw(SpriteBatch_Imidiate* a_SBI)
{
	Vec2 playerPos = Vec2(100, 100);
	Vec2 playerSize = Vec2(50, 100);

	a_SBI->Begin();

	a_SBI->SetColor(255, 255, 255, 255);
	a_SBI->DrawSprite(m_texture1, playerPos, playerSize);

	//TestDrawing();
	a_SBI->End();
}

void MainMenu::TestDrawing()
{
	float ratio;
	int width, height;
	glfwGetFramebufferSize(m_pWin, &width, &height);
	ratio = width / (float)height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef((float)glfwGetTime() * 50.f, 50.f, 50.f, 1.f);

#pragma region Cube Quads
	float hBW = 0.5f; //Half Box Width
	float hBH = 0.5f; //Half Box Height
	float hBD = 0.5f; //Half Box Depth

	glBegin(GL_QUADS);
	//TOP - RED
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-hBW, hBH, hBD);
	glVertex3f(hBW, hBH, hBD);
	glVertex3f(hBW, hBH, -hBD);
	glVertex3f(-hBW, hBH, -hBD);

	glEnd();

	glBegin(GL_QUADS);
	//FRONT - YELLOW
	glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, 0.5f);
	glVertex3f(hBW, -hBH, -hBD);
	glVertex3f(hBW, hBH, -hBD);
	glVertex3f(-hBW, hBH, -hBD);
	glVertex3f(-hBW, -hBH, -hBD);

	glEnd();

	glBegin(GL_QUADS);
	//RIGHT - BLUE
	glColor3f(0.0f, 0.0f, 1.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(hBW, hBH, -hBD);
	glVertex3f(hBW, hBH, hBD);
	glVertex3f(hBW, -hBH, hBD);
	glVertex3f(hBW, -hBH, -hBD);

	glEnd();

	glBegin(GL_QUADS);
	//LEFT - GREEN
	glColor3f(0.0f, 1.0f, 0.5f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-hBW, -hBH, hBD);
	glVertex3f(-hBW, hBH, hBD);
	glVertex3f(-hBW, hBH, -hBD);
	glVertex3f(-hBW, -hBH, -hBD);

	glEnd();

	glBegin(GL_QUADS);
	//BOTTOM - PURPLE
	glColor3f(0.5f, 0.0f, 1.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(hBW, -hBH, hBD);
	glVertex3f(-hBW, -hBH, hBD);
	glVertex3f(-hBW, -hBH, -hBD);
	glVertex3f(hBW, -hBH, -hBD);

	glEnd();

	glBegin(GL_QUADS);
	//BACK - ORANGE
	glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(hBW, hBH, hBD);
	glVertex3f(hBW, -hBH, hBD);
	glVertex3f(-hBW, -hBH, hBD);
	glVertex3f(-hBW, hBH, hBD);

	glEnd();
#pragma endregion
}