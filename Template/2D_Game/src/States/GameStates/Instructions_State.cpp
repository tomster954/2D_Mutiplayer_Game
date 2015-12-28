#include "GameStates\Instructions_State.h"
#include "Application.h"
#include "imgui.h"

Instructions_State::Instructions_State(Application *a_application) : IGameState(a_application)
{
	m_blockDraw = true;
	m_blockUpdate = true;
}

Instructions_State::~Instructions_State()
{

}

void Instructions_State::Update(float a_dt)
{
	if (glfwGetKey(m_pApplication->m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		m_pApplication->m_pGameStateManager->PopState();
}

void Instructions_State::Draw(SpriteBatch_Imidiate *a_SBI)
{
	glfwGetWindowSize(m_pApplication->m_pWindow, &m_windowWidth, &m_windowHeight);

	//Setting up next window
	ImGui::SetNextWindowSize(ImVec2((float)m_windowWidth, (float)m_windowHeight), ImGuiSetCond_Always);
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiSetCond_Once);

	//BEGIN
	if (ImGui::Begin("Instructions State", NULL))
	{
		//TODO:: Add play button
		if (ImGui::Button("Back", ImVec2(100, 100)))
		{
			m_pApplication->m_pGameStateManager->PopState();
		}

	}
	ImGui::End();
	//END
}