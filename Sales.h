
#ifndef SALES_H_
#define SALSALES_H_

#include "Purchase.h"
#include <iostream>
#include <iomanip>

#include <string>

using namespace std;

class SalesDay
{
private:
	float revenue;
	int numExec;
	int numMem;
	std::string date;
	SalesDay *tomorrow;
	Purchase *firstPurchase;
	Purchase *lastPurchase;
public:
	SalesDay();
	SalesDay(float initRevenue, int initExec, int initMem, std::string initDate, SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast);
	SalesDay(SalesDay a);
	void IncreaseRevenue(int addRevenue);
	void MemberCount(bool member);
	void AddPurchase(Purchase a);
	void AdjustPurchase(Purchase a);
	void NextDay(SalesDay a);
	void Print();
	~SalesDay();
};
#endif
