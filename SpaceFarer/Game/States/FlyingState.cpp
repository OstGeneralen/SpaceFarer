#include "FlyingState.h"
#include "..\..\Engine\MathTools.h"
#include "..\Ship\ShipFactory.h"
#include "..\Weapons\WeaponFactory.h"
#include "..\..\TextureBank.h"
#include "StateManger.h"

#include "..\Bullets\BulletManager.h"
#include "..\CollisionManager.h"

void FlyingState::Load(sf::RenderWindow * aRenderWindow)
{

	State::Load(aRenderWindow);
	myDebris.Init();
	BulletManager::GetInstance().Init();
	CollisionManager::GetInstance().SetPlayer(&myPlayer);

	WeaponFactory::GetInstance().Init();
	myGameCamera = Camera(*aRenderWindow);
	myGuiCamera = Camera(*aRenderWindow);
	myGui.Load();

	mySpaceStation.Init(GET_TEXTURE("spaceStation"), true, { 800,900 }, 100000);

 	myTempShip = ShipFactory::GetInstance().BuildShip(ShipModel::Debug);
	myTempShip.Init(GET_TEXTURE("player"), true, { 0,0 }, 50.f, 0.25f);

	myPlayer.GiveShip(&myTempShip);

	myTempActor.Init(GET_TEXTURE("alienBlue"), true, { 200, 20 }, 10000, 1);

	myPlayer.AttatchObserver(&myGui);
	myPlayer.AttatchObserver(&myDebris);

	myPlayer.GiveShip(&myTempShip);

	myPlayer.GetShip().SetUp(true);
	myPlayer.GetShip().GiveCollider(new CircleCollider(myPlayer.GetShip().GetPosition(), myPlayer.GetShip().GetSize().x / 2));

	myPlayer.SetTarget(mySpaceStation.GetPosition());

	myGui.SetPositions(*myGameWindow);

	myGameCamera.SetTarget(&myPlayer.GetShip());
	myGameCamera.SetCenter(&myPlayer.GetShip());

	mySpaceStation.SetExitPoint(ExitPoint::Left);
	mySpaceStation.GiveCollider(new CircleCollider(mySpaceStation.GetPosition(), mySpaceStation.GetSize().x / 2));


	myBackground.CreateBackground(*myGameWindow);
}

void FlyingState::LoadWithPosition(const sf::Vector2f & aPosition)
{
	myPlayer.GetShip().SetPosition(aPosition);
	myGameCamera.SetCenter(&myPlayer.GetShip());
}

void FlyingState::Unload()
{
}

void FlyingState::Update(float aDeltaTime)
{
	myGameCamera.Update(aDeltaTime);

	myPlayer.Update(aDeltaTime);
	mySpaceStation.Update(aDeltaTime);

	myDebris.Update(aDeltaTime, myGameCamera, *myGameWindow);
	BulletManager::GetInstance().Update(aDeltaTime, myGameCamera);
	CollisionManager::GetInstance().Update(myGameCamera);

	if (myPlayer.GetShip().CheckIfColliding(mySpaceStation))
	{
		StateManager::GetInstance().ChangeStateWithPosition(GameState::SpaceStation, *myGameWindow, mySpaceStation.GetExitPoint());
	}

	if (myPlayer.GetShip().GetIsDead())
	{
		StateManager::GetInstance().ChangeState(GameState::Menu, *myGameWindow);
	}

}

void FlyingState::Render()
{
	myGameCamera.UseView(*myGameWindow);

	//Todo: Game Rendering
	myBackground.Render(*myGameWindow, myGameCamera);
	myDebris.Render(myGameCamera, *myGameWindow);

	myPlayer.Render(*myGameWindow);

	if (myGameCamera.CanSee(mySpaceStation.GetViewHitBox()))
	{
		mySpaceStation.Render(*myGameWindow);
	}

	BulletManager::GetInstance().Render(*myGameWindow);

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
