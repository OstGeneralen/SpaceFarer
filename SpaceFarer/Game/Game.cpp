#include "Game.h"
#include <iostream>
#include "..\Engine\DebugTools\FPSCounter.h"
#include "..\Engine\DebugTools\VersionStamp.h"
#include "..\Engine\MathTools.h"
#include "..\TextureBank.h"
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

	myDebugTool = new D::FPSCounter(new D::VersionStamp(new D::Tools()));
}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer");
	TextureBank::GetInstance()->Load();

	myGui.Load("fonts/helvetica.ttf");
	myGui.SetPositions(myGameWindow);
	
	myPlayer.AttatchObserver(&myGui);

	myPlayer.Init(GET_TEXTURE("player"), true);
	myTempActor.Init(GET_TEXTURE("alienBlue"), true, { 200, 20 });
	myGameCamera.SetTarget(&myPlayer);
	myGameCamera.SetCenter(&myPlayer);
	
	myActors.reserve(500);
	myActors.push_back(&myPlayer);
	myActors.push_back(&myTempActor);
	for (int i = 0; i < 100; ++i)
	{
		Asteroid* tmpAsteroid = new Asteroid();
		tmpAsteroid->Init(GET_TEXTURE("asteroid"), true, (0.25f + MT::Randf()) * 2500.f * sf::Vector2f(sinf(static_cast<float>(rand())), cosf(static_cast<float>(rand()))));
		myActors.push_back(tmpAsteroid);
	}

	myBackground.CreateBackground(myGameWindow);

	myDebugTool->Load(myGameWindow);
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

	myGameCamera.Update(aDeltaTime);

	for (unsigned i = 0; i < myActors.size(); i++)
	{
		if (myGameCamera.CanSee(myActors[i]->GetPosition()))
		{
			for (unsigned j = 0; j < myActors.size(); j++)
			{
				if (j != i)
				{
					HandleCollision(*myActors[i], *myActors[j]);

				}
			}
			myActors[i]->Update(aDeltaTime);
		}
	}


	for (int i = myActors.size()-1; i >= 0; --i)
	{
		if (MT::Length(myGameCamera.GetTargetPosition() - myActors[i]->GetPosition()) > 4000 && myActors[i] != &myPlayer && myActors[i] != &myTempActor)
		{
			delete myActors[i];
			myActors[i] = nullptr;
			myActors[i] = myActors.back();
			myActors.pop_back();
		}
	}
}

void Game::Render()
{
	myGameWindow.clear(myClearColor);
	
	myGameCamera.UseView(myGameWindow);

	//Todo: Game Rendering
	myBackground.Render(myGameWindow);

	for (unsigned i = 0; i < myActors.size(); i++)
	{
		if (myGameCamera.CanSee(myActors[i]->GetPosition()))
		{
			myActors[i]->Render(myGameWindow);
		}
	}

	//GUI Rendering
	myGuiCamera.UseView(myGameWindow);
	myGui.Render(myGameWindow);
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
