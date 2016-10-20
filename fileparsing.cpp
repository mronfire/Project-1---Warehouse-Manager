/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "fileparsing.h"

//! Create member list function
/*!
 * \brief This function will create the linked list of members
 * \param inFile
 * \return the top of member list
 */
member *CreateMemberList(QString inFile)
{
    member *memberList;
    QString name;
    QString memNum;
    QString isExec;
    bool   ExecBool;
    QString date;

    QFile memFile(inFile);
    memFile.open(QIODevice::ReadOnly | QIODevice::Text);

    if(true) //create member list //this line was .isopen
    {
        name = memFile.readLine();
        name = name.left(name.length() - 1);
        memNum = memFile.readLine();
        memNum = memNum.left(memNum.length() - 1);
        isExec = memFile.readLine();
        isExec = isExec.left(isExec.length() - 1);
        date = memFile.readLine();
        date = date.left(date.length() - 1);
        if(isExec == "Executive")
        {
            ExecBool = true;
        }
        else
        {
            ExecBool = false;
        }

        if(ExecBool)
        {
            memberList = new ExecClass(name, memNum, ExecBool, date);
        }
        else
        {
            memberList = new member(name, memNum, ExecBool, date);
        }

        while(!memFile.atEnd())//code is different: memlist should be 1st mem
        {
            name = memFile.readLine();
            name = name.left(name.length() - 1);
            memNum = memFile.readLine();
            memNum = memNum.left(memNum.length() - 1);
            isExec = memFile.readLine();
            isExec = isExec.left(isExec.length() - 1);
            date = memFile.readLine();
            date = date.left(date.length() - 1);
            if(isExec == "Executive")
            {
                ExecBool = true;
            }
            else
            {
                ExecBool = false;
            }

            if(name != NULL && memNum.size() == 5 &&
               date[2] == '/' && date[5] == '/' && date.size() == 10) //error checking!
            {
                if(ExecBool)
                {
                    memberList->AddToMemberList(new ExecClass(name, memNum, ExecBool, date));
                }
                else
                {
                    memberList->AddToMemberList(new member(name, memNum, ExecBool, date));
                }
            }
        }
    }
    memFile.close();
    cout << "Done loading members!\n";

    return memberList;
}

//! Create day list function
/*!
 * \brief This function will create the linked list for the days
 * \param numDays
 * \param day1
 * \return the top of days list
 */
SalesDay *CreateDayList(int numDays, QString day1)
{
    int index;

    SalesDay *dayList = new SalesDay;
    SalesDay *dayptr = dayList;
    dayList->SetDate(day1); //date of day 1

    for(index = 1; index < numDays; index++) //day 1 is created already
    {
        dayptr->SetNextDay(new SalesDay(dayptr)); //tommorow constructor
        dayptr = dayptr->GetNextDay();
    }
    dayptr->SetNextDay(new SalesDay()); //creates the day "Other" to end list
    dayptr = dayptr->GetNextDay();
    dayptr -> SetDate("Other");
    cout << "Done Generating days!\n";

    return dayList;
}

//! Read all purchases
/*!
 * \brief This function will read all purchases from each day and assign it to
 *        respective member and the day it was bought
 * \param inFile
 * \param memberList
 * \param dayList
 */
void ReadPurchases(QString inFile, member *memberList, SalesDay *dayList)
{
    QString day;
    QString customer;
    QString obj;
    QString line;
    int    amount;
    float  cost;

    Purchase *purchptr = NULL;
    SalesDay *dayptr;
    member   *memptr;

    QFile purchFile(inFile);
    purchFile.open(QIODevice::ReadOnly | QIODevice::Text);

    if(true) //qfile has no .isOpen
    {
        while(!purchFile.atEnd())
        {
            //generate new purchase
            purchptr = new Purchase;
            day = purchFile.readLine();
            day = day.left(day.length() - 1); //gets rid of white space
            customer = purchFile.readLine();
            customer = customer.left(customer.length() - 1); //same
            obj =  purchFile.readLine();
            obj = obj.left(obj.length() - 1); //same
            line = purchFile.readLine(); //reads into line, chops off white space, then typecasts properly
            line = line.left(line.length() - 1);
            cost = line.toFloat();
            line = purchFile.readLine();
            line = line.left(line.length() - 1);
            amount = line.toInt();

            purchptr->setPurchaseDate(day);
            purchptr->setMemberNum(customer);
            purchptr->setObjType(obj);
            purchptr->setObjPrice(cost);
            purchptr->setObjQuantity(amount);

            //find and assign day
            dayptr = dayList;
            while(day != dayptr->GetDate() && dayptr->GetDate() != "Other" && dayptr != NULL)
            {              //ptr->method.function is correct here
                dayptr = dayptr->GetNextDay();
                while(dayptr == NULL) //this should never run
                {
                    cout << "day oob";
                    cin.ignore(9001,'\n');
                } //waits so the program no asplode
            }

            if(dayptr != NULL) //if we have the right day
            {
                dayptr->AddPurchase(purchptr, memberList);
            }
            else //if this runs, I am finding an out of bounds day
            {
                cout << "PLEASE ONLY USE DAYS BETWEEN 1 AND " << NUMDAYS;
            }

            //find and assign member
            memptr = memberList;
            while(customer != memptr->GetNumber() && memptr != NULL)
            { 
                while(memptr == NULL) //this should never run
                {
                    cout << "member oob";
                    cin.ignore(9001,'\n');
                } //waits so the program no asplode
                memptr = memptr->GetNextMember();
            }

            if(memptr != NULL) //if we have the right member
            {
                memptr->AddPurchase(purchptr);
            }
            else //if this runs, we're not pointing to a member
            {
                cout << customer.toStdString() << " IS NOT A CLAIMED MEMBER NUMBER\n";
            }
        }
    }

    purchFile.close();
    cout << "Done loading purchases!\n";
}

