#include "FlyingState.h"
#include "..\..\Engine\MathTools.h"
#include "..\Ship\ShipFactory.h"
#include "..\Weapons\WeaponFactory.h"
#include "..\..\TextureBank.h"
#include "StateManger.h"

#include "..\Bullets\BulletManager.h"
#include "..\CollisionManager.h"

void FlyingState::Load(GameData aData)
{
	State::Load(aData);

	myDebris.Init();
	
	BulletManager::GetInstance().Init();

	WeaponFactory::GetInstance().Init();
	myGameCamera = Camera(*myData.myGameWindow);
	myGuiCamera = Camera(*myData.myGameWindow);
	
	myGui.Load();
	myGui.SetPositions(*myData.myGameWindow);

	mySpaceStation.Init(GET_TEXTURE("spaceStation"), true, { 800,900 }, 100000);

	//Load player
	LoadPlayer();

	myTempActor.Init(GET_TEXTURE("alienBlue"), true, { 200, 20 }, 10000, 1);


	myGameCamera.SetTarget(&myData.myPlayer->GetShip());
	myGameCamera.SetCenter(&myData.myPlayer->GetShip());

	mySpaceStation.SetExitPoint(ExitPoint::Left);
	mySpaceStation.GiveCollider(new CircleCollider(mySpaceStation.GetPosition(), mySpaceStation.GetSize().x / 2));
	
	if (myData.myLastVisitedStation != nullptr)
	{
		myData.myPlayer->GetShip().SetPosition(myData.myLastVisitedStation->GetExitPoint());
	}

	CollisionManager::GetInstance().SetPlayer(myData.myPlayer);

	myBackground.CreateBackground(*myData.myGameWindow);
}

void FlyingState::Unload()
{
}

void FlyingState::Update(float aDeltaTime)
{
	myGameCamera.Update(aDeltaTime);

	myData.myPlayer->Update(aDeltaTime);
	mySpaceStation.Update(aDeltaTime);

	myDebris.Update(aDeltaTime, myGameCamera, *myData.myGameWindow);
	BulletManager::GetInstance().Update(aDeltaTime, myGameCamera);
	CollisionManager::GetInstance().Update(myGameCamera);

	if (myData.myPlayer->GetShip().CheckIfColliding(mySpaceStation))
	{
		myData.myLastVisitedStation = &mySpaceStation;
		StateManager::GetInstance().ChangeState(GameState::SpaceStation, myData);
	}

	if (myData.myPlayer->GetShip().GetIsDead())
	{
		if (myData.myLastVisitedStation == nullptr)
		{
			StateManager::GetInstance().ChangeState(GameState::Menu, myData);
		}
		else
		{
			StateManager::GetInstance().ChangeState(GameState::SpaceStation, myData);
		}
	}

}

void FlyingState::Render()
{
	myGameCamera.UseView(*myData.myGameWindow);

	//Todo: Game Rendering
	myBackground.Render(*myData.myGameWindow, myGameCamera);
	myDebris.Render(myGameCamera, *myData.myGameWindow);

	myData.myPlayer->Render(*myData.myGameWindow);

	if (myGameCamera.CanSee(mySpaceStation.GetViewHitBox()))
	{
		mySpaceStation.Render(*myData.myGameWindow);
	}

	BulletManager::GetInstance().Render(*myData.myGameWindow);

	//GUI Rendering
	myGuiCamera.UseView(*myData.myGameWindow);
	myGui.Render(*myData.myGameWindow);
}

void FlyingState::WindowResize()
{
	myGameCamera.UseView(*myData.myGameWindow);
	myGameCamera.Resize(static_cast<float>(myData.myGameWindow->getSize().x), static_cast<float>(myData.myGameWindow->getSize().y));

	myGuiCamera.UseView(*myData.myGameWindow);
	myGuiCamera.Resize(static_cast<float>(myData.myGameWindow->getSize().x), static_cast<float>(myData.myGameWindow->getSize().y));

	myGui.SetPositions(*myData.myGameWindow);
}

void FlyingState::LoadPlayer()
{
	if (myData.myPlayer == nullptr)
	{
		myData.myPlayer = new Player();

		myTempShip = ShipFactory::GetInstance().BuildShip(ShipModel::Debug);
		myTempShip.Init(GET_TEXTURE("player"), true, { 0,0 }, 50.f, 0.25f);

		myData.myPlayer->GiveShip(&myTempShip);
		myData.myPlayer->AttatchObserver(&myGui);
		myData.myPlayer->AttatchObserver(&myDebris);
		myData.myPlayer->GetShip().SetUp(true);
		myData.myPlayer->GiveShip(&myTempShip);
		myData.myPlayer->GetShip().GiveCollider(new CircleCollider(myData.myPlayer->GetShip().GetPosition(), myData.myPlayer->GetShip().GetSize().x / 2));
		myData.myPlayer->SetTarget(mySpaceStation.GetPosition());
	}
	else
	{
		myData.myPlayer->GetShip().Stop();
	}
}
