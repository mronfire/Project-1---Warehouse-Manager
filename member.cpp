/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "member.h"

//!The member class constructor
/*!
 * \brief This is the constructor of the member class
 * \details The default constructor will run when a member object is created without any parameters
 */
member::member(): name("BLANK"), number("00000"), memType(NORMAL), totalSpent(0),
                  totalTax(0), expiration("01/01/2020"), nextMember(NULL),
                  firstPurchase(NULL), lastPurchase(NULL)
{

}

//!The member inFile constructor
/*!
 * \brief This is the constructor that initializes using an input file
 * \details This constructor will run when initializing member functions using an input file
 * \param iName initializes the member name
 * \param iNum  initializes the member number
 * \param iType initializes membership type
 * \param iDate initializes membership expiration date
 */
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

//! The member class constructor with parameters
/*!
 * \brief This is the constructor of the member class that takes in a list of parameters
 * \details This constructor will be used when initializing a member object using a list of parameters
 * \param iName          initializes the name of the member
 * \param iNumber        initializes the member number
 * \param iMemType       initializes the membership type of the member
 * \param iTotalSpent    initializes the total amount spent by the member
 * \param iNextMember    initializes the pointer that points to the next member
 * \param iFirstPurchase initializes the pointer that points to the first purchase
 * \param iLastPurchase  initializes the pointer that points to the last purchase
 */
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

//!The ExecClass class
/*!
 * \brief This is the constructor of the ExecClass
 * \details This constructor will be used when initializing an ExecClass member with no parameters
 */
ExecClass::ExecClass():member()
{
    SetType(true); //sets to executive member
    rebate = 0;
}

//! The ExecClass constructor with parameters
/*!
 * \brief This is the constructor for the ExecClass that uses a list of parameters
 * \details This constructor will be used when initializing an ExecClass object with a list of parameters
 * \param iName initializes the executive member name
 * \param iNum  initializes the executive member number
 * \param iType initializes the executive member membership type
 * \param iDate initializes the executive member expiration date
 */
ExecClass::ExecClass(QString iName, QString iNum, bool iType, QString iDate)
            :member(iName, iNum, iType, iDate)
{
    rebate = 0;
}

//! The SetName function
/*!
 * \brief SetName sets the name of the member
 * \param newName the new name of the member
 */
void member::SetName(QString newName)
{
    name = newName;
}

//! The SetNumber function
/*!
 * \brief SetNumber sets the member number
 * \param newNum the new number of the member
 */
void member::SetNumber(QString newNum)
{
    number = newNum;
}

//! The SetType function
/*!
 * \brief SetType sets the membership type of the member
 * \param newType the new membership type of the member
 */
void member::SetType(bool newType)
{
    memType = newType;
}

//! The SetSpent function
/*!
 * \brief SetSpent sets the total ammount spent by the member
 * \param newSpent the ammount spent by the member
 */
void member::SetSpent(float newSpent)
{
    totalSpent = newSpent;
}

//! The SetNextMember function
/*!
 * \brief SetNextMember sets the next member of the member list
 * \param newNextMember a pointer that points to the next member
 */
void member::SetNextMember(member *newNextMember)
{
    nextMember = newNextMember;
}

//! The SetFirstPurchase function
/*!
 * \brief SetFirstPurchase sets the first purchase of the member
 * \param newPurch pointer that points to the first purchase
 */
void member::SetFirstPurchase(Purchase *newPurch)
{
    firstPurchase = newPurch;
}

//! The SetLastPurchase function
/*!
 * \brief SetLastPurchase sets the last purchase of the member
 * \param newPurch pointer that points to the last purchase
 */
void member::SetLastPurchase(Purchase *newPurch)
{
    lastPurchase = newPurch;
}

//! The CalcTotalSpent function
/*!
 * \brief CalcTotalSpent calculates the total ammount of money spent
 * \details CalcTotalSpent will go through the list of purchases of a member and will calculate the total ammount of money spent
 */
void member::CalcTotalSpent()
{
    bool quit = false;
    Purchase *temp;
    int quantity;
    float price;
    float purchTotal;
    float total = 0;

    temp = firstPurchase;

    /*! While loop that goes through the list of member purchases to calculate the total*/
    /*! money spent until it reaches the end of the list*/
    while(quit == false)
    {
        price = temp->getObjPrice();
        quantity = temp->getObjQuantity();
        purchTotal = quantity * price;
        total += purchTotal;
        temp = temp->getNextMember();

        /*! \if the purchase is the last purchase quit the loop*/
        if(temp == lastPurchase)
        {
            quit = true;
        }
    }
}

//! The CalcTotalTax function
/*!
 * \brief CalcTotalTax calculates the total ammount of money spent including tax
 */
void member::CalcTotalTax()
{
    float tax;

    tax = totalSpent * TAX_RATE;

    totalTax = totalSpent + tax;
}

//! The Expiration function
/*!
 * \brief Expiration compares the expiration date to the current date
 * \details Expiration will compare the expiration to the current date and will prompt the user to renew their membership
 * \param today the current date
 */
