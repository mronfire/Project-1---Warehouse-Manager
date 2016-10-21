/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#ifndef MEMBER_H
#define MEMBER_H

#include"purchase.h"
#include<limits>

using namespace std;

/*!
 * CONSTANT VARIABLES
 * ------------------
 * EXEC = A member is an executive member
 * NORMAL = A member is just a regular member
 * REBATE_RATE = The rebate rate for executive members
 */
const bool EXEC = true;
const bool NORMAL = false;
const float REBATE_RATE = 0.0325;

//!The member class
/*!
 * \brief This class is the base class for the members of the bulk club
 */
class member
{
private:
    QString name; /*! The member name */
    QString number; /*! The member number*/
    bool memType; /*! Determines if a member is executive(true) or regular(false) */
    QString expiration; /*! The membership expiration date */
    float totalSpent; /*! Total money spent by a member*/
    float totalTax; /*! Total money spent by member after tax */
    member *nextMember; /*! member pointer that points to the next member */
    Purchase *firstPurchase; /*! purchase pointer that points to the first purchase */
    Purchase *lastPurchase; /*! purchase pointer that points to the last purchase */

public:
    //!The member class constructor
    /*!
     * \brief This is the constructor of the member class
     */
    member();

    //!The member inFile constructor
    /*!
     * \brief This is the constructor that initializes using an input file
     * \param iName initializes the member name
     * \param iNum  initializes the member number
     * \param iType initializes membership type
     * \param iDate initializes membership expiration date
     */
    member(QString iName, QString iNum, bool iType, QString iDate);

    //! The member class constructor with parameters
    /*!
     * \brief This is the constructor of the member class that takes in a list of parameters
     * \param iName          initializes the name of the member
     * \param iNumber        initializes the member number
     * \param iMemType       initializes the membership type of the member
     * \param iTotalSpent    initializes the total amount spent by the member
     * \param iNextMember    initializes the pointer that points to the next member
     * \param iFirstPurchase initializes the pointer that points to the first purchase
     * \param iLastPurchase  initializes the pointer that points to the last purchase
     */
    member(QString iName, QString iNumber, bool iMemType, float iTotalSpent, member *iNextMember, Purchase *iFirstPurchase, Purchase *iLastPurchase);

    /*! Accessor functions */
    //! The GetName function
    /*!
     * \brief GetName returns the name of the member
     * \returns a QString
     */
    QString GetName();

    //! The GetNumber function
    /*!
     * \brief GetNumber returns the number of the member
     * \returns a QString
     */
    QString GetNumber();

    //! The GetType function
    /*!
     * \brief GetType returns the membership type of the member
     * \returns a bool
     */
    bool GetType();

    //! The GetExpiration function
    /*!
     * \brief GetExpiration returns the expiration date of the member
     * \returns a QString
     */
    QString GetExpiration();

    //! The GetSpent function
    /*!
     * \brief GetSpent returns the total ammount of money spent by the member
     * \returns a float
     */
    float GetSpent();

    //! The GetTaxSpent function
    /*!
     * \brief GetTaxSpent returns the total tax of the member
     * \returns a float
     */
    float GetTaxSpent();

    //! The GetNextMember function
    /*!
     * \brief GetNextMember returns the next member of the list
     * \returns a member pointer
     */
    member *GetNextMember();

    //! The GetFirstPurchase function
    /*!
     * \brief GetFirstPurchase returns the first purchase of the member
     * \returns a Purchase pointer
     */
    Purchase *GetFirstPurchase();

    //! The GetLastPurchase function
    /*!
     * \brief GetLastPurchase returns the last purchase of the member
     * \returns a Purchase pointer
     */
    Purchase *GetLastPurchase();

    //! The isWrongType function
    /*!
     * \brief isWrongType returns the membership type of the member
     * \returns a bool
     */
    virtual bool isWrongType();

    //! The GetThisMember function
    /*!
     * \brief GetThisMember returns a pointer that points to a member in the member list
     * \param findNum the member number the function is looking for
     * \returns a member pointer
     */
    member *GetThisMember(QString findNum); //call this from memList

    //! The GetListLength function
    /*!
     * \brief GetListLength returns the length of the member list
     * \returns a qint32
     */
    qint32 GetListLength();

    /*! Mutator functions */

    //! The SetName function
    /*!
     * \brief SetName sets the name of the member
     * \param newName the new name of the member
     */
    void SetName(QString newName);

    //! The SetNumber function
    /*!
     * \brief SetNumber sets the member number
     * \param newNum the new number of the member
     */
    void SetNumber(QString newNum);

    //! The SetType function
    /*!
     * \brief SetType sets the membership type of the member
     * \param newType the new membership type of the member
     */
    void SetType(bool newType);

    //! The ChangeMembership function
    /*!
     * \brief ChangeMembership changes the membership type of the member
     */
    void ChangeMembership();

