#include "GameStates\PauseState.h"
#include "Application.h"

#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"

#include <imgui.h>

#include <glfw3.h>
#include <vector>

PauseState::PauseState(Application *a_application) : IGameState(a_application)
{
	m_blockUpdate	= true;
	m_blockDraw		= true;
	Load();
}

void PauseState::Load()
{
	LoadTextures();
	LoadButtons();
}

void PauseState::LoadTextures()
{
	//Background
	m_backgroundTexture = new Texture("./Images/Backgrounds/Scribble.png");
	m_backgroundTexture->m_repeat = true;
	m_backgroundTexture->SetSize(Vec2((float)m_windowWidth, (float)m_windowHeight));

	//Back Button
	m_backButtonTexture = new Texture("./Images/Buttons/Back.png");
	m_backButtonTexture->SetSize(Vec2(50, 50));

	//Main Buttons
	m_tHScores		= new Texture("./Images/Buttons/HighScores2.png");
	m_tInstructions = new Texture("./Images/Buttons/Instructions2.png");
	m_tSettings		= new Texture("./Images/Buttons/Settings2.png");
	m_tQuit			= new Texture("./Images/Buttons/Quit.png");
}

void PauseState::LoadButtons()
{
	float yPosOffset = 0.40f;

	//setting the size of the buttons based of the window size
	float largeImageWidth = (float)m_windowWidth * 0.30f;
	float largeImageHeight = (float)m_windowHeight * 0.05f;
	float largeButtonPosX = (float)m_windowWidth * 0.50f - largeImageWidth * 0.50f;
	float largeButtonPosY = m_windowHeight;

	//setting the main button texture size relative to the size of the window
	m_tHScores->SetSize(Vec2(largeImageWidth, largeImageHeight));
	m_tSettings->SetSize(Vec2(largeImageWidth, largeImageHeight));
	m_tInstructions->SetSize(Vec2(largeImageWidth, largeImageHeight));
	m_tQuit->SetSize(Vec2(largeImageWidth, largeImageHeight));

	//Initialising the back buttons
	m_backButton = new Button(Vec2(20, 20), m_backButtonTexture, BtnFunction::BACK, m_pApplication);

	//Initialising the main buttons
	m_bHScores		= new Button(Vec2(largeButtonPosX, largeButtonPosY * yPosOffset),			 m_tHScores, BtnFunction::HIGH_SCORES, m_pApplication);
	m_bSettings		= new Button(Vec2(largeButtonPosX, largeButtonPosY * (yPosOffset += 0.10f)), m_tSettings, BtnFunction::SETTINGS, m_pApplication);
	m_bInstructions = new Button(Vec2(largeButtonPosX, largeButtonPosY * (yPosOffset += 0.10f)), m_tInstructions, BtnFunction::INSTUCTIONS, m_pApplication);
	m_bQuit			= new Button(Vec2(largeButtonPosX, largeButtonPosY * (yPosOffset += 0.10f)), m_tQuit, BtnFunction::MAIN_MENU, m_pApplication);

	m_allButtons.push_back(m_backButton);

	m_allButtons.push_back(m_bHScores);
	m_allButtons.push_back(m_bSettings);
	m_allButtons.push_back(m_bInstructions);
	m_allButtons.push_back(m_bQuit);
}

PauseState::~PauseState()
{
	delete m_backButton;
	delete m_backgroundTexture;
	delete m_backButtonTexture;
}

void PauseState::Update(float a_dt)
{
	for (int i = 0; i < m_allButtons.size(); i++)
		m_allButtons[i]->Update();
}

void PauseState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	m_SBI = a_SBI;

	for (int i = 0; i < m_allButtons.size(); i++)
		m_allButtons[i]->Draw(m_SBI);	

	DrawBackground();
}

void PauseState::DrawBackground()
{
	Vec2 mapSize = Vec2(m_windowWidth, m_windowHeight);
	Mat3 mapTransform = Mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);

	float posX = mapSize.x / 2;
	float posY = mapSize.y / 2;

	mapTransform.TranslateMat3(posX, posY);

	m_SBI->SetColor(255, 255, 255, 255);
	m_SBI->DrawSprite(m_backgroundTexture, mapTransform, mapSize);
}