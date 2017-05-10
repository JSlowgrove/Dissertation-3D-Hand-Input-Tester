#include "DemoState.h"

#include <SDL.h>
#include "../Core/GameObject.h"
#include "../Core/InputManager.h"
#include "../Core/Application.h"
#include "../Core/Logging.h"
#include "../Components/ModelComponent.h"
#include "../Components/CameraComponent.h"
#include "../Components/TransformComponent.h"
#include "../ResourceManagement/ResourceManager.h"
#include "../ResourceManagement/ResourceManager.h"
#include "../Maths/Convert.h"

#include <string>
#include <iostream>
#include "../HandInput/HandInput.h"

DemoState::DemoState(StateManager* stateManager, SDL_Window* window)
	: State(stateManager, window, "DemoState")
{
	//Set the background colour
	Application::setBackgroundColour(Vec3(0.0f, 0.0f, 0.0f));

	//Create the game objects

	auto camera = GameObject::create("camera").lock();
	camera->addComponent<CameraComponent>();
	camera->addComponent<TransformComponent>();
	Application::camera = camera;

	auto rec1 = GameObject::create("rec1").lock();
	rec1->addComponent<TransformComponent>();
	rec1->addComponent<ModelComponent>();

	auto rec2 = GameObject::create("rec2").lock();
	rec2->addComponent<TransformComponent>();
	rec2->addComponent<ModelComponent>();

	//Awake the game objects

	rec1->awake();
	rec2->awake();
	camera->awake();

	//Initalise the game objects

	camera->getComponent<TransformComponent>().lock()->setPos(Vec3(0.0f, 0.0f, -6.0f));

	rec1->getComponent<TransformComponent>().lock()->setScale(Vec3(1.5f, 0.5f, 0.5f));
	rec1->getComponent<TransformComponent>().lock()->setPos(Vec3(0.5f, 0.0f, 0.0f));
	rec1->getComponent<ModelComponent>().lock()->initaliseMesh("cube");
	rec1->getComponent<ModelComponent>().lock()->initaliseShaders("default", "cyan");

	rec2->getComponent<TransformComponent>().lock()->setScale(Vec3(1.5f, 0.5f, 0.5f));
	rec2->getComponent<TransformComponent>().lock()->setPos(Vec3(-1.0f, 0.0f, 0.0f));
	rec2->getComponent<ModelComponent>().lock()->initaliseMesh("cube");
	rec2->getComponent<ModelComponent>().lock()->initaliseShaders("default", "magenta");

	//initalise bools
	initialLoop = true;

	//initalise the angle
	angle = new float(0.0f);

	//initalise the input thread
	inThread = new InThread(1, angle);
}

DemoState::~DemoState()
{
	inThread->flagStop();
	while (!inThread->checkFinished())
	{
		//wait for thread to finish
	}
	delete inThread;
	delete angle;
	//Delete shaders
	ResourceManager::deleteAllShaders();
	//delete meshes
	ResourceManager::deleteAllMeshes();
}

bool DemoState::input()
{
	//Check for user input
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		InputManager::pollInputEvent(incomingEvent);
		if (incomingEvent.type == SDL_QUIT)
		{
			//If player closes the window, end the game loop
			return false;
		}
		if (InputManager::isKeyPressed(ESC_KEY))
		{
			//If Escape is pressed, end the game loop
			return false;
		}
	}
	return true;
}

void DemoState::update()
{
	//hack for initial loop
	if (initialLoop)
	{
		Application::setDT(0.0f);
		initialLoop = false;
	}

	//loops through the game objects
	for (unsigned int i = 0; i < Application::getGameObjects().size(); i++)
	{
		//set the rotation of the rectangle to the current value of the pointer
		if (Application::getGameObjects()[i]->getName() == "rec1")
		{
			Application::getGameObjects()[i]->getComponent<TransformComponent>().lock()->setRotation(
				Vec3(0.0f, 0.0f, Convert::convertDegreeToRadian(*angle))
			);
		}
	}
}

void DemoState::draw()
{
	//loops through the game objects
	for (unsigned int i = 0; i < Application::getGameObjects().size(); i++)
	{
		//draw the state
		Application::getGameObjects()[i]->render();
	}
}