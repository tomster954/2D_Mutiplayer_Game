#include "Application.h"
#include "SpriteLoad\SpriteBatch_Immediate.h"
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "Managers\GameStateManager.h"

#include "States\GameStates\MenuState.h"
#include "States\GameStates\PlayState.h"
#include "States\GameStates\Instructions_State.h"
#include "States\GameStates\JoinSetupState.h"
#include "States\GameStates\HostSetupState.h"
#include "States\GameStates\SettingsState.h"
#include "States\GameStates\HighScoresState.h"
#include "States\GameStates\PauseState.h"

#include "windows.h"

#define GLFW_INCLUDE_GLU
#include <glfw3.h>
#include <iostream>

void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//Is called when the window resizes
}

Application::Application() :
m_currentTime(0.0f),
m_deltaTime(0.0f),
m_lastTime(0.0f)
{

	m_winWidth = 640.0f;
	m_winHeight = 480.0f;

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
	m_pGameStateManager->SetState("InstructionsState",	new InstructionsState(this));
	m_pGameStateManager->SetState("JoinGameState",		new JoinGameState(this));
	m_pGameStateManager->SetState("HostGameState",		new HostGameState(this));
	m_pGameStateManager->SetState("SettingsState",		new SettingsState(this));
	m_pGameStateManager->SetState("HighScoresState",	new HighScoresState(this));
	m_pGameStateManager->SetState("PauseState",			new PauseState(this));
	

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
	glfwWindowHint(GLFW_RESIZABLE, 0);
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	m_pWindow = glfwCreateWindow(mode->width, mode->height, "Game", glfwGetPrimaryMonitor(), NULL);

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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_DEPTH_TEST);
}

void Application::Run()
{
	

	//Main run loop
	while (!glfwWindowShouldClose(m_pWindow))
	{
		float ratio;
		int width, height;

		glfwGetFramebufferSize(m_pWindow, &width, &height);
		ratio = width / (float)height;

		//sets background to white
		glClearColor(255, 255, 255, 255);
		//Nothing draws wihtout this
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Update();
		Draw();
		
		glfwSwapBuffers(m_pWindow);
		glfwPollEvents();
	}
}

void Application::Update()
{
	glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);

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
	//ImGui_ImplGlfw_NewFrame();
	//ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	
	//draw the menu state
	m_pGameStateManager->DrawGameStates(m_SBI);
	
	//End
	//ImGui::PopStyleVar();
	//ImGui::Render();		
}