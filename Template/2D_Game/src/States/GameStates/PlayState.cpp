#include "GameStates\PlayState.h"
#include "Application.h"

#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"

#include <imgui.h>

#include <glfw3.h>
#include <vector>

PlayState::PlayState(Application *a_application) : IGameState(a_application)
{
	Load();
}

void PlayState::Load()
{
	m_Buttontxture = new Texture("./Images/Buttons/Pause.png");
	m_Buttontxture->SetSize(Vec2(25, 25));

	m_backgroundTexture = new Texture("./Images/grass.png");
	m_backgroundTexture->m_repeat = true;
	m_backgroundTexture->SetSize(Vec2((float)m_windowWidth, (float)m_windowHeight));

	m_pauseButton = new Button(Vec2(20, 20), m_Buttontxture, BtnFunction::PAUSE, m_pApplication);
}

PlayState::~PlayState()
{
	delete m_pauseButton;
	delete m_backgroundTexture;
	delete m_Buttontxture;
}

void PlayState::Update(float a_dt)
{
	

	m_pauseButton->Update();
}

void PlayState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	m_SBI = a_SBI;

	m_pauseButton->Draw(a_SBI);

	DrawMap();
	
}

void PlayState::DrawMap()
{
	Vec2 mapSize = Vec2(m_windowWidth, m_windowHeight);

	Mat3 mapTransform = Mat3(1, 0, 0,
							 0, 1, 0,
							 0, 0, 1);

	float posX = mapSize.x / 2;
	float posY = mapSize.y / 2;
	mapTransform.TranslateMat3(posX, posY);

	m_SBI->Begin();

	m_SBI->SetColor(255, 255, 255, 255);
	m_SBI->DrawSprite(m_backgroundTexture, mapTransform, mapSize);
}