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
	m_Buttontxture = new Texture("./Images/smiley.png");
	m_Buttontxture->SetSize(Vec2(100, 100));

	m_testBoxText = new Texture("./Images/grass.png");
	m_testBoxText->m_repeat = true;
	m_testBoxText->SetSize(Vec2(400, 400));

	//Vec2 mousePos;
	
	m_testButton = new Button(Vec2(100, 100), m_Buttontxture, m_pApplication);
}

PlayState::~PlayState()
{
	delete m_testButton;
	delete m_testBoxText;
	delete m_Buttontxture;
}

void PlayState::Update(float a_dt)
{
	//m_testButton->SetPosition(100, 100);
	m_testButton->Update();
	
	if (m_testButton->m_pressed)
	{
		m_testButton->m_pressed = false;
		m_pApplication->m_pGameStateManager->PopState();
		m_pApplication->m_pGameStateManager->PushState("MenuState");
	}

	
}

void PlayState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	m_SBI = a_SBI;

	m_testButton->Draw(a_SBI);

	DrawMap();
	
}

void PlayState::DrawMap()
{
	Vec2 mapSize = Vec2(640, 480);

	Mat3 mapTransform = Mat3(1, 0, 0,
							 0, 1, 0,
							 0, 0, 1);

	float posX = mapSize.x / 2;
	float posY = mapSize.y / 2;
	mapTransform.TranslateMat3(posX, posY);

	m_SBI->Begin();

	m_SBI->SetColor(255, 255, 255, 255);
	m_SBI->DrawSprite(m_testBoxText, mapTransform, mapSize);

	//TestDrawing();
	m_SBI->End();
}