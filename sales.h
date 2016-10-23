/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#ifndef SALES_H
#define SALES_H

#include "header.h"
#include "purchase.h"
#include "member.h"

//! The SalesDay class
/*!
 * \brief The SalesDay class will keep track of the each day
 * \details The SalesDay class will keep track of each day and the purchases that were made in that day
 *          and will keep track of the total revenue of each day and how many members made purchases that day
 */
class SalesDay
{
private:
    float revenue;           /*! The revenue of the current day */
    int numExec;             /*! The number of executives that made purchases on that day */
    int numMem;              /*! The number of members that made purchases on that day */
    QString date;            /*! The date */
    SalesDay *tomorrow;      /*! Pointer that points to the next day */
    Purchase *firstPurchase; /*! Pointer that points to the first purchase of the day */
    Purchase *lastPurchase;  /*! Pointer that points to the last purchase of the day */
public:

    //! The SalesDay default constructor
    /*!
     * \brief This is the constructor of the SalesDay class
     */
    SalesDay();

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
    SalesDay(float initRevenue, int initExec, int initMem, QString initDate, SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast);

    //! The SalesDay constructor
    /*!
     * \brief This is the constructor of the SalesDay class that takes in another SalesDay object
     * \param a another SalesDay object that is used to initialize another SalesDay object
     */
    SalesDay(SalesDay *a);

    /*! Accessor functions */

    //! The GetNextDay function
    /*!
     * \brief GetNextDay returns a pointer to the next day in the list
     */
    SalesDay *GetNextDay();

    //! The GetFirstPurchase function
    /*!
     * \brief GetFirstPurchase returns a pointer to the first purchase of the current day
     */
    Purchase *GetFirstPurchase();

    //! The GetLastPurchase function
    /*!
     * \brief GetLastPurchase returns the most recent purchase of the current day
     */
    Purchase *GetLastPurchase();

    //! The GetDate function
    /*!
     * \brief GetDate returns the current date
     */
    QString GetDate();

    //! The GetMem function
    /*!
     * \brief GetMem returns the number of members that have made purchases
     */
    int GetMem();

    //! The GetExec function
    /*!
     * \brief GetExec returns the number of executives that have made purchases
     */
    int GetExec();

    //! The GetRevenue function
    /*!
     * \brief GetRevenue returns the amount of revenue made in the day
     */
    float GetRevenue();

    /*! Mutator functions */

    //! The SetDate function
    /*!
     * \brief SetDate sets the date of the current day
     * \param today The current date
     */
    void SetDate(QString today);

    //! The IncreaseRevenue function
    /*!
     * \brief IncreaseRevenue increases the revenue made during the day
     * \param addRevenue The revenue that will be added
     */
    void IncreaseRevenue(int addRevenue);

    //! The MemberCount function
    /*!
     * \brief MemberCount will increase the count of members or executives
     * \param member The type of membership
     */
    void MemberCount(bool member);

    //! The AddPurchase function
    /*!
     * \brief AddPurcahse will add a purchase to the list of purchases made in the day
     * \param a       The purchase object that will be added
     * \param memList The list of members
     */
    void AddPurchase(Purchase *a, member *memList);

    //! The SetFirstPurchase function
    /*!
     * \brief SetFirstPurchase sets the first purchase of the day
     * \param newFirst The first purchase to be added to the list
     */
    void SetFirstPurchase(Purchase *newFirst);

    //! The SetLastPurchase function
    /*!
     * \brief SetLastPurchase sets the last purchase of the day
     * \param newLast The last purchase to be added to the list
     */
    void SetLastPurchase(Purchase *newLast);

    //! The SetNextDay function
    /*!
     * \brief SetNextDay sets the date for the next day
     * \param a The object for the sales day
     */
    void SetNextDay(SalesDay *a);

    /*! Other functions */
    //! The Print function
    /*!
     * \brief Print will print out information relevant to the SalesDay class
     */
    void Print();

    /*! Destructor */

    //! The SalesDay destructor
    /*!
     * \brief This is the destructor for the SalesDay class
     * \param today The current date
     */
    ~SalesDay();
};

#endif // SALES_H
