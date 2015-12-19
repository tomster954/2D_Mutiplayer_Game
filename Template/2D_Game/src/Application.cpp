#include "Application.h"
#include "SpriteLoad\SpriteBatchImidiate.h"
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "Managers\GameStateManager.h"

#include "States\GameStates\MainMenu.h"
#include "States\GameStates\PlayState.h"

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
	m_pGameStateManager->SetState("MenuState", new MainMenu(this));
	m_pGameStateManager->SetState("PlayState", new PlayState(this));

	m_pGameStateManager->PushState("MenuState");
	//Main run loop
	Run();
}

Application::~Application()
{
	//Cleaning up 
	delete m_SBI;
	ImGui_ImplGlfw_Shutdown();
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
	m_pWindow = glfwCreateWindow(640, 480, "Window", NULL, NULL);

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
		if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)	glfwSetWindowShouldClose(m_pWindow, true);

		int width, height;
		glfwGetFramebufferSize(m_pWindow, &width, &height);
		glViewport(0, 0, width, height);
		
		glClearColor(255, 255, 255, 255);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

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