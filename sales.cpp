/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "Sales.h"

//! Default Constructor
/*!
 * \brief The SalesDay constructor
 */
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

//! Alternative Constructor
/*!
 * \brief The SalesDay alternative constructor will initialize all members using a list of parameters
 * \param initRevenue
 * \param initExec
 * \param initMem
 * \param initDate
 * \param initTomorrow
 * \param initFirst
 * \param initLast
 */
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

//! Alternative Constructor
/*!
 * \brief The SalesDay alternative constructor will create the next sales day
 * \param a
 */
SalesDay::SalesDay(SalesDay *a)
{
    QString today = a->GetDate();

    //!
    //! \brief m1, m2, d1, d2, y3, y4 sets values to hold components of the date
    //!        ascii needs me to substract 48 since we are using chars technically
    //!
    qint32 m1 = today.at(0).digitValue();
    qint32 m2 = today.at(1).digitValue();
    qint32 d1 = today.at(3).digitValue();
    qint32 d2 = today.at(4).digitValue();
    qint32 y3 = today.at(8).digitValue();
    qint32 y4 = today.at(9).digitValue();
    ostringstream tommorow;

    /*!
     * \if this big if-nested statements will add a year to the current year
     */
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
                        y3++; ///program will work until 2099
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

    date = QString::fromStdString(tommorow.str()); ///TYPE CASTING
    numExec = 0;
    numMem = 0;
    revenue = 0;
    tomorrow = NULL;
    firstPurchase = NULL;
    lastPurchase = NULL;
}

//! Get the next sales day
/*!
 * \brief GetNextDay will return a pointer of the next sales day
 * \return next sales day
 */
SalesDay *SalesDay::GetNextDay()
{
    return tomorrow;
}

//! Get the first purchase
/*!
 * \brief GetFirstPurchase will return the first purchase of the day
 * \return the first purchase
 */
Purchase *SalesDay::GetFirstPurchase()
{
    return firstPurchase;
}

//! Get the date of purchase
/*!
 * \brief GetDate will get the day of purchase of the day
 * \return the date of purchase
 */
QString SalesDay::GetDate()
{
    return date;
}

//! Get the member
/*!
 * \brief GetMem will get the number of member in the list
 * \return the member number
 */
int SalesDay::GetMem()
{
    return numMem;
}

//! Get the executive member
/*!
 * \brief GetExec will get the number of executive members in the list
 * \return the executive member number
 */
int SalesDay::GetExec()
{
    return numExec;
}

//! Get the revenue
/*!
 * \brief GetRevenue will return the revenue
 * \return the revenue
 */
float SalesDay::GetRevenue()
{
    return revenue;
}

//! Sets the date
/*!
 * \brief SetDate will set the date of purchase
 * \param today
 */
void SalesDay::SetDate(QString today)
{
    date = today;
}

//! Increase Revenue
/*!
 * \brief IncreaseRevenue will increase the revenue
 * \param addRevenue
 */
void SalesDay::IncreaseRevenue(int addRevenue)
{
    revenue += addRevenue;
}

//! The member count
/*!
 * \brief MemberCount will get the member count
 * \param member
 */
void SalesDay::MemberCount(bool member)
{
    /*!
     * \if this if statement will increase the count of either executive or normal
     */
    if(member == true)
    {
        numExec++;
    }
    else if(member == false)
    {
        numMem++;
    }
}

//! Set the first purchase
/*!
 * \brief SetFirstPurchase will set the first purchase to the front of the list
 * \param newFirst
 */
void SalesDay::SetFirstPurchase(Purchase *newFirst)
{
    firstPurchase = newFirst;
}

//! Set next day
/*!
 * \brief SetLastPurchase will set the next day of sales
 * \param a
 */
void SalesDay::SetNextDay(SalesDay *a)
{
    tomorrow = a;
}

//! Get the last purchase
/*!
 * \brief GetLastPurchase will get the last purchase of the day
 * \return the last purchase
 */
Purchase *SalesDay::GetLastPurchase()
{
    return lastPurchase;
}

//! Set the last purchase
/*!
 * \brief SetLastPurchase will set the last purchase to the end of the list
 * \param newLast
 */
void SalesDay::SetLastPurchase(Purchase *newLast)
{
    lastPurchase = newLast;
}

//! Add purchase
/*!
 * \brief AddPurchase will add the purchase to the end of list
 * \param a
 * \param memList
 */
void SalesDay::AddPurchase(Purchase *a, member *memList)
{
    member *customer;

    /*! \if there is nothing in the list, then add new purchase to the front of the list
     *  \else if there is purchases in the list, then add at the end */
    if(firstPurchase == NULL)
    {
        firstPurchase = a;
    }
    else
    {
        lastPurchase->setNextDay(a);
    }

    lastPurchase = a;

    ///This will increase the revenue of new purchase
    revenue += (a->getObjPrice() * a->getObjQuantity());

    ///This will find customer in the list
    customer = memList->GetThisMember(a->getMemberNum());

    /*! \if customer exist, then increase the count */
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

//! Print information
/*!
 * \brief Print will print information of the day sales
 */
void SalesDay::Print()
{
    cout << left << setw(18) << "Member purchases:" << numMem << endl;
    cout << setw(21) << "Executive purchases:" << numExec << endl;
    cout << "Total revenue: $" << revenue << endl;
}

//! The Destructor
/*!
 * \brief The destructor will destroy the sales day list
 */
SalesDay::~SalesDay()
{

}
