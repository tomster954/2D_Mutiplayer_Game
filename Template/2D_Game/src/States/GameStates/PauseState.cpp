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
	m_backButtonTexture = new Texture("./Images/Buttons/Back.png");
	m_backButtonTexture->SetSize(Vec2(25, 25));

	m_backgroundTexture = new Texture("./Images/Backgrounds/Scribble.png");
	m_backgroundTexture->m_repeat = true;
	m_backgroundTexture->SetSize(Vec2((float)m_windowWidth, (float)m_windowHeight));

	m_backButton = new Button(Vec2(20, 20), m_backButtonTexture, BtnFunction::BACK, m_pApplication);

	m_allButtons.push_back(m_backButton);
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