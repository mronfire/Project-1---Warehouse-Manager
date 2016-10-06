#ifndef MEMBER_H
#define MEMBER_H

#include"purchase.h"

using namespace std;

const bool EXEC = true;
const bool NORMAL = false;
const float REBATE_RATE = 0.0325;

class member
{
private:
    string name; //Member name
    string number; //Member number
    bool memType; //True if exec, false if normal member
    string expiration;
    float totalSpent; //Total money spent by member before tax
    float totalTax; //Total money spent by member after tax
    member *nextMember;
    Purchase *firstPurchase;
    Purchase *lastPurchase;

public:
    member();
    member(string iName, string iNumber, bool iMemType, float iTotalSpent, float iTotalTax, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase);
    void SetName(string newName);
    void SetNumber(string newNum);
    void SetType(bool newType);
    void SetSpent(float newSpent);
    void CalcTotalSpent(); //Get total spent
    void CalcTotalTax(); //Get total spent with tax
    void SetNextMember(member *newNextMember);
    void SetFirstPurchase(Purchase *newPurch);
    void SetLastPurchase(Purchase *newPurch);
    void AddPurchase(Purchase *a);
    void Expiration(string today);
    void Renew();

    string GetName();
    string GetNumber();
    bool GetType();
    float GetSpent();
    float GetTaxSpent();
    member *GetNextMember();
    Purchase *GetFirstPurchase();
    Purchase *GetLastPurchase();
};

class ExecClass:public member
{
private:
    float rebate;

public:
    void CalcRebate(); //Calculates rebate using total spent before tax
    void AdjustType();
    void ChangeMembership();

    float GetRebate();
};

#endif
