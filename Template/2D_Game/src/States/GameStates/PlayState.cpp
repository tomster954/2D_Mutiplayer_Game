#include "GameStates\PlayState.h"
#include "Application.h"

#include "Managers\GameStateManager.h"

#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatchImidiate.h"

#include <imgui.h>

#include <glfw3.h>
#include <vector>

PlayState::PlayState(Application *a_application) : IGameState(a_application)
{
	m_testBoxText = new Texture("./Images/images.png");
	
	//We dont want any other state drawing or updating below this state
	m_blockDraw = true;
	m_blockUpdate = true;
}

PlayState::~PlayState()
{
}

void PlayState::Update(float a_dt)
{
	//m_blockDraw = true;
	//m_blockUpdate = true;
}

void PlayState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	Vec2 playerSize = Vec2(50, 100);

	Mat3 playerTransform = Mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);

	playerTransform.TranslateMat3(100, 100);
	playerTransform.CreateRotation(360);
	a_SBI->Begin();

	a_SBI->SetColor(255, 255, 255, 255);
	a_SBI->DrawSprite(m_testBoxText, playerTransform, playerSize);

	//TestDrawing();
	a_SBI->End();
}