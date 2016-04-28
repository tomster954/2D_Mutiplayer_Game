#include "GameStates\JoinSetupState.h"
#include "Application.h"

#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"

#include <imgui.h>

#include <glfw3.h>
#include <vector>

JoinGameState::JoinGameState(Application *a_application) : IGameState(a_application)
{
	m_blockUpdate = true;
	m_blockDraw = true;
	Load();
}

void JoinGameState::Load()
{
	m_backButtonTexture = new Texture("./Images/Buttons/Back.png");
	m_backButtonTexture->SetSize(Vec2(50, 50));

	m_backgroundTexture = new Texture("./Images/Backgrounds/JoinSetup.png");

	m_backButton = new Button(Vec2(20, 20), m_backButtonTexture, BtnFunction::BACK, m_pApplication);

	m_allButtons.push_back(m_backButton);
}

JoinGameState::~JoinGameState()
{
	delete m_backButton;
	delete m_backgroundTexture;
	delete m_backButtonTexture;
}

void JoinGameState::Update(float a_dt)
{
	for (int i = 0; i < m_allButtons.size(); i++)
		m_allButtons[i]->Update();
}

void JoinGameState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	m_SBI = a_SBI;

	for (int i = 0; i < m_allButtons.size(); i++)
		m_allButtons[i]->Draw(m_SBI);
	
	DrawBackground();
}

void JoinGameState::DrawBackground()
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