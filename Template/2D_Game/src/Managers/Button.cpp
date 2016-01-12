#include "Managers\Button.h"
#include "Application.h"
#include "Managers\GameStateManager.h"
#include "SpriteLoad\Texture.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"

#include "Windows.h"
#include <glfw3.h>


Button::Button()
{
	m_pressed = false;
}

Button::Button(Vec2 a_pos, Texture *a_texture, BtnFunction func, Application *a_app)
{
	m_function	= func;
	m_pressed	= false;
	m_size		= a_texture->GetSize();
	m_pos		= a_pos;
	m_texture	= a_texture;
	m_app		= a_app;
}

Button::~Button()
{
}

void Button::Update()
{
	m_pressed = false;
	m_size = m_texture->GetSize();
	
	double x, y;
	glfwGetCursorPos(m_app->m_pWindow, &x, &y);

	if (x < m_pos.x + m_size.x && x > m_pos.x &&
		y < m_pos.y + m_size.y && y > m_pos.y)
	{
		m_colour = Vec3(100, 0, 100);
		if (glfwGetMouseButton(m_app->m_pWindow, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
			m_pressed = true;
	}
	else
	{
		m_pressed = false;
		m_colour = Vec3(255, 255, 255);
	}

	if (m_pressed)
		ButtonFunction();
}

void Button::Draw(SpriteBatch_Imidiate *a_SBI)
{
	a_SBI->Begin();

	a_SBI->SetColor(m_colour.x, m_colour.y, m_colour.z, 255);
	a_SBI->DrawSprite(m_texture, m_pos, m_size);
	a_SBI->SetColor(255, 255, 255, 255);

	a_SBI->End();
}

void Button::SetPosition(float a_x, float a_y)
{
	m_pos.x = a_x;
	m_pos.y = a_y;
}

void Button::ButtonFunction()
{
	switch (m_function)
	{
	case BtnFunction::BACK:
	{
		m_app->m_pGameStateManager->PopState();
	}break;
	case BtnFunction::SINGLE_PLAYER:
	{
		m_app->m_pGameStateManager->PopState();
		m_app->m_pGameStateManager->PushState("PlayState");
	}break;
	case BtnFunction::HIGH_SCORES:
	{
		m_app->m_pGameStateManager->PushState("HighScoresState");
	}break;
	case BtnFunction::HOST_GAME:
	{
		m_app->m_pGameStateManager->PushState("HostGameState");
	}break;
	case BtnFunction::INSTUCTIONS:
	{
		m_app->m_pGameStateManager->PushState("InstructionsState");
	}break;
	case BtnFunction::JOIN_GAME:
	{
		m_app->m_pGameStateManager->PushState("JoinGameState");
	}break;
	case BtnFunction::MAIN_MENU:
	{
		m_app->m_pGameStateManager->PopState();
		m_app->m_pGameStateManager->PushState("MenuState");
	}break;
	case BtnFunction::PAUSE:
	{
		m_app->m_pGameStateManager->PushState("PauseState");
	}break;
	case BtnFunction::SETTINGS:
	{
		m_app->m_pGameStateManager->PushState("SettingsState");
	}break;
	case BtnFunction::QUIT:
	{
		glfwSetWindowShouldClose(m_app->m_pWindow, true);
	}break;
	case BtnFunction::OTHER:
	{
		//Do nothing because the user will handle it
	}
	default:
		break;
	}

}