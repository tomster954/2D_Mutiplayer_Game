#include "GameStates\PlayState.h"
#include "Application.h"

#include "Managers\GameStateManager.h"

#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"

#include <imgui.h>

#include <glfw3.h>
#include <vector>

PlayState::PlayState(Application *a_application) : IGameState(a_application)
{
	m_testBoxText = new Texture("./Images/grass.png");
	m_testBoxText->m_repeat = true;
	m_testBoxText->SetSize(Vec2(400, 400));
}

PlayState::~PlayState()
{
}

void PlayState::Update(float a_dt)
{
}

void PlayState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	Vec2 imageSize = Vec2(640, 480);

	Mat3 playerTransform = Mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);

	float posX = imageSize.x / 2;
	float posY = imageSize.y / 2;

	playerTransform.TranslateMat3(posX, posY);
	playerTransform.CreateRotation(360);

	a_SBI->Begin();

	a_SBI->SetColor(255, 255, 255, 255);
	a_SBI->DrawSprite(m_testBoxText, playerTransform, imageSize);

	//TestDrawing();
	a_SBI->End();
}