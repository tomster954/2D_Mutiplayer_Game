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
	glfwGetWindowSize(m_pApplication->m_pWindow, &m_windowWidth, &m_windowHeight);
	LoadTextures(); 
	LoadButtons();
}

MenuState::~MenuState()
{
	delete m_tQuit;
	delete m_tHScores;
	delete m_tSettings;
	delete m_tInstructions;
	delete m_tHostGame;
	delete m_tJoinGame;
	delete m_tSinglePlayer;
}

void MenuState::LoadTextures()
{
	m_tSinglePlayer	= new Texture("./Images/images.png");
	m_tJoinGame		= new Texture("./Images/images.png");
	m_tHostGame		= new Texture("./Images/images.png");
	m_tInstructions = new Texture("./Images/images.png");
	m_tSettings		= new Texture("./Images/images.png");
	m_tHScores		= new Texture("./Images/images.png");
	m_tQuit			= new Texture("./Images/images.png");
}

void MenuState::LoadButtons()
{
	float yPosOffset = 0.40f;

	//setting the size of the buttons based of the window size
	float largeImageWidth	= (float)m_windowWidth * 0.30f;
	float largeImageHeight	= (float)m_windowHeight * 0.05f;
	float largeButtonPosX	= (float)m_windowWidth * 0.50f - largeImageWidth * 0.50f;
	float largeButtonPosY	= m_windowHeight;
	
	float smallImageWidth	= (float)m_windowWidth * 0.05f;
	float smallImageHeight	= (float)m_windowHeight * 0.05f;
	float smallButtonPosX	= (float)m_windowWidth * 0.50f - largeImageWidth * 0.5f;
	float smallButtonPosY	= (float)m_windowHeight;

	//setting the main button texture size relative to the size of the window
	m_tSinglePlayer->SetSize(Vec2(largeImageWidth, largeImageHeight));
	m_tJoinGame->SetSize(Vec2(largeImageWidth, largeImageHeight));	
	m_tHostGame->SetSize(Vec2(largeImageWidth, largeImageHeight));
	
	m_tInstructions->SetSize(Vec2(smallImageWidth, smallImageHeight));
	m_tSettings->SetSize(Vec2(smallImageWidth, smallImageHeight));
	m_tHScores->SetSize(Vec2(smallImageWidth, smallImageHeight));
	m_tQuit->SetSize(Vec2(smallImageWidth, smallImageHeight));

	//Initialising the main buttons
	m_bSinglePlayer = new Button(Vec2(largeButtonPosX, largeButtonPosY * yPosOffset),				m_tSinglePlayer,	BtnFunction::SINGLE_PLAYER, m_pApplication);
	m_bJoinGame		= new Button(Vec2(largeButtonPosX, largeButtonPosY * (yPosOffset += 0.10f)),	m_tJoinGame,		BtnFunction::JOIN_GAME,		m_pApplication);
	m_bHostGame		= new Button(Vec2(largeButtonPosX, largeButtonPosY * (yPosOffset += 0.10f)),	m_tHostGame,		BtnFunction::HOST_GAME,		m_pApplication);
	
	//Initialising the smaller buttons
	float buttonSpacing = (largeImageWidth - (4*smallImageWidth)) / 3;
	m_bInstructions = new Button(Vec2(smallButtonPosX,										smallButtonPosY * (yPosOffset += 0.10f)),	m_tInstructions,	BtnFunction::INSTUCTIONS	,m_pApplication);
	m_bSettings		= new Button(Vec2(smallButtonPosX += smallImageWidth + buttonSpacing,	smallButtonPosY * yPosOffset),				m_tSettings,		BtnFunction::SETTINGS		,m_pApplication);
	m_bHScores		= new Button(Vec2(smallButtonPosX += smallImageWidth + buttonSpacing,	smallButtonPosY * yPosOffset),				m_tHScores,			BtnFunction::HIGH_SCORES	,m_pApplication);
	m_bQuit			= new Button(Vec2(smallButtonPosX += smallImageWidth + buttonSpacing,	smallButtonPosY * yPosOffset),				m_tQuit,			BtnFunction::QUIT			,m_pApplication);

	//Adding buttons to a list for updating and drawing
	m_buttons.push_back(m_bSinglePlayer);
	m_buttons.push_back(m_bJoinGame);
	m_buttons.push_back(m_bHostGame);
	m_buttons.push_back(m_bInstructions);
	m_buttons.push_back(m_bSettings);
	m_buttons.push_back(m_bHScores);
	m_buttons.push_back(m_bQuit);
}

void MenuState::Update(float a_dt)
{
	for (int i = 0; i < m_buttons.size(); i++)
		m_buttons[i]->Update();
}

void MenuState::Draw(SpriteBatch_Imidiate* a_SBI)
{
	glfwGetWindowSize(m_pApplication->m_pWindow, &m_windowWidth, &m_windowHeight);

	//Setting up next window
	//ImGui::SetNextWindowSize(ImVec2((float)m_windowWidth, (float)m_windowHeight), ImGuiSetCond_Always);
	//ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiSetCond_Once);
	//
	//BEGIN
	//if (ImGui::Begin("Main Menu", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
	//{
	//	
	//	if(ImGui::Button("Play", ImVec2(100, 100)))
	//	{
	//		//Set the current Updating state to Play State;
	//		m_pApplication->m_pGameStateManager->PopState();
	//		m_pApplication->m_pGameStateManager->PushState("PlayState");
	//	}
	//	if (ImGui::Button("Instructions", ImVec2(100, 100)))
	//	{
	//		//Push the Instructions state
	//		m_pApplication->m_pGameStateManager->PushState("InstructionsState");
	//	}
	//}
	//ImGui::End();
	//END

	for (int i = 0; i < m_buttons.size(); i++)
		m_buttons[i]->Draw(a_SBI);
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