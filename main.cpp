#include "mainwindow.h"
#include <QApplication>
#include "purchase.h"
#include "sales.h"
#include "member.h"

int main(int argc, char *argv[])
{
    string line; //used to process input
    string day;
    string customer;
    int     index;
    int     amount;
    float   cost;
    member *memberList;
    member *memptr;
    SalesDay *dayList = new SalesDay;
    SalesDay *dayptr = dayList;
    Purchase *purchptr = NULL;
    dayList->SetDate("08/01/2015"); //date of day 1
    ifstream memFile;
    ifstream purchFile;

    //need to input location of folders on your system for some reason
    memFile.open("C:/Users/mnelson39/Desktop/FixingA3/members.txt");
    purchFile.open("C:/Users/mnelson39/Desktop/FixingA3/purchases.txt");

    //cin.ignore(9001,'\n');

    if (memFile.is_open()) //create member list
    {
        memberList = new member; //code is different: memlist should be 1st mem
        memptr = memberList;
        getline(memFile, line);
        memptr->SetName(line);
        getline(memFile,line);
        memptr->SetNumber(line);
        getline(memFile,line);
        if(line == "Executive")
        {
            memptr->SetType(true);
        }
        else
        {
            memptr->SetType(false);
        }
        getline(memFile,line);
        //memptr->SetDate(line);
        while(getline(memFile, line))
        {
            memptr->SetNextMember(new member);
            memptr = memptr->GetNextMember();
            memptr->SetName(line);
            getline(memFile,line);
            memptr->SetNumber(line);
            getline(memFile,line);
            if(line == "Executive")
            {
                memptr->SetType(true);
            }
            else
            {
                memptr->SetType(false);
            }
            getline(memFile,line);
            //memptr->SetDate(line);
        }

    }
    memFile.close();
    cout << "done loading members!\n";

    //cin.ignore(9001,'\n');


    for(index = 1; index < NUMDAYS; index++) //day 1 is created already
    {
        dayptr->SetNextDay(new SalesDay(dayptr)); //tommorow constructor
        dayptr = dayptr->GetNextDay();
    }
    dayptr->SetNextDay(new SalesDay()); //creates the day "Other" to end list
    dayptr = dayptr->GetNextDay();
    dayptr -> SetDate("Other");
    cout << "Done Generating days!\n";

    //cin.ignore(9001,'\n');

    if(purchFile.is_open())
    {
        while(getline(purchFile, line))
        {
            //generate new purchase
            purchptr = new Purchase;
            purchptr->setPurchaseDate(line);
            day = line;
            getline(purchFile, line);
            purchptr->setMemberNum(line);
            customer = line;
            getline(purchFile, line);
            purchptr->setObjType(line);
            purchFile>>cost;
            purchptr->setObjPrice(cost);
            purchFile>>amount;
            purchptr->setObjQuantity(amount);
            purchFile.ignore(1,'\n');

            //find and assign day
            dayptr = dayList;
            while(day != dayptr->GetDate() && dayptr->GetDate() != "Other")
            {
                dayptr = dayptr->GetNextDay();
                while(dayptr == NULL) //this should never run
                {
                    cout << "oob";
                    cin.ignore(9001,'\n');
                } //waits so the program no asplode
            }

            if(dayptr != NULL) //if we have the right day
            {
                dayptr->AddPurchase(purchptr);
            }
            else //if this runs, I am finding an out of bounds day
            {
                cout << "PLEASE ONLY USE DAYS BETWEEN 1 AND " << NUMDAYS;
            }

            //find and assign member
            memptr = memberList;
            while(customer != memptr->GetNumber() && memptr != NULL)
            {
                memptr = memptr->GetNextMember();
                while(memptr == NULL) //this should never run
                {
                    cout << "oob";
                    cin.ignore(9001,'\n');
                } //waits so the program no asplode
            }

            if(memptr != NULL) //if we have the right member
            {
                memptr->AddPurchase(purchptr);
            }
            else //if this runs, we're not pointing to a member
            {
                cout << customer << " IS NOT A CLAIMED MEMBER NUMBER\n";
            }
        }
    }


    purchFile.close();
    cout << "done loading purchases!\n";


    memptr = memberList;
    cout << "\nMember list:\n";
    //delete all dynamically allocated memory
    while(memberList != NULL)
    {
        cout << "Member name: " << memberList->GetName() << endl;
        cout << "Member num : " << memberList->GetNumber() << endl;

        while(memptr->GetFirstPurchase() != NULL)
        {
            cout << " -" << memptr->GetFirstPurchase()->getObjType() << endl;
            purchptr = memptr->GetFirstPurchase()->getNextDay(); //point to next purchase in day
            memptr->SetFirstPurchase(purchptr);
        }

        memptr = memberList->GetNextMember();
        delete memberList;
        memberList = memptr;
    }

    dayptr = dayList;
    cout << "\nDayList:\n";

    while(dayList != NULL) //day is on charge of deallocating purchases
    {
        cout << "Sales Date: " << dayList->GetDate() << endl;
        while(dayptr->GetFirstPurchase() != NULL)
        {
            cout << " -" << dayptr->GetFirstPurchase()->getObjType() << endl;
            purchptr = dayptr->GetFirstPurchase()->getNextDay(); //point to next purchase in day
            delete dayptr->GetFirstPurchase();
            dayptr->SetFirstPurchase(purchptr);
        }
        dayptr = dayList->GetNextDay();
        delete dayList;
        dayList = dayptr;
    }

    cout << "\n\nYou have reached the end of the demo!";

    QApplication a(argc, argv); //main menu goes here
    MainWindow w;
    w.show();
    cin.ignore(9001,'\n');

    return 0;

    return a.exec();
}
