#include "MemberClass.h"

MemberClass::MemberClass(): name("BLANK"), number(0), memType(NORMAL), totalSpent(0), nextMember(NULL), firstPurchase(NULL), lastPurchase(NULL)
{

}

MemberClass::MemberClass(string iName, string iNumber, bool iMemType, float iTotalSpent, MemberClass *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase)
{
	name = iName;
	number = iNumber;
	memType = iMemType;
	totalSpent = iTotalSpent;
	nextMember = iNextMember;
	firstPurchase = iFirstPurchase;
	lastPurchase = iLastPurchase;
}

void MemberClass::SetName(string newName)
{
	name = newName;
}

void MemberClass::SetNumber(string newNum)
{
	number = newNum;
}

void MemberClass::SetType(bool newType)
{
	memType = newType;
}

void MemberClass::SetSpent(float newSpent)
{
	totalSpent = newSpent;
}

void MemberClass::CalcTotalSpent()
{
	bool quit = false;
	Purchase *temp;
	int quantity;
	float price;
	float purchTotal;
	float total = 0;

	temp = firstPurchase;

	while(quit == false)
	{
		price = temp->getObjPrice();
		quantity = temp->getObjQuantity();
		purchTotal = quantity * price;
		total += purchTotal;
		temp = temp->getNextMember();

		if(temp == lastPurchase)
		{
			quit = true;
		}
	}
}

string MemberClass::GetName()
{
	return name;
}

string MemberClass::GetNumber()
{
	return number;
}

bool MemberClass::GetType()
{
	return memType;
}

float MemberClass::GetSpent()
{
	return totalSpent;
}

MemberClass *MemberClass::GetNextMember()
{
	return nextMember;
}

Purchase *MemberClass::GetFirstPurchase()
{
		return firstPurchase;
}

Purchase *MemberClass::GetLastPurchase()
{
		return lastPurchase;
}

void ExecClass::SetRebate(float newRebate)
{
	rebate = newRebate;
}
