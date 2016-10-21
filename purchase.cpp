/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "purchase.h"

//!The Purchase class constructor
/*!
 * \brief This is the constructor of the Purchase class
 */
Purchase::Purchase()
{
    memberNum.clear();
    objectType.clear();
    price         = 0.00;
    quantity      = 0;
    purchaseDate.clear();
    nextMember    = NULL;
    nextDay       = NULL;
}

//!The Purchase class constructor
/*!
 * \brief This is the constructor of the Purchase class that initializes using a list of parameters
 * \param num    Initializes the member number
 * \param type   Initializes the object type
 * \param cost   Initializes the cost of the object
 * \param amount Initializes the amount of the object
 * \param date   Initializes the date of the purchase
 */
Purchase::Purchase(QString num, QString type, float cost, int amount,
                             QString date)
{
    memberNum    = num;
    objectType   = type;
    price        = cost;
    quantity     = amount;
    purchaseDate = date;
    nextMember   = NULL;
    nextDay      = NULL;
}

//!The Purchase class constructor
/*!
 * \brief This is the constructor of the Purchase class that initializes using another purchase object
 * \param purchToCopy a pointer that points to a purchase object
 */
Purchase::Purchase(Purchase *purchToCopy)
{
    memberNum    = purchToCopy->getMemberNum();
    objectType   = purchToCopy->getObjType();
    price        = purchToCopy->getObjPrice();
    quantity     = purchToCopy->getObjQuantity();
    purchaseDate = purchToCopy->getPurchaseDate();
    nextMember   = NULL;
    nextDay      = NULL;
}

//!The setMemberNum function
/*!
 * \brief The SetMemberNum function will set the number of the member
 * \param num the new member number
 */
void Purchase::setMemberNum(QString num)
{
    memberNum = num;
}

//!The setObjType function
/*!
 * \brief The SetObjType function will set the type of the purchase object
 * \param type the type of purchase object
 */
void Purchase::setObjType(QString type)
{
    objectType = type;
}

//!The setObjPrice function
/*!
 * \brief The SetObjPrice function will set the price of the purchase object
 * \param cost of the purchase object
 */
void Purchase::setObjPrice(float cost)
{
    price = cost;
}

//!The setObjQuantity function
/*!
 * \brief The SetObjQuantity function will set the amount of objects being purchased
 * \param amount the amount of objects being purchased
 */
void Purchase::setObjQuantity(int amount)
{
    quantity = amount;
}

//!The setPurchaseDate function
/*!
 * \brief The setPurchaseDate function will set date of the day that the purcahse was made
 * \param date the date that the purchase was made
 */
void Purchase::setPurchaseDate(QString date)
{
    purchaseDate = date;
}

//!The setNextMember function
/*!
 * \brief The setNextMember function will set the purcahse pointer to point to the next member
 * \param otherMember pointer that points to another member
 */
void Purchase::setNextMember(Purchase *otherMember)
{
    nextMember = otherMember;
}

//!The setNextDay function
/*!
 * \brief The setNextDay function will set the pointer of the purcahse object to point to the next day
 * \param otherDay purchase pointer that points to another day
 */
void Purchase::setNextDay(Purchase *otherDay)
{
    nextDay = otherDay;
}

//!The getMemberNum function
/*!
 * \brief The getMemberNum function will return the member number
 * \returns a QString
 */
QString Purchase::getMemberNum() const
{
    return memberNum;
}

//!The getObjType function
/*!
 * \brief The getObjType function will return the type of the object
 * \returns a QString
 */
QString Purchase::getObjType() const
{
    return objectType;
}

//!The getObjPrice function
/*!
 * \brief The getObjPrice function will return the price of the object
 * \returns a float
 */
float Purchase::getObjPrice() const
{
    return price;
}

//!The getObjQuantity function
/*!
 * \brief The getObjQuantity function will return the amount of objects purchased
 * \returns an int
 */
int Purchase::getObjQuantity() const
{
    return quantity;
}

//!The getPurchaseDate function
/*!
 * \brief The getPurchaseDate function will return the date of the purchase
 * \returns a QString
 */
QString Purchase::getPurchaseDate() const
{
    return purchaseDate;
}

//!The getNextMember function
/*!
 * \brief The getNextMember function will return a pointer that points to the next member
 * \returns a Purchase pointer
 */
Purchase *Purchase::getNextMember() const
{
    return nextMember;
}

//!The getNextDay function
/*!
 * \brief The getNextDay function will return a pointer that points to the next day
 * \returns a Purchase pointer
 */
Purchase *Purchase::getNextDay() const
{
    return nextDay;
}
