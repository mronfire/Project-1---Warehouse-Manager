#include "member.h"

member::member(): name("BLANK"), number("00000"), memType(NORMAL), totalSpent(0), nextMember(NULL), firstPurchase(NULL), lastPurchase(NULL)
{

}

member::member(string iName, string iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase)
{
    name = iName;
    number = iNumber;
    memType = iMemType;
    totalSpent = iTotalSpent;
    nextMember = iNextMember;
    firstPurchase = iFirstPurchase;
    lastPurchase = iLastPurchase;
}

void member::SetName(string newName)
{
    name = newName;
}

void member::SetNumber(string newNum)
{
    number = newNum;
}

void member::SetType(bool newType)
{
    memType = newType;
}

void member::SetSpent(float newSpent)
{
    totalSpent = newSpent;
}

void member::SetNextMember(member *newNextMember)
{
    nextMember = newNextMember;
}

void member::SetFirstPurchase(Purchase *newPurch)
{
    firstPurchase = newPurch;
}

void member::SetLastPurchase(Purchase *newPurch)
{
    lastPurchase = newPurch;
}

void member::CalcTotalSpent()
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

void member::AddPurchase(Purchase *a)
{
    if(firstPurchase == NULL) //if nothing in the list
    {
        firstPurchase = a; //add to end of list
    }
    else //if stuff in list
    {
        lastPurchase->setNextMember(a); //add to back of list
    }
    lastPurchase = a;
}

string member::GetName()
{
    return name;
}

string member::GetNumber()
{
    return number;
}

bool member::GetType()
{
    return memType;
}

float member::GetSpent()
{
    return totalSpent;
}

member *member::GetNextMember()
{
    return nextMember;
}

Purchase *member::GetFirstPurchase()
{
        return firstPurchase;
}

Purchase *member::GetLastPurchase()
{
        return lastPurchase;
}

void ExecClass::SetRebate(float newRebate)
{
    rebate = newRebate;
}

