#include "Application.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "Managers\GameStateManager.h"

#include "States\GameStates\MenuState.h"
#include "States\GameStates\PlayState.h"
#include "States\GameStates\Instructions_State.h"

#define GLFW_INCLUDE_GLU
#include <glfw3.h>
#include <iostream>

void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

Application::Application() :
m_currentTime(0.0f),
m_deltaTime(0.0f),
m_lastTime(0.0f)
{
	//Sets up GLFW and creates window
	SetUpGLFW();

	//SpriteBatch Imidiate
	m_SBI = new SpriteBatch_Imidiate(m_pWindow);

	//Initialise ImGui
	ImGui_ImplGlfw_Init(m_pWindow, true);

	//Initialise the game state manager
	m_pGameStateManager = new GameStateManager();

	//Initialise the game states
	m_pGameStateManager->SetState("MenuState",			new MenuState(this));
	m_pGameStateManager->SetState("PlayState",			new PlayState(this));
	m_pGameStateManager->SetState("InstructionsState",	new Instructions_State(this));
	

	m_pGameStateManager->PushState("MenuState");
	//Main run loop
	Run();
}

Application::~Application()
{
	//Cleaning up 

	delete m_pGameStateManager;
	ImGui_ImplGlfw_Shutdown();
	delete m_SBI;

	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}

void Application::SetUpGLFW()
{
	//Setting up error call back
	glfwSetErrorCallback(error_callback);
	
	//If initialisation failed
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
		return;
	}

	//Create a new window
	m_pWindow = glfwCreateWindow(1280, 800, "Game", NULL, NULL);

	//If window initialisation failed
	if (!m_pWindow)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
		return;
	}

	//Making the new window the current context
	glfwMakeContextCurrent(m_pWindow);

	//setting the swap intervals timer - vsync
	glfwSwapInterval(1);

	//Setting the background to white
	glClearColor(255, 255, 255, 255);

	//Enable depth test for test cube
	glEnable(GL_DEPTH_TEST);
}

void Application::Run()
{
	

	//Main run loop
	while (!glfwWindowShouldClose(m_pWindow))
	{
		glClearColor(255, 255, 255, 255);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		float ratio;
		int width, height;
		glfwGetFramebufferSize(m_pWindow, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		Update();
		Draw();

		
		glfwSwapBuffers(m_pWindow);
		glfwPollEvents();
	}
}

void Application::Update()
{
	//Calculating deltatime
	m_currentTime = (float)glfwGetTime();
	m_deltaTime = m_currentTime - m_lastTime;
	m_lastTime = m_currentTime;

	m_pGameStateManager->UpdateGameStates(m_deltaTime);
}

void Application::Draw()
{
	//Begin
	m_SBI->Begin();
	ImGui_ImplGlfw_NewFrame();
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	
	//draw the menu state
	m_pGameStateManager->DrawGameStates(m_SBI);
	
	//End
	m_SBI->End();
	ImGui::PopStyleVar();
	ImGui::Render();		
}