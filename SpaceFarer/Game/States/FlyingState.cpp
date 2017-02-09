#include "FlyingState.h"
#include "..\..\Engine\MathTools.h"
#include "..\Ship\ShipFactory.h"
#include "..\Weapons\WeaponFactory.h"
#include "..\..\TextureBank.h"
#include "StateManger.h"


void FlyingState::Load(sf::RenderWindow * aRenderWindow)
{

	State::Load(aRenderWindow);

	WeaponFactory::GetInstance().Init(&myActors);
	myGameCamera = Camera(*aRenderWindow);
	myGuiCamera = Camera(*aRenderWindow);

	myGui.Load();

	mySpaceStation.Init(GET_TEXTURE("spaceStation"), true, { 800,900 }, 100000);

 	myTempShip = ShipFactory::GetInstance().BuildShip(ShipModel::Debug);
	myTempShip.Init(GET_TEXTURE("player"), true, { 0,0 }, 50.f, 0.25f);

	myPlayer.GiveShip(&myTempShip);

	myTempActor.Init(GET_TEXTURE("alienBlue"), true, { 200, 20 }, 10000, 1);

	myPlayer.AttatchObserver(&myGui);

	myPlayer.GiveShip(&myTempShip);

	myPlayer.GetShip().SetUp(&myActors);

	myPlayer.SetTarget(mySpaceStation.GetPosition());

	myGui.SetPositions(*myGameWindow);

	myGameCamera.SetTarget(&myPlayer.GetShip());
	myGameCamera.SetCenter(&myPlayer.GetShip());

	myActors.reserve(500);
	myActors.push_back(&myPlayer.GetShip());
	myActors.push_back(&myTempActor);
	
	for (int i = 0; i < 100; ++i)
	{
		Asteroid* tmpAsteroid = new Asteroid();
		tmpAsteroid->Init(GET_TEXTURE("asteroid"), true, (0.25f + MT::Randf()) * 2500.f * sf::Vector2f(sinf(static_cast<float>(rand())), cosf(static_cast<float>(rand()))), 25.f, 0.5f);
		myActors.push_back(tmpAsteroid);
	}
	
	/* RECTANGLE FUNHOUSE
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 16; x++)
		{
			if (y == 0 || y == 8 || x == 0 || x == 15)
			{
				Asteroid* tmpAsteroid = new Asteroid();
				tmpAsteroid->Init(GET_TEXTURE("asteroid"), true, sf::Vector2f(-800 + x * 128, -450 + y * 128), 1000000.f, 1.f);
				myActors.push_back(tmpAsteroid);
			}
		}
	}
	*/

	mySpaceStation.SetExitPoint(ExitPoint::Left);

	myActors.push_back(&mySpaceStation);

	myBackground.CreateBackground(*myGameWindow);

}

void FlyingState::LoadWithPosition(const sf::Vector2f & aPosition)
{
	myPlayer.GetShip().SetPosition(aPosition);
	myGameCamera.SetCenter(&myPlayer.GetShip());
}

void FlyingState::Unload()
{
	myActors.clear();
}

void FlyingState::Update(float aDeltaTime)
{
	myGameCamera.Update(aDeltaTime);

	for (unsigned i = 0; i < myActors.size(); i++)
	{
		if (myGameCamera.CanSee(myActors[i]->GetViewHitBox()))
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

	if (myPlayer.GetShip().CheckIfColliding(mySpaceStation))
	{
		StateManager::GetInstance().ChangeStateWithPosition(GameState::SpaceStation, *myGameWindow, mySpaceStation.GetExitPoint());
	}

	for (int i = myActors.size() - 1; i >= 0; --i)
	{
		if (MT::Length(myGameCamera.GetTargetPosition() - myActors[i]->GetPosition()) > 4000 && myActors[i] != &myPlayer.GetShip() && myActors[i] != &myTempActor && myActors[i] != &mySpaceStation)
		{
			delete myActors[i];
			myActors[i] = nullptr;
			myActors[i] = myActors.back();
			myActors.pop_back();
		}
	}
}

void FlyingState::Render()
{
	myGameCamera.UseView(*myGameWindow);

	//Todo: Game Rendering
	myBackground.Render(*myGameWindow);

	for (unsigned i = 0; i < myActors.size(); i++)
	{
		if (myGameCamera.CanSee(myActors[i]->GetViewHitBox()))
		{
			myActors[i]->Render(*myGameWindow);
		}
	}

	//GUI Rendering
	myGuiCamera.UseView(*myGameWindow);
	myGui.Render(*myGameWindow);
}

void FlyingState::WindowResize()
{
	myGameCamera.UseView(*myGameWindow);
	myGameCamera.Resize(static_cast<float>(myGameWindow->getSize().x), static_cast<float>(myGameWindow->getSize().y));

	myGuiCamera.UseView(*myGameWindow);
	myGuiCamera.Resize(static_cast<float>(myGameWindow->getSize().x), static_cast<float>(myGameWindow->getSize().y));

	myGui.SetPositions(*myGameWindow);
}

void FlyingState::HandleCollision(Actor & aActor1, Actor & aActor2)
{

	if (aActor1.CheckIfColliding(aActor2))
	{
		sf::Vector2f normal = aActor2.GetPosition() - aActor1.GetPosition();
		MT::Normalize(normal);
		sf::Vector2f relativeVel = aActor2.GetVelocity() - aActor1.GetVelocity();
		float velocityScalar = MT::Dot(relativeVel, normal);

		if (velocityScalar > 0)
			return;

		float e = MT::Min(aActor1.GetRestitution(), aActor2.GetRestitution());

		float j = -(1 + e) * velocityScalar;
		j /= ((1.f / aActor1.GetMass()) + (1.f / aActor2.GetMass()));

		//normal *= velocityScalar;
		sf::Vector2f impulse = j * normal;
		aActor1.ChangeVelocity(-1.f / (aActor1.GetMass()) * impulse);
		aActor2.ChangeVelocity(1.f / (aActor2.GetMass()) * impulse);
	}
}
