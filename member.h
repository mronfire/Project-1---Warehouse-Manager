#ifndef MEMBER_H
#define MEMBER_H

#include"purchase.h"
#include "sales.h"

using namespace std;

const bool EXEC = true;
const bool NORMAL = false;

class member
{
private:
    string name; //Member name
    string number; //Member number
    bool memType; //True if exec, false if normal member
    string expiration;
    float totalSpent; //Total money spent by member
    member *nextMember;
    Purchase *firstPurchase;
    Purchase *lastPurchase;

public:
    member();
    member(string iName, string iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase, string iExpiration);
    void SetName(string newName);
    void SetNumber(string newNum);
    void SetType(bool newType);
    void SetSpent(float newSpent);
    void CalcTotalSpent(); //Get total spent
    void SetNextMember(member *newNextMember);
    void SetFirstPurchase(Purchase *newPurch);
    void SetLastPurchase(Purchase *newPurch);
    void AddPurchase(Purchase *a);
    void Expiration(SalesDay today);
    void Renew();

    string GetName();
    string GetNumber();
    bool GetType();
    float GetSpent();
    member *GetNextMember();
    Purchase *GetFirstPurchase();
    Purchase *GetLastPurchase();
};

class ExecClass:public member
{
private:
    float rebate;

public:
    void SetRebate(float newRebate);
    void AdjustType();
    void ChangeMembership();
};

#endif // MEMBER_H
