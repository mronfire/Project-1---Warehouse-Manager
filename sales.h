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

//!
//! \brief The SalesDay class contains the days a sale was made
//!
class SalesDay
{
private:
    float revenue;              /*!< The revenue of purhcases for the day */
    int numExec;                /*!< The number of executive members */
    int numMem;                 /*!< The number of normal members */
    QString date;               /*!< The date of purchase */
    SalesDay *tomorrow;         /*!< Pointer to next day */
    Purchase *firstPurchase;    /*!< Pointer to first purhcase of the day */
    Purchase *lastPurchase;     /*!< Pointer to last purchase of the day */
public:

    //! Default Constructor
    /*!
     * \brief The SalesDay constructor
     */
    SalesDay();

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
    SalesDay(float initRevenue, int initExec, int initMem, QString initDate,
             SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast);

    //! Alternative Constructor
    /*!
     * \brief The SalesDay alternative constructor will create the next sales day
     * \param a
     */
    SalesDay(SalesDay *a);

    //! Get the next sales day
    /*!
     * \brief GetNextDay will return a pointer of the next sales day
     * \return next sales day
     */
    SalesDay *GetNextDay();

    //! Get the first purchase
    /*!
     * \brief GetFirstPurchase will return the first purchase of the day
     * \return the first purchase
     */
    Purchase *GetFirstPurchase();

    //! Get the last purchase
    /*!
     * \brief GetLastPurchase will get the last purchase of the day
     * \return the last purchase
     */
    Purchase *GetLastPurchase();

    //! Get the date of purchase
    /*!
     * \brief GetDate will get the day of purchase of the day
     * \return the date of purchase
     */
    QString GetDate();

    //! Get the member
    /*!
     * \brief GetMem will get the number of member in the list
     * \return the member number
     */
    int GetMem();

    //! Get the executive member
    /*!
     * \brief GetExec will get the number of executive members in the list
     * \return the executive member number
     */
    int GetExec();

    //! Get the revenue
    /*!
     * \brief GetRevenue will return the revenue
     * \return the revenue
     */
    float GetRevenue();

    //! Sets the date
    /*!
     * \brief SetDate will set the date of purchase
     * \param today
     */
    void SetDate(QString today);

    //! Increase Revenue
    /*!
     * \brief IncreaseRevenue will increase the revenue
     * \param addRevenue
     */
    void IncreaseRevenue(int addRevenue);

    //! The member count
    /*!
     * \brief MemberCount will get the member count
     * \param member
     */
    void MemberCount(bool member);

    //! Add purchase
    /*!
     * \brief AddPurchase will add the purchase to the end of list
     * \param a
     * \param memList
     */
    void AddPurchase(Purchase *a, member *memList);

    //! Set the first purchase
    /*!
     * \brief SetFirstPurchase will set the first purchase to the front of the list
     * \param newFirst
     */
    void SetFirstPurchase(Purchase *newFirst);

    //! Set the last purchase
    /*!
     * \brief SetLastPurchase will set the last purchase to the end of the list
     * \param newLast
     */
    void SetLastPurchase(Purchase *newLast);

    //! Set next day
    /*!
     * \brief SetLastPurchase will set the next day of sales
     * \param a
     */
    void SetNextDay(SalesDay *a);

    //! Print information
    /*!
     * \brief Print will print information of the day sales
     */
    void Print();

    //! The Destructor
    /*!
     * \brief The destructor will destroy the sales day list
     */
    ~SalesDay();
};

#endif // SALES_H
