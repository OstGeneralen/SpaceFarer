#include "Game.h"
#include <iostream>
#include "..\Engine\DebugTools\FPSCounter.h"
#include "..\Engine\MathTools.h"
#define RANDOM_SEED 25062009

Game::Game(bool& aShouldRun)
	: myShouldRun(aShouldRun)
{
#ifdef _DEBUG
	myShouldShowDebugInfo = true;
	srand(RANDOM_SEED);
#else
	myShouldShowDebugInfo = false;
#endif

	myDebugTool = new D::FPSCounter(new D::Tools());
}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer");

	myPlayerTex.loadFromFile("sprites/player.png");
	myAlienTex.loadFromFile("sprites/Trash/alien.png");
	myAsteroidTex.loadFromFile("sprites/Trash/asteroid.png");
	myFrameTex.loadFromFile("sprites/frame.png");

	myPlayer.Init(&myPlayerTex, true);
	myTempActor.Init(&myAlienTex, true, { 200, 20 });
	myFrame.Init(&myFrameTex);
	myGameCamera.SetTarget(&myPlayer);
	myGameCamera.SetCenter(&myPlayer);
	
	for (int i = 0; i < 10; ++i)
	{
		Asteroid tmpAsteroid;
		tmpAsteroid.Init(&myAsteroidTex, true, (0.25f + MT::Randf()) * 500.f * sf::Vector2f(sin(2 * MT_PI / 10 * i), cos(2 * MT_PI / 10 * i)));
		myAsteroids.push_back(tmpAsteroid);
	}

	myBackground.CreateBackground(myGameWindow);
}

void Game::Update(float aDeltaTime)
{
	sf::Event e;
	myGameWindow.pollEvent(e);

	if (e.type == sf::Event::Closed)
	{
		myGameWindow.close();
		myShouldRun = false;
	}

	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Key::D)
		{
			myShouldShowDebugInfo = !myShouldShowDebugInfo;
		}
		if (e.key.code == sf::Keyboard::Key::A)
		{
			myGameCamera.SetTarget(&myTempActor);
		}
		if (e.key.code == sf::Keyboard::Key::P)
		{
			myGameCamera.SetTarget(&myPlayer);
		}
	}

	if (e.type == sf::Event::Resized)
	{
		myGameCamera.Resize(static_cast<float>(myGameWindow.getSize().x), static_cast<float>(myGameWindow.getSize().y));
		myGuiCamera.Resize(static_cast<float>(myGameWindow.getSize().x), static_cast<float>(myGameWindow.getSize().y));
	}


	if (myShouldShowDebugInfo)
	{
		myDebugTool->Update(aDeltaTime);
	}

	myPlayer.Update(aDeltaTime);
	myGameCamera.Update(aDeltaTime);

	for (unsigned i = 0; i < myAsteroids.size(); i++)
	{
		HandleCollision(myAsteroids[i], myPlayer);

		for (unsigned j = 0; j < myAsteroids.size(); j++)
		{
			if (j != i)
			{
				HandleCollision(myAsteroids[i], myAsteroids[j]);
			}
		}

		myAsteroids[i].Update(aDeltaTime);
	}
}

void Game::Render()
{
	myGameWindow.clear(myClearColor);
	
	myGameCamera.UseView(myGameWindow);

	//Todo: Game Rendering
	myBackground.Render(myGameWindow);
	myTempActor.Render(myGameWindow);
	myPlayer.Render(myGameWindow);

	for (unsigned i = 0; i < myAsteroids.size(); i++)
	{
		myAsteroids[i].Render(myGameWindow);
	}

	//GUI Rendering
	myGuiCamera.UseView(myGameWindow);
	myFrame.Render(myGameWindow);
	if (myShouldShowDebugInfo)
	{
		myDebugTool->Render(myGameWindow);
	}

	myGameWindow.display();
}

void Game::HandleCollision(Actor & aActor1, Actor & aActor2)
{
	float distance = abs(MT::Length(aActor1.GetPosition() - aActor2.GetPosition()));
	
	if (distance < aActor1.GetRadius() + aActor2.GetRadius())
	{
		sf::Vector2f normal = aActor2.GetPosition() - aActor1.GetPosition();
		MT::Normalize(normal);
		sf::Vector2f relativeVel = aActor2.GetVelocity() - aActor1.GetVelocity();
		float velocityScalar = MT::Dot(relativeVel, normal);

		if (velocityScalar > 0)
			return;

		normal *= velocityScalar;
		aActor1.ChangeVelocity(normal);
		aActor2.ChangeVelocity(-normal);
	}
}
