#include "member.h"

member::member(): name("BLANK"), number("00000"), memType(NORMAL), totalSpent(0),
                  totalTax(0), expiration("01/01/2020"), nextMember(NULL),
                  firstPurchase(NULL), lastPurchase(NULL)
{

}

member::member(QString iName, QString iNum, bool iType, QString iDate)
{
    name = iName;
    number = iNum;
    memType = iType;
    expiration = iDate;
    totalSpent = 0;
    totalTax = 0;
    nextMember = NULL;
    firstPurchase = NULL;
    lastPurchase = NULL;
}

member::member(QString iName, QString iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase)
{
    name = iName;
    number = iNumber;
    memType = iMemType;
    totalSpent = iTotalSpent;
    nextMember = iNextMember;
    firstPurchase = iFirstPurchase;
    lastPurchase = iLastPurchase;
}

ExecClass::ExecClass():member()
{
    SetType(true); //sets to executive member
    rebate = 0;
}

ExecClass::ExecClass(QString iName, QString iNum, bool iType, QString iDate)
            :member(iName, iNum, iType, iDate)
{
    rebate = 0;
}

void member::SetName(QString newName)
{
    name = newName;
}

void member::SetNumber(QString newNum)
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

void member::CalcTotalTax()
{
    float tax;

    tax = totalSpent * TAX_RATE;

    totalTax = totalSpent + tax;
}

void member::Expiration(QString a)
{
    char b;
    QString today;
    int m1;
    int m2;
    int month1;
    int month2;

    today = a;

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

void member::Renew(QString newDate)
{
    expiration = newDate;
}

member *member::AddToMemberList(member *newMember)
{
    if(nextMember == NULL)//if last item in list
    {
        nextMember = newMember;
    }
    else
    {
        nextMember->AddToMemberList(newMember);
    }

    return newMember; //returns so we can put get adress of last in list
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

    SpendMoney(a);
}

void ExecClass::AddPurchase(Purchase *a)
{
    if(GetFirstPurchase() == NULL) //if nothing in the list
    {
        SetFirstPurchase(a); //add to end of list
    }
    else //if stuff in list
    {
        GetLastPurchase()->setNextMember(a); //add to back of list
    }
    SetLastPurchase(a);

    SpendMoney(a);
    AddRebate(a);
}

QString member::GetName()
{
    return name;
}

QString member::GetNumber()
{
    return number;
}

bool member::GetType()
{
    return memType;
}

QString member::GetExpiration()
{
    return expiration;
}

float member::GetSpent()
{
    return totalSpent;
}

float member::GetTaxSpent()
{
    return totalTax;
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

member *member::GetThisMember(QString findNum)
{
    member *memptr;

    if(number == findNum)
    {
        memptr = this;
    }
    else
    {
        if(nextMember != NULL)
        {
            memptr = nextMember->GetThisMember(findNum);
            //recursive call goes through list until it finds member
        }
        else
        {
            memptr = NULL;
            //if the member can't be found, return NULL
        }
    }

    return memptr;
}

float ExecClass::GetRebate()
{
    return rebate;
}

void ExecClass::SetRebate(float newRebate)
{
    rebate = newRebate;
}

void ExecClass::AddRebate(Purchase *purch)
{
    float receit;

    receit = purch->getObjPrice() * purch->getObjQuantity();

    rebate += receit * REBATE_RATE;
}

void member::AdjustType()
{
    float mem, ex;

    mem = 85 + GetSpent();
    ex = 95 + GetSpent() - (REBATE_RATE * GetSpent());

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

void ExecClass::AdjustType()
{
    float mem, ex;

    mem = 85 + GetSpent();
    ex = 95 + GetSpent() - rebate;

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

void member::ChangeMembership()
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

void member::SpendMoney(Purchase *purch)
{
    float receit;
    receit = purch->getObjPrice() * purch->getObjQuantity();
    totalSpent += receit;
    receit += receit * TAX_RATE;
    PayTax(receit); //total tax money spent after tax
}

void member::PayTax(float receit)
{
    totalTax += receit;
}

member::~member()
{

}

ExecClass::~ExecClass()
{

}