    //! The Renew function
    /*!
     * \brief Renew renews the membership of the member
     */
    void Renew();

    //! The Renew function with a parameter
    /*!
     * \brief Renew changes the expiration date of the member with a passed in date
     * \param newDate the new expiration date of the member
     */
    void Renew(QString newDate);

    //! The SetSpent function
    /*!
     * \brief SetSpent sets the total ammount spent by the member
     * \param newSpent the ammount spent by the member
     */
    void SetSpent(float newSpent);

    //! The SetNextMember function
    /*!
     * \brief SetNextMember sets the next member of the member list
     * \param newNextMember a pointer that points to the next member
     */
    void SetNextMember(member *newNextMember);

    //! The SetFirstPurchase function
    /*!
     * \brief SetFirstPurchase sets the first purchase of the member
     * \param newPurch pointer that points to the first purchase
     */
    void SetFirstPurchase(Purchase *newPurch);

    //! The SetLastPurchase function
    /*!
     * \brief SetLastPurchase sets the last purchase of the member
     * \param newPurch pointer that points to the last purchase
     */
    void SetLastPurchase(Purchase *newPurch);

    //! The AddToMemberList function
    /*!
     * \brief AddToMemberList adds a member to the member list
     * \param newMember the member being added to the lists
     * \returns a pointer to a member object
     */
    member *AddToMemberList(member *newMember);

    //! The PayTax function
    /*!
     * \brief PayTax calculates the total tax of the member
     * \param receit the tax being added to the total tax
     */
    void PayTax(float receit);

    //! The SpendMoney function
    /*!
     * \brief SpendMoney calculates the total ammount of money spent
     * \param purch pointer that points to a purchase
     */
    void SpendMoney(Purchase *purch);

    //! AddPurchase function
    /*!
     * \brief AddPurchase adds a purchase to the list
     * \param a pointer to a purchase object
     */
    virtual void AddPurchase(Purchase *a);

    /*! Other class methods */

    //! The CalcTotalSpent function
    /*!
     * \brief CalcTotalSpent calculates the total ammount of money spent
     */
    void CalcTotalSpent();

    //! The CalcTotalTax function
    /*!
     * \brief CalcTotalTax calculates the total ammount of money spent including tax
     */
    void CalcTotalTax();

    //! The Expiration function
    /*!
     * \brief Expiration compares the expiration date to the current date
     * \details Expiration will compare the expiration to the current date and will prompt the user to renew their membership
     * \param today the current date
     */
    void Expiration(QString today);

    /*! Overloaded Class Operators */

    //! The overloaded member addition operator
    /*!
     * \brief the overloaded addition operator will add a member to the member list
     * \param newMember the member being added to member list
     */
    member *operator+(member *newMember);

    //! The overloaded purchase addition operator
    /*!
     * \brief the overloaded addition operator will add a purchase to the list
     * \param newPurchase the purchase being added to the list
     */
    void operator+(Purchase *newPurchase);

    //! The member destructor
    /*!
     * \brief ~member is the virtual destructor of the member class
     */
    virtual ~member();
};

//!The ExecClass class
/*!
 * \brief This class is the class derived from the member class for the executive members of bulk club
 */
class ExecClass:public member
{
private:
    float rebate; /*! The rebate rate of executive members */

public:
    //! The ExecClass constructor
    /*!
     * \brief This is the constructor of the ExecClass
     */
    ExecClass();

    //! The ExecClass constructor with parameters
    /*!
     * \brief This is the constructor for the ExecClass that uses a list of parameters
     * \param iName initializes the executive member name
     * \param iNum  initializes the executive member number
     * \param iType initializes the executive member membership type
     * \param iDate initializes the executive member expiration date
     */
    ExecClass(QString iName, QString iNum, bool iType, QString iDate);

    //! The GetRebate function
    /*!
     * \brief GetRebate returns the rebate of the member
     * \returns a float
     */
    float GetRebate();

    //! The SetReabte function
    /*!
     * \brief SetRebate sets the rebate of the member
     * \param newRebate the new rebate of the member
     */
    void SetRebate(float newRebate);

    //! The AddRebate function
    /*!
     * \brief AddRebate calculates the rebate of the member
     * \param purch a pointer that points to a purchase object
     */
    void AddRebate(Purchase *purch);

    //! The isWrongType function
    /*!
     * \brief isWrongType changes the membership type of the member
     * \returns a bool
     */
    virtual bool isWrongType();

    //! The AddPurchase function
    /*!
     * \brief AddPurchase adds a purchase object to the list
     * \param a a pointer that points to a purchase object
     */
    virtual void AddPurchase(Purchase *a);

    //! The ExecClass destructor
    /*!
     * \brief ~ExecClass is the virtual destructor for the ExecClass class
     */
    virtual ~ExecClass();
};

#endif // MEMBER_H
