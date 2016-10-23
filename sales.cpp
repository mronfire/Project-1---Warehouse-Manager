/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "Sales.h"

//! The SalesDay default constructor
/*!
 * \brief This is the constructor of the SalesDay class
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

//! The SalesDay constructor
/*!
 * \brief This is the constructor of the SalesDay class that takes in a list of parameters
 * \param initRevenue  initializes the revenue of the day
 * \param initExec     initializes the number of executives that made purchases
 * \param initMem      initializes the number of members that made purchases
 * \param initDate     initializes the date
 * \param initTomorrow initializes the pointer that points to the next date
 * \param initFirst    initializes the pointer that points to the first purchase of the day
 * \param initLast     initializes the pointer that points to the last purchase of the day
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

//! The SalesDay constructor
/*!
 * \brief This is the constructor of the SalesDay class that takes in another SalesDay object
 * \details This constructor will be used when we want to construct a SalesDay object for the next day
 * \param a another SalesDay object that is used to initialize another SalesDay object
 */
SalesDay::SalesDay(SalesDay *a) //tommorow constructer
{
    QString today = a->GetDate();

    /*! qints that will be used to hold components of the date */
    qint32 m1 = today.at(0).digitValue();
    qint32 m2 = today.at(1).digitValue(); //ascii needs me to subtract 48 since we're
    qint32 d1 = today.at(3).digitValue(); //using chars technically
    qint32 d2 = today.at(4).digitValue();
    qint32 y3 = today.at(8).digitValue();
    qint32 y4 = today.at(9).digitValue();
    ostringstream tommorow;

    /*!
     * \if the second digit of the day is 9 set it to 0
     * \else increase the second digit of the day by 1
     */
    if(d2 == 9)
    {
        d2 = 0;

        /*!
         * \if the first digit of the day is 2 set it to 0
         * \else increase the first digit of the day by 1
         */
        if(d1 == 2)
        {
            d1 = 0;

            /*!
             * \if the second digit of the month is 9 set it to 0 and set the first digit to 1
             * \else check the month
             */
            if(m2 == 9)
            {
                m2 = 0;
                m1 = 1;
            }
            else
            {

                /*!
                 * \if the first digit of the month is 1 and the second digit is 2 set the first digit to 0 and the second digit to 1
                 * \else increase the second digit of the month by 1
                 */
                if(m1 == 1 && m2 == 2)
                {
                    m1 = 0;
                    m2 = 1;

                    /*!
                      \details this will cause the program to work until the year 2099
                     * \if the fourth digit of the year is 9 set it to 0 and inrease the third digit by 1
                     * \else increase the fourth digit of the year by 1
                     */
                    if(y4 == 9)
                    {
                        y4 = 0;
                        y3++;
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

    /*! Setting the date of tomorrow */
    tommorow << m1 << m2 << '/' << d1 << d2 << "/20" << y3 << y4;

    /*! Type casting the date */
    date = QString::fromStdString(tommorow.str()); //TYPE CASTING
    numExec = 0;
    numMem = 0;
    revenue = 0;
    tomorrow = NULL;
    firstPurchase = NULL;
    lastPurchase = NULL;
}

//! The GetNextDay function
/*!
 * \brief GetNextDay returns a pointer to the next day in the list
 */
SalesDay *SalesDay::GetNextDay()
{
    return tomorrow;
}

//! The GetFirstPurchase function
/*!
 * \brief GetFirstPurchase returns a pointer to the first purchase of the current day
 */
Purchase *SalesDay::GetFirstPurchase()
{
    return firstPurchase;
}

//! The GetDate function
/*!
 * \brief GetDate returns the current date
 */
QString SalesDay::GetDate()
{
    return date;
}

//! The GetMem function
/*!
 * \brief GetMem returns the number of members that have made purchases
 */
int SalesDay::GetMem()
{
    return numMem;
}

//! The GetExec function
/*!
 * \brief GetExec returns the number of executives that have made purchases
 */
int SalesDay::GetExec()
{
    return numExec;
}

//! The GetRevenue function
/*!
 * \brief GetRevenue returns the amount of revenue made in the day
 */
float SalesDay::GetRevenue()
{
    return revenue;
}

//! The SetDate function
/*!
 * \brief SetDate sets the date of the current day
 * \param today The current date
 */
void SalesDay::SetDate(QString today)
{
    date = today;
}

//! The IncreaseRevenue function
/*!
 * \brief IncreaseRevenue increases the revenue made during the day
 * \param addRevenue The revenue that will be added
 */
void SalesDay::IncreaseRevenue(int addRevenue)
{
    revenue += addRevenue;
}

//! The MemberCount function
/*!
 * \brief MemberCount will increase the count of members or executives
 * \param member The type of membership
 */
void SalesDay::MemberCount(bool member)
{
    /*!
     * \if member is an executive increase the executive count
     * \elseif member is regular increase the regular count
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

//! The SetFirstPurchase function
/*!
 * \brief SetFirstPurchase sets the first purchase of the day
 * \param newFirst The first purchase to be added to the list
 */
void SalesDay::SetFirstPurchase(Purchase *newFirst)
{
    firstPurchase = newFirst;
}

//! The SetNextDay function
/*!
 * \brief SetNextDay sets the date for the next day
 * \param a The object for the sales day
 */
void SalesDay::SetNextDay(SalesDay *a)
{
    tomorrow = a;
}

//! The GetLastPurchase function
/*!
 * \brief GetLastPurchase returns the most recent purchase of the current day
 */
Purchase *SalesDay::GetLastPurchase()
{
    return lastPurchase;
}

//! The SetLastPurchase function
/*!
 * \brief SetLastPurchase sets the last purchase of the day
 * \param newLast The last purchase to be added to the list
 */
void SalesDay::SetLastPurchase(Purchase *newLast)
{
    lastPurchase = newLast;
}

//! The AddPurchase function
/*!
 * \brief AddPurcahse will add a purchase to the list of purchases made in the day
 * \param a       The purchase object that will be added
 * \param memList The list of members
 */
void SalesDay::AddPurchase(Purchase *a, member *memList)
{
    member *customer;

    /*!
     * \if the list is empty add to the end of the list
     * \else add to the back of the list
     */
    if(firstPurchase == NULL)
    {
        firstPurchase = a;
    }
    else
    {
        lastPurchase->setNextDay(a);
    }
    lastPurchase = a;

    /*! Increase revenue */
    revenue += (a->getObjPrice() * a->getObjQuantity());

    /*! Member that made purchase */
    customer = memList->GetThisMember(a->getMemberNum());

    /*!
     * \if member was found
     */
    if(customer != NULL)
    {
        /*!
         * \if member is executive increase executive count
         * \else increase the regular count
         */
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

/*! Other functions */
//! The Print function
/*!
 * \brief Print will print out information relevant to the SalesDay class
 * \details Print will print out the number of member purchases, executive purchases and the total revenue made during the day
 */
void SalesDay::Print()
{
    cout << left << setw(18) << "Member purchases:" << numMem << endl;
    cout << setw(21) << "Executive purchases:" << numExec << endl;
    cout << "Total revenue: $" << revenue << endl;
}

//! The SalesDay destructor
/*!
 * \brief This is the destructor for the SalesDay class
 * \param today The current date
 */
SalesDay::~SalesDay()
{

}
