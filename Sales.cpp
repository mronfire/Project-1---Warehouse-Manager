#include "Sales.h"

SalesDay::SalesDay()
{
	numExec = 0;
	numMem = 0;
	revenue = 0;
	date = "";
	tomorrow = NULL;
	firstPurchase = NULL;
	lastPurchase = NULL;

}

SalesDay::SalesDay(float initRevenue, int initExec, int initMem, std::string initDate, SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast)
{
	revenue = initRevenue;
	numExec = initExec;
	numMem = initMem;
	date = initDate;
	tomorrow = initTomorrow;
	firstPurchase = initFirst;
	lastPurchase = initLast;
}

SalesDay::SalesDay(SalesDay a)
{

}

void SalesDay::IncreaseRevenue(int addRevenue)
{
	revenue += addRevenue;
}

void SalesDay::MemberCount(bool member)
{
	if(member == true)
	{
		numExec++;
	}
	else if(member == false)
	{
		numMem++;
	}
}

void SalesDay::NextDay(SalesDay a)
{
	tomorrow = a;
}

void SalesDay::AdjustPurchase(Purchase a)
{
	Purchase temp;

	temp = firstPurchase;
	firstPurchase = a.next;
}

void SalesDay::AddPurchase(Purchase a)
{
	lastPurchase = a;
}

void SalesDay::Print()
{
	cout << left << setw(18) << "Member purchases:" << numMem << endl;
	cout << setw(21) << "Executive purchases:" << numExec << endl;
	cout << "Total revenue: $" << revenue << endl;
}

SalesDay::~SalesDay()
{

}
