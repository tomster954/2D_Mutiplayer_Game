#include "Managers\GameStateManager.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"
#include "Application.h"

#include "glfw3.h"

#pragma region IGameState

IGameState::IGameState(Application *a_app)
{
	m_pApplication = a_app;
	glfwGetWindowSize(m_pApplication->m_pWindow, &m_windowWidth, &m_windowHeight);
}

IGameState::~IGameState()
{
	//Left Blank
}

void IGameState::Update(float dt)
{
	
}

void IGameState::Draw(SpriteBatch_Imidiate *a_SBI)
{
	//left blank
}

#pragma endregion IGameState

#pragma region GameStateManager
GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

//Calls the updates for all updating states
void GameStateManager::UpdateGameStates(float a_dt)
{
	//Find all the states that require updating 
	ProcessCommands();

	//Loops throught states that need updating
	for (int i = 0; i < m_gameStateStack.size(); i++)
	{
		bool blocking = false;

		//Finds if there are any states higher on the stack that are blocking updates, if so, dont update this state.
		for (int j = i + 1; j < m_gameStateStack.size(); j++)
		{
			if (m_gameStateStack[j]->m_blockUpdate == true)
			{
				blocking = true;
				break;
			}
		}

		//Only updates this state if the states ontop aren't blocking updates
		if (!blocking)
			m_gameStateStack[i]->Update(a_dt);
	}
}

void GameStateManager::DrawGameStates(SpriteBatch_Imidiate *a_SBI)
{
	//Loops throught states that need drawing
	for (int i = 0; i < m_gameStateStack.size(); i++)
	{
		bool blocking = false;

		//Finds if there are any states higher on the stack that are blocking drawing, if so, dont draw this state.
		for (int j = i + 1; j < m_gameStateStack.size(); j++)
		{
			if (m_gameStateStack[j]->m_blockDraw == true)
			{
				blocking = true;
				break;
			}
		}

		//Only draws this state if the states ontop aren't blocking drawing
		if (!blocking)
			m_gameStateStack[i]->Draw(a_SBI);
	}
}

//Finds the states that need updating
void GameStateManager::ProcessCommands()
{
	for (int i = 0; i< m_commands.size(); i++)
	{
		if (m_commands[i].cmd == E_PUSH)
		{
			//process the "push" command
			//-----------------------------------------------------
			auto iter = m_availableStates.find(m_commands[i].name);

			if (iter != m_availableStates.end())
			{
				m_gameStateStack.push_back(iter->second);
			}
			//-----------------------------------------------------
		}
		else if (m_commands[i].cmd == E_POP)
		{
			if (m_gameStateStack.size() > 0)
				m_gameStateStack.pop_back();
		}
	}

	m_commands.clear();
}

//used to manipulate the game State stack
void GameStateManager::SetState(const char *a_name, IGameState *a_pState)
{
	//if the a_name == an existing state that isnt already on the top of m_availableStates,
	//	delete it and re-add it to m_availableStates.
	auto iter = m_availableStates.find(a_name);
	if (iter != m_availableStates.end())
	{
		delete iter->second;
	}

	m_availableStates[a_name] = a_pState;
}

void GameStateManager::PushState(const char *name)
{
	SCommands command;
	command.name = name;
	command.cmd = E_PUSH;

	m_commands.push_back(command);
}

void GameStateManager::PopState()
{
	SCommands command;
	command.cmd = E_POP;

	m_commands.push_back(command);
}

#pragma endregion GameStateManager