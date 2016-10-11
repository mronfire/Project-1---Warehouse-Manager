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
    member(string iName, string iNum, bool iType, string iDate); //infile constructor
    member(string iName, string iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase);

    //accessors
    string GetName();
    string GetNumber();
    bool GetType();
    string GetExpiration();
    float GetSpent();
    float GetTaxSpent();
    member *GetNextMember();
    Purchase *GetFirstPurchase();
    Purchase *GetLastPurchase();

    member *GetThisMember(string findNum); //call this from memList

    //mutators
    void SetName(string newName);
    void SetNumber(string newNum);
    void SetType(bool newType);
    void ChangeMembership();
    void Renew();
    void Renew(string newDate); //aka set new expiration date
    void SetSpent(float newSpent);
    void SetNextMember(member *newNextMember);
    void SetFirstPurchase(Purchase *newPurch);
    void SetLastPurchase(Purchase *newPurch);
    member *AddToMemberList(member *newMember);

    void PayTax(float receit);
    void SpendMoney(Purchase *purch);
    virtual void AddPurchase(Purchase *a);

    //other methods
    void CalcTotalSpent(); //Get total spent
    void CalcTotalTax(); //Get total spent with tax
    void Expiration(string today);
    virtual void AdjustType();

    //destructor
    virtual ~member();
};

class ExecClass:public member
{
private:
    float rebate;

public:
    ExecClass();
    ExecClass(string iName, string iNum, bool iType, string iDate);

    float GetRebate();
    void SetRebate(float newRebate);
    void AddRebate(Purchase *purch);
    virtual void AdjustType();
    virtual void AddPurchase(Purchase *a);
    virtual ~ExecClass();
};

#endif // MEMBER_H
