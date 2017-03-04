#pragma once
#include "Observer\Subject.h"

class Wallet : public Subject
{
public:
	void Earn(int aAmount);
	void Pay(int aAmount);
	bool CanAfford(int aPrice) const;
private:
	int myBalance;
};