void member::Expiration(QString a)
{
    QChar b;
    QString today;
    qint32 m1;
    qint32 m2;
    qint32 month1;
    qint32 month2;

    today = a;

    m1 = expiration.at(0).digitValue();
    m2 = expiration.at(1).digitValue();
    month1 = (m1 * 10) + m2;

    m1 = today.at(0).digitValue();
    m2 = today.at(1).digitValue();
    month2 = (m1 * 10) + m2;

    /*! \if the expiration date is today */
    if(month1 == month2 && expiration[9] == today[9])
    {
        cout << "Your membership expires this month!\n" << "Would you like to renew your membership?";
        //cin.get(b); //Can't get from console. Assign to buttons.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        /*! \if member wants to renew their membership */
        if(b == 'y' || b == 'Y')
        {
            Renew();
        }
        else
        {

        }
    }

}

//! The Renew function
/*!
 * \brief Renew renews the membership of the member
 * \details The Renew function will renew the membership and set the expiration date to one year later
 */
void member::Renew()
{
    int y1, y2, y3, y4;
    char m;

    y1 = expiration.at(6).digitValue();
    y2 = expiration.at(7).digitValue();
    y3 = expiration.at(8).digitValue();
    y4 = expiration.at(9).digitValue();

    /*! \if the fourth digit of the year is 9 set it to 0 and increment third digit */
    if(y4 == 9)
    {
        y4 = 0;
        y3++;

        /*! \if the third digit of the year is 10 set it to 0 and increment second digit */
        if(y3 == 10)
        {
            y3 = 0;
            y2++;

            /*! \if the second digit of the year is 10 set it to 0 and increment first digit */
            if(y2 == 10)
            {
                y2 = 0;
                y1++;
            }
        }
    }
    /*! \else increment fourth digit */
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

//! The Renew function with a parameter
/*!
 * \brief Renew changes the expiration date of the member with a passed in date
 * \param newDate the new expiration date of the member
 */
void member::Renew(QString newDate)
{
    expiration = newDate;
}

//! The AddToMemberList function
/*!
 * \brief AddToMemberList adds a member to the member list
 * \param newMember the member being added to the lists
 * \returns a pointer to a member object
 */
member *member::AddToMemberList(member *newMember)
{
    /*!
     * \if the member is the last in the list add member to the end of the list
     * \else go to the next member
     */

    if(nextMember == NULL)
    {
        nextMember = newMember;
    }
    else
    {
        nextMember->AddToMemberList(newMember);
    }

    return newMember; //returns so we can put get adress of last in list
}

//! AddPurchase function
/*!
 * \brief AddPurchase adds a purchase to the list
 * \param a pointer to a purchase object
 */
void member::AddPurchase(Purchase *a)
{
    /*!
     * \if the list is empty add to the top of the list
     * \else add the purchase to the end of the list
     */
    if(firstPurchase == NULL)
    {
        firstPurchase = a;
    }
    else
    {
        lastPurchase->setNextMember(a);
    }
    lastPurchase = a;

    SpendMoney(a);
}

//! The AddPurchase function
/*!
 * \brief AddPurchase adds a purchase object to the list
 * \param a a pointer that points to a purchase object
 */
void ExecClass::AddPurchase(Purchase *a)
{
    /*!
     * \if the list is empty add to the top of the list
     * \else add purchase to the end of the list
     */
    if(GetFirstPurchase() == NULL)
    {
        SetFirstPurchase(a);
    }
    else
    {
        GetLastPurchase()->setNextMember(a);
    }
    SetLastPurchase(a);

    SpendMoney(a);
    AddRebate(a);
}

//! The GetName function
/*!
 * \brief GetName returns the name of the member
 * \returns a QString
 */
QString member::GetName()
{
    return name;
}

//! The GetNumber function
/*!
 * \brief GetNumber returns the number of the member
 * \returns a QString
 */
QString member::GetNumber()
{
    return number;
}

//! The GetType function
/*!
 * \brief GetType returns the membership type of the member
 * \returns a bool
 */
bool member::GetType()
{
    return memType;
}

//! The GetExpiration function
/*!
 * \brief GetExpiration returns the expiration date of the member
 * \returns a QString
 */
QString member::GetExpiration()
{
    return expiration;
}

//! The GetSpent function
/*!
 * \brief GetSpent returns the total ammount of money spent by the member
 * \returns a float
 */
float member::GetSpent()
{
    return totalSpent;
}

//! The GetTaxSpent function
/*!
 * \brief GetTaxSpent returns the total tax of the member
 * \returns a float
 */
float member::GetTaxSpent()
{
    return totalTax;
}

//! The GetNextMember function
/*!
 * \brief GetNextMember returns the next member of the list
 * \returns a member pointer
 */
member *member::GetNextMember()
{
    return nextMember;
}

//! The GetFirstPurchase function
/*!
 * \brief GetFirstPurchase returns the first purchase of the member
 * \returns a Purchase pointer
 */
Purchase *member::GetFirstPurchase()
{
        return firstPurchase;
}

//! The GetLastPurchase function
/*!
 * \brief GetLastPurchase returns the last purchase of the member
 * \returns a Purchase pointer
 */
Purchase *member::GetLastPurchase()
{
        return lastPurchase;
}

//! The GetThisMember function
/*!
 * \brief GetThisMember returns a pointer that points to a member in the member list
 * \details GetThisMember will search for a specific member and will return a pointer pointing to that member if found
 *          and if not found then it will return a NULL pointer
 * \param findNum the member number the function is looking for
 * \returns a member pointer
 */
member *member::GetThisMember(QString findNum)
{
    member *memptr;

    /*!
     * \if member number is the member being looked for point to that member
     * \else go to next member
     */
    if(number == findNum)
    {
        memptr = this;
    }
    else
    {
        /*!
         * \if there is another member in the list go to next member
         * \else if member was not found set pointer to NULL
         */
        if(nextMember != NULL)
        {
            memptr = nextMember->GetThisMember(findNum);
        }
        else
        {
            memptr = NULL;
        }
    }

    return memptr;
}

//! The GetListLength function
/*!
 * \brief GetListLength returns the length of the member list
 * \details GetListLength will cycle through the list of members until it gets the total number of members
 * \returns a qint32
 */
qint32 member::GetListLength() //might not work?
{
    qint32 length;
    member *theNextMember = GetNextMember();

    /*!
     * \if there is another member on the list go to next member and add to length
     * \else set length to 1
     */
    if(theNextMember != NULL)
    {
        length = theNextMember->GetListLength();
        length ++;
    }
    else
    {
        length = 1;
    }

    return length;
}

//! The GetRebate function
/*!
 * \brief GetRebate returns the rebate of the member
 * \returns a float
 */
float ExecClass::GetRebate()
{
    return rebate;
}

//! The SetReabte function
/*!
 * \brief SetRebate sets the rebate of the member
 * \param newRebate the new rebate of the member
 */
void ExecClass::SetRebate(float newRebate)
{
    rebate = newRebate;
}

//! The AddRebate function
/*!
 * \brief AddRebate calculates the rebate of the member
 * \details AddRebate will calculate the total rebate for the executive member
 * \param purch a pointer that points to a purchase object
 */
void ExecClass::AddRebate(Purchase *purch)
{
    float receit;

    receit = purch->getObjPrice() * purch->getObjQuantity();

    rebate += receit * REBATE_RATE;
}

//! The isWrongType function
/*!
 * \brief isWrongType returns the membership type of the member
 * \returns a bool
 */
bool member::isWrongType()
{
    float mem, ex;
    bool isWrong;

    mem = 85 + GetSpent();
    ex = 95 + GetSpent() - (REBATE_RATE * GetSpent());

    /*!
     * \if regular member spending total is less than executive
     *  maintain membership
     * \else change membership to executive
     */
    if(mem <= ex)
    {
        isWrong = false;
    }
    else
    {
        isWrong = true;
    }

    return isWrong;
}

//! The isWrongType function
/*!
 * \brief isWrongType changes the membership type of the member
 * \returns a bool
 */
bool ExecClass::isWrongType()
{
    float mem, ex;
    bool isWrong;

    mem = 85 + GetSpent();
    ex = 95 + GetSpent() - rebate;

    /*!
     * \if regular member spending total is less than executive change membership
     * \else change membership to regular
     */
    if(mem < ex)
    {
        isWrong = true;
    }
    else
    {
        isWrong = false;
    }

    return isWrong;
}

//! The ChangeMembership function
/*!
 * \brief ChangeMembership changes the membership type of the member
 */
void member::ChangeMembership()
{
    /*!
     * \if membership is executive change to normal
     * \else change membership to executive
     */
    if(GetType() == EXEC)
    {
        SetType(NORMAL);
    }
    else
    {
        SetType(EXEC);
    }
}

//! The SpendMoney function
/*!
 * \brief SpendMoney calculates the total ammount of money spent
 * \param purch pointer that points to a purchase
 */
void member::SpendMoney(Purchase *purch)
{
    float receit;
    receit = purch->getObjPrice() * purch->getObjQuantity();
    totalSpent += receit;
    receit += receit * TAX_RATE;
    PayTax(receit); //total tax money spent after tax
}

//! The PayTax function
/*!
 * \brief PayTax calculates the total tax of the member
 * \param receit the tax being added to the total tax
 */
void member::PayTax(float receit)
{
    totalTax += receit;
}

//! The member destructor
/*!
 * \brief ~member is the virtual destructor of the member class
 */
member::~member()
{

}

//! The ExecClass destructor
/*!
 * \brief ~ExecClass is the virtual destructor for the ExecClass class
 */
ExecClass::~ExecClass()
{

}

//! The overloaded member addition operator
/*!
 * \brief the overloaded addition operator will add a member to the member list
 * \param newMember the member being added to member list
 */
member *member::operator +(member *newMember)
{
    return AddToMemberList(newMember);
}

//! The overloaded purchase addition operator
/*!
 * \brief the overloaded addition operator will add a purchase to the list
 * \param newPurchase the purchase being added to the list
 */
void member::operator +(Purchase *newPurchase)
{
    AddPurchase(newPurchase);
}

