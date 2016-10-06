#include "member.h"

member::member(): name("BLANK"), number("00000"), memType(NORMAL), totalSpent(0), nextMember(NULL), firstPurchase(NULL), lastPurchase(NULL), expiration("BLANK")
{

}

member::member(string iName, string iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase, string iExpiration)
{
    name = iName;
    number = iNumber;
    memType = iMemType;
    totalSpent = iTotalSpent;
    nextMember = iNextMember;
    firstPurchase = iFirstPurchase;
    lastPurchase = iLastPurchase;
    expiration = iExpiration;
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

void member::Expiration(SalesDay a)
{
    char b;
    string today;
    int m1;
    int m2;
    int month1;
    int month2;

    today = a.GetDate();

    b = expiration[0];
    m1 = b;

    b = expiration[1];
    m2 = b;
    month1 = (m1 * 10) + m2;

    b = today[0];
    m1 = b;

    b = today[1];
    m2 = b;

    month2 = (m1 * 10) + m2;

    if(month1 == month2 && expiration[9] == today[9])
    {
        cout << "Your membership expires this month!\n" << "Would you like to renew your membership?";
        cin.get(b);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(b == 'y' || b == 'Y')
        {
            Renew();
        }
        else
        {

        }
    }

}

void member::Renew()
{
    int y1, y2, y3, y4;
    char m;

    y1 = expiration[6];
    y2 = expiration[7];
    y3 = expiration[8];
    y4 = expiration[9];

    if(y4 == 9)
    {
        y4 = 0;
        y3++;

        if(y3 == 10)
        {
            y3 = 0;
            y2++;

            if(y2 == 10)
            {
                y2 = 0;
                y1++;
            }
        }
    }
    else
    {
        y4++;
    }

    m = y1;
    expiration[6] = m;

    m = y2;
    expiration[7] = m;

    m = y3;
    expiration[8] = m;

    m = y4;
    expiration[9] = m;
}

void ExecClass::AdjustType()
{
    bool type;
    float mem, ex;

    mem = 85 + GetSpent();
    ex = 95 + GetSpent() - (rebate * GetSpent());

    type = GetType();

    if(type == EXEC)
    {
        if(mem < ex)
        {
            cout << "You should consider switching to a regular membership!\n";
            ChangeMembership();
        }
        else
        {
            cout << "You should maintain your executive membership.";
        }
    }
    else
    {
        if(mem < ex)
        {
            cout << "You should maintain your regular membership";
        }
        else
        {
            cout << "You should upgrade your membership!";
            ChangeMembership();
        }
    }
}

void ExecClass::ChangeMembership()
{
    if(GetType() == EXEC)
    {
        SetType(NORMAL);
    }
    else
    {
        SetType(EXEC);
    }
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
