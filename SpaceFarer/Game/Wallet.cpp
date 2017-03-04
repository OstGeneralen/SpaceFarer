#include "Wallet.h"

void Wallet::Earn(int aAmount)
{
	myBalance += aAmount;
	NotifyObservers(EVENT_PLAYER_NEW_BALANCE, myBalance);
}

void Wallet::Pay(int aAmount)
{
	myBalance -= aAmount;
	NotifyObservers(EVENT_PLAYER_NEW_BALANCE, myBalance);
}

bool Wallet::CanAfford(int aPrice) const
{
	return aPrice <= myBalance;
}
