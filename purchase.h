/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#ifndef PURCHASECLASS_H
#define PURCHASECLASS_H

#include "header.h"

//! The purchase class
class Purchase
{
public:
    /*! Constructors */

    //!The Purchase class constructor
    /*!
     * \brief This is the constructor of the Purchase class
     */
    Purchase();

    //!The Purchase class constructor
    /*!
     * \brief This is the constructor of the Purchase class that initializes using a list of parameters
     * \param num    Initializes the member number
     * \param type   Initializes the object type
     * \param cost   Initializes the cost of the object
     * \param amount Initializes the amount of the object
     * \param date   Initializes the date of the purchase
     */
    Purchase(QString num, QString type, float cost, int amount,
                  QString date);

    //!The Purchase class constructor
    /*!
     * \brief This is the constructor of the Purchase class that initializes using another purchase object
     * \param purchToCopy a pointer that points to a purchase object
     */
    Purchase(Purchase *purchToCopy);

    /*! Mutators */

    //!The setMemberNum function
    /*!
     * \brief The SetMemberNum function will set the number of the member
     * \param num the new member number
     */
    void setMemberNum(QString num);

    //!The setObjType function
    /*!
     * \brief The SetObjType function will set the type of the purchase object
     * \param type the type of purchase object
     */
    void setObjType(QString type);

    //!The setObjPrice function
    /*!
     * \brief The SetObjPrice function will set the price of the purchase object
     * \param cost of the purchase object
     */
    void setObjPrice(float cost);

    //!The setObjQuantity function
    /*!
     * \brief The SetObjQuantity function will set the amount of objects being purchased
     * \param amount the amount of objects being purchased
     */
    void setObjQuantity(int amount);

    //!The setPurchaseDate function
    /*!
     * \brief The setPurchaseDate function will set date of the day that the purcahse was made
     * \param date the date that the purchase was made
     */
    void setPurchaseDate(QString date);

    //!The setNextMember function
    /*!
     * \brief The setNextMember function will set the purcahse pointer to point to the next member
     * \param otherMember pointer that points to another member
     */
    void setNextMember(Purchase *otherMember);

    //!The setNextDay function
    /*!
     * \brief The setNextDay function will set the pointer of the purcahse object to point to the next day
     * \param otherDay purchase pointer that points to another day
     */
    void setNextDay(Purchase *otherDay);

    /*! Accessors */

    //!The getPurchaseDate function
    /*!
     * \brief The getPurchaseDate function will return the date of the purchase
     * \returns a QString
     */
    QString getPurchaseDate() const;

    //!The getMemberNum function
    /*!
     * \brief The getMemberNum function will return the member number
     * \returns a QString
     */
    QString getMemberNum() const;

    //!The getObjType function
    /*!
     * \brief The getObjType function will return the type of the object
     * \returns a QString
     */
    QString getObjType() const;

    //!The getObjPrice function
    /*!
     * \brief The getObjPrice function will return the price of the object
     * \returns a float
     */
    float getObjPrice() const;

    //!The getObjQuantity function
    /*!
     * \brief The getObjQuantity function will return the amount of objects purchased
     * \returns an int
     */
    int getObjQuantity() const;

    //!The getNextMember function
    /*!
     * \brief The getNextMember function will return a pointer that points to the next member
     * \returns a Purchase pointer
     */
    Purchase *getNextMember() const;

    //!The getNextDay function
    /*!
     * \brief The getNextDay function will return a pointer that points to the next day
     * \returns a Purchase pointer
     */
    Purchase *getNextDay() const;

private:

    QString memberNum;    /*! The number of the member */
    QString objectType;   /*! The type of the purchase object */
    float  price;         /*! The price of an individual object */
    int    quantity;      /*! The amount of objects that have been purchased */
    QString purchaseDate; /*! The date that an object was purchased */
    Purchase *nextMember; /*! Purchase pointer that points to the next member */
    Purchase *nextDay;    /*! Purchase pointer that points to the next day */

};

#endif // PURCHASECLASS_H
