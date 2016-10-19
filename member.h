/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
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
    QString name; //Member name
    QString number; //Member number
    bool memType; //True if exec, false if normal member
    QString expiration;
    float totalSpent; //Total money spent by member
    float totalTax; //Total money spent by member after tax
    member *nextMember;
    Purchase *firstPurchase;
    Purchase *lastPurchase;

public:
    member();
    member(QString iName, QString iNum, bool iType, QString iDate); //infile constructor
    member(QString iName, QString iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase);

    //accessors
    QString GetName();
    QString GetNumber();
    bool GetType();
    QString GetExpiration();
    float GetSpent();
    float GetTaxSpent();
    member *GetNextMember();
    Purchase *GetFirstPurchase();
    Purchase *GetLastPurchase();

    member *GetThisMember(QString findNum); //call this from memList
    qint32 GetListLength();

    //mutators
    void SetName(QString newName);
    void SetNumber(QString newNum);
    void SetType(bool newType);
    void ChangeMembership();
    void Renew();
    void Renew(QString newDate); //aka set new expiration date
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
    void Expiration(QString today);
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
    ExecClass(QString iName, QString iNum, bool iType, QString iDate);

    float GetRebate();
    void SetRebate(float newRebate);
    void AddRebate(Purchase *purch);
    virtual void AdjustType();
    virtual void AddPurchase(Purchase *a);
    virtual ~ExecClass();
};

#endif // MEMBER_H
