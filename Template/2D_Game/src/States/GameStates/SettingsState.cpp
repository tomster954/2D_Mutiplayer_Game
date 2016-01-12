#include "GameStates\SettingsState.h"
#include "Application.h"

#include "Managers\GameStateManager.h"
#include "Managers\Button.h"

#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"

#include <imgui.h>

#include <glfw3.h>
#include <vector>

SettingsState::SettingsState(Application *a_application) : IGameState(a_application)
{
	m_blockUpdate	= true;
	m_blockDraw		= true;
	Load();
}

void SettingsState::Load()
{
	m_backButtonTexture = new Texture("./Images/Buttons/Back.png");
	m_backButtonTexture->SetSize(Vec2(25, 25));

	m_backgroundTexture = new Texture("./Images/Backgrounds/Scribble.png");
	m_backgroundTexture->m_repeat = true;
	m_backgroundTexture->SetSize(Vec2((float)m_windowWidth, (float)m_windowHeight));

	m_backButton = new Button(Vec2(20, 20), m_backButtonTexture, BtnFunction::BACK, m_pApplication);

	m_allButtons.push_back(m_backButton);
}

SettingsState::~SettingsState()
{
	delete m_backButton;
	delete m_backgroundTexture;
	delete m_backButtonTexture;
}

void SettingsState::Update(float a_dt)
{
	for (int i = 0; i < m_allButtons.size(); i++)
		m_allButtons[i]->Update();
}

void SettingsState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	m_SBI = a_SBI;

	for (int i = 0; i < m_allButtons.size(); i++)
		m_allButtons[i]->Draw(m_SBI);	
}