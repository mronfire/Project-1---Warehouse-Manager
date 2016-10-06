#ifndef MEMBER_H
#define MEMBER_H

#include"purchase.h"
#include<limits>

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
    float totalSpent; //Total money spent by member
    float totalTax; //Total money spent by member after tax
    member *nextMember;
    Purchase *firstPurchase;
    Purchase *lastPurchase;

public:
    member();
    member(string iName, string iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase);
    void SetName(string newName);
    void SetNumber(string newNum);
    void SetType(bool newType);
    void SetSpent(float newSpent);
    void CalcTotalSpent(); //Get total spent
    void CalcTotalTax(); //Get total spent with tax
    void SetNextMember(member *newNextMember);
    void SetFirstPurchase(Purchase *newPurch);
    void SetLastPurchase(Purchase *newPurch);
    virtual void AddPurchase(Purchase *a);
    void Expiration(string today);
    void Renew();
    void ChangeMembership();

    string GetName();
    string GetNumber();
    bool GetType();
    float GetSpent();
    float GetTaxSpent();
    member *GetNextMember();
    Purchase *GetFirstPurchase();
    Purchase *GetLastPurchase();
    member *GetThisMember(string findNum); //call this from memList
};

class ExecClass:public member
{
private:
    float rebate;

public:
    float GetRebate();
    void SetRebate(float newRebate);
    void AddRebate(Purchase *purch);
    void AdjustType();
    virtual void AddPurchase(Purchase *a);
};

#endif // MEMBER_H
