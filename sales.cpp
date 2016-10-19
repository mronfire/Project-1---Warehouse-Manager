/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "Sales.h"

SalesDay::SalesDay()
{
    numExec = 0;
    numMem = 0;
    revenue = 0;
    date = "";
    tomorrow = NULL;
    firstPurchase = NULL;
    lastPurchase = NULL;

}

SalesDay::SalesDay(float initRevenue, int initExec, int initMem, QString initDate, SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast)
{
    revenue = initRevenue;
    numExec = initExec;
    numMem = initMem;
    date = initDate;
    tomorrow = initTomorrow;
    firstPurchase = initFirst;
    lastPurchase = initLast;
}

SalesDay::SalesDay(SalesDay *a) //tommorow constructer
{
    QString today = a->GetDate();
    qint32 m1 = today.at(0).digitValue(); //sets values to hold components of the date
    qint32 m2 = today.at(1).digitValue(); //ascii needs me to subtract 48 since we're
    qint32 d1 = today.at(3).digitValue(); //using chars technically
    qint32 d2 = today.at(4).digitValue();
    qint32 y3 = today.at(8).digitValue();
    qint32 y4 = today.at(9).digitValue();
    ostringstream tommorow;

    if(d2 == 9)
    {
        d2 = 0;
        if(d1 == 2)
        {
            d1 = 0;
            if(m2 == 9)
            {
                m2 = 0;
                m1 = 1;
            }
            else
            {
                if(m1 == 1 && m2 == 2)
                {
                    m1 = 0;
                    m2 = 1;
                    if(y4 == 9)
                    {
                        y4 = 0;
                        y3++; //program will work until 2099
                    }
                    else
                    {
                        y4++;
                    }
                }
                else
                {
                    m2++;
                }
            }
        }
        else
        {
            d1++;
        }
    }
    else
    {
        d2++;
    }

    tommorow << m1 << m2 << '/' << d1 << d2 << "/20" << y3 << y4;

    date = QString::fromStdString(tommorow.str()); //TYPE CASTING
    numExec = 0;
    numMem = 0;
    revenue = 0;
    tomorrow = NULL;
    firstPurchase = NULL;
    lastPurchase = NULL;
}

SalesDay *SalesDay::GetNextDay()
{
    return tomorrow;
}

Purchase *SalesDay::GetFirstPurchase()
{
    return firstPurchase;
}

QString SalesDay::GetDate()
{
    return date;
}

int SalesDay::GetMem()
{
    return numMem;
}

int SalesDay::GetExec()
{
    return numExec;
}

float SalesDay::GetRevenue()
{
    return revenue;
}

void SalesDay::SetDate(QString today)
{
    date = today;
}

void SalesDay::IncreaseRevenue(int addRevenue)
{
    revenue += addRevenue;
}

void SalesDay::MemberCount(bool member)
{
    if(member == true)
    {
        numExec++;
    }
    else if(member == false)
    {
        numMem++;
    }
}

void SalesDay::SetFirstPurchase(Purchase *newFirst)
{
    firstPurchase = newFirst;
}

void SalesDay::SetNextDay(SalesDay *a)
{
    tomorrow = a;
}

void SalesDay::AddPurchase(Purchase *a, member *memList)
{
    member *customer;

    if(firstPurchase == NULL) //if nothing in the list
    {
        firstPurchase = a; //add to end of list
    }
    else //if stuff in list
    {
        lastPurchase->setNextDay(a); //add to back of list
    }
    lastPurchase = a;

    revenue += (a->getObjPrice() * a->getObjQuantity());

    customer = memList->GetThisMember(a->getMemberNum());

    if(customer != NULL)
    {
        if(customer->GetType())
        {
            numExec++;
        }
        else
        {
            numMem++;
        }
    }
}

void SalesDay::Print()
{
    cout << left << setw(18) << "Member purchases:" << numMem << endl;
    cout << setw(21) << "Executive purchases:" << numExec << endl;
    cout << "Total revenue: $" << revenue << endl;
}

SalesDay::~SalesDay()
{

}