//! Delete all members
/*!
 * \brief This function will delete all members of the list
 * \param memberList
 */
void DeleteMembers(member *memberList)
{
    //ALWAYS DELETE MEMBERS BEFORE DAYS
    member   *memptr;
    Purchase *purchptr;

    memptr = memberList;
    cout << "\nMember list:\n";

    //delete all dynamically allocated memory
    while(memberList != NULL)
    {
        cout << "Member name : " << memberList->GetName().toStdString() << endl;
        cout << "Member num  : " << memberList->GetNumber().toStdString() << endl;
        cout << fixed << setprecision(2);
        cout << "Member spent: $" << memberList->GetSpent() << endl;

        while(memptr->GetFirstPurchase() != NULL)
        {
            cout << " -" << memptr->GetFirstPurchase()->getObjType().toStdString() << endl;
            purchptr = memptr->GetFirstPurchase()->getNextMember(); //point to next purchase under that member
            memptr->SetFirstPurchase(purchptr);
        }

        memptr = memberList->GetNextMember();
        delete memberList;
        memberList = memptr;
    }
}

//! Delete all days
/*!
 * \brief This function will delete all days of the list
 * \param dayList
 */
void DeleteDays(SalesDay *dayList)
{
    //ALWAYS DELETE MEMBERS BEFORE DAYS
    SalesDay *dayptr;
    Purchase *purchptr;

    dayptr = dayList;
    cout << "\nDayList:\n";

    while(dayList != NULL) //day is on charge of deallocating purchases
    {
        cout << "Sales Date: " << dayList->GetDate().toStdString() << endl;
        cout << "Total Revenue: $" << dayList->GetRevenue() << endl;
        cout << "Total Regular Members: " << dayList->GetMem() << endl;
        cout << "Total Executive Members: " << dayList->GetExec() << endl;
        while(dayptr->GetFirstPurchase() != NULL)
        {
            cout << " -" << dayptr->GetFirstPurchase()->getObjType().toStdString() << endl;
            purchptr = dayptr->GetFirstPurchase()->getNextDay(); //point to next purchase in day
            delete dayptr->GetFirstPurchase();
            dayptr->SetFirstPurchase(purchptr);
        }
        dayptr = dayList->GetNextDay();
        delete dayList;
        dayList = dayptr;
    }
}

//! Save all data
/*!
 * \brief This function will save all data made to the files for later use
 * \param memFileName
 * \param purchFileName
 * \param memberList
 * \param dayList
 */
void SaveData(QString memFileName, QString purchFileName, member *memberList, SalesDay *dayList)
{
    member *memptr = memberList;
    SalesDay *dayptr = dayList;
    Purchase *purchptr;

    QFile memFile(memFileName);
    QFile purchFile(purchFileName);

    memFile.open(QIODevice::ReadWrite);
    purchFile.open(QIODevice::ReadWrite);

    QTextStream memStream(&memFile);
    QTextStream purchStream(&purchFile);

    while(memptr != NULL)
    {
        memStream << memptr->GetName() << endl
                << memptr->GetNumber() << endl;
        if(memptr->GetType()) //true is exec
        {
            memStream << "Executive\n";
        }
        else
        {
            memStream << "Regular\n";
        }
        memStream << memptr->GetExpiration() << endl;
        memptr = memptr->GetNextMember();
    }
    memFile.close();

    while(dayptr != NULL)
    {
        purchptr = dayptr->GetFirstPurchase();
        while(purchptr != NULL)
        {
            //purchStream << fixed << setprecision(2); //these might not work with QStream
            purchStream << purchptr->getPurchaseDate() << endl
                        << purchptr->getMemberNum() << endl
                        << purchptr->getObjType() << endl
                        << purchptr->getObjPrice() << endl
                        << purchptr->getObjQuantity() << endl;
            purchptr = purchptr->getNextDay(); //point to next purchase in day
        }
        dayptr = dayptr->GetNextDay();
    }

    purchFile.close();
}
