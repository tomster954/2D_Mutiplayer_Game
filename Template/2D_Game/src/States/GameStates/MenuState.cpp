#include "GameStates\MenuState.h"
#include "Application.h"
#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"
#include "Managers\Button.h"

#include "imgui.h"
#include <glfw3.h>
#include "stdlib.h"

MenuState::MenuState(Application *a_application) : IGameState(a_application)
{

}

MenuState::~MenuState()
{
	delete m_texture1;
}

void MenuState::Update(float a_dt)
{

}

void MenuState::Draw(SpriteBatch_Imidiate* a_SBI)
{
	glfwGetWindowSize(m_pApplication->m_pWindow, &m_windowWidth, &m_windowHeight);

	//Setting up next window
	ImGui::SetNextWindowSize(ImVec2((float)m_windowWidth, (float)m_windowHeight), ImGuiSetCond_Always);
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiSetCond_Once);
	
	//BEGIN
	if (ImGui::Begin("Main Menu", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	{
		if(ImGui::Button("Play", ImVec2(100, 100)))
		{
			//Set the current Updating state to Play State;
			m_pApplication->m_pGameStateManager->PopState();
			m_pApplication->m_pGameStateManager->PushState("PlayState");
		}
		if (ImGui::Button("Instructions", ImVec2(100, 100)))
		{
			//Push the Instructions state
			m_pApplication->m_pGameStateManager->PushState("InstructionsState");
		}
	}
	ImGui::End();
	//END
}

void MenuState::TestDrawing()
{
	//Draws a 3D cube

	float ratio;
	int width, height;
	glfwGetFramebufferSize(m_pApplication->m_pWindow, &width, &height);
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