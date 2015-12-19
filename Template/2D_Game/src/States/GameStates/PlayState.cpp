#include "GameStates\PlayState.h"
#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatchImidiate.h"
#include <imgui.h>

#include <glfw3.h>
#include <vector>

PlayState::PlayState()
{
}

void PlayState::Initialise(GLFWwindow *a_pWindow)
{
	m_testBoxText = new Texture("./Images/images.png");
}

PlayState::~PlayState()
{
}

void PlayState::Update(float a_dt)
{

}

void PlayState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	//BEGIN
	if (ImGui::Begin("Messenger", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar))
	{
		//TODO::
	}
	ImGui::End();
	//END

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