#include "FlyingState.h"
#include "..\..\Engine\MathTools.h"
#include "..\Ship\ShipFactory.h"
#include "..\..\TextureBank.h"

void FlyingState::Load(sf::RenderWindow * aRenderWindow)
{
	State::Load(aRenderWindow);

	myGui.Load();

	myTempShip = ShipFactory::GetInstance().BuildShip(ShipModel::Debug);
	myTempShip.Init(GET_TEXTURE("player"), true);

	myPlayer.GiveShip(&myTempShip);

	myTempActor.Init(GET_TEXTURE("alienBlue"), true, { 200, 20 }, 10000, 1);

	myPlayer.AttatchObserver(&myGui);

	myPlayer.GiveShip(&myTempShip);

	myPlayer.GetShip().SetUp(&myActors);

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

	myBackground.CreateBackground(*myGameWindow);
}

void FlyingState::Update(float aDeltaTime, GameState& aGameState)
{
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


	for (int i = myActors.size() - 1; i >= 0; --i)
	{
		if (MT::Length(myGameCamera.GetTargetPosition() - myActors[i]->GetPosition()) > 4000 && myActors[i] != &myPlayer.GetShip() && myActors[i] != &myTempActor)
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
		if (myGameCamera.CanSee(myActors[i]->GetPosition()))
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
	float distance = abs(MT::Length(aActor1.GetPosition() - aActor2.GetPosition()));

	if (distance < aActor1.GetRadius() + aActor2.GetRadius())
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
