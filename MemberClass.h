
#ifndef MEMBERCLASS_H_
#define MEMBERCLASS_H_

#include"purchaseclass.h"

using namespace std;

const bool EXEC = true;
const bool NORMAL = false;

class MemberClass
{
private:
	string name; //Member name
	string number; //Member number
	bool memType; //True if exec, false if normal member
	//Date expiration;
	float totalSpent; //Total money spent by member
	MemberClass *nextMember;
	Purchase *firstPurchase;
	Purchase *lastPurchase;

public:
	MemberClass();
	MemberClass(string iName, string iNumber, bool iMemType, float iTotalSpent, MemberClass *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase);
	void SetName(string newName);
	void SetNumber(string newNum);
	void SetType(bool newType);
	void SetSpent(float newSpent);
	void CalcTotalSpent(); //Get total spent

	string GetName();
	string GetNumber();
	bool GetType();
	float GetSpent();
	MemberClass *GetNextMember();
	Purchase *GetFirstPurchase();
	Purchase *GetLastPurchase();
};

class ExecClass:public MemberClass
{
private:
	float rebate;

public:
	void SetRebate(float newRebate);
};

#endif
