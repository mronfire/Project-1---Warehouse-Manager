#include "fileparsing.h"

member *CreateMemberList(string inFile)
{
    member *memberList;
    member *memptr;
    string line;

    ifstream memFile;
    memFile.open(inFile);

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
    cout << "Done loading members!\n";

    return memberList;
}

SalesDay *CreateDayList(int numDays, string day1)
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

void ReadPurchases(string inFile, member *memberList, SalesDay *dayList)
{
    string line;
    string day;
    string customer;
    int    amount;
    float  cost;

    Purchase *purchptr = NULL;
    SalesDay *dayptr;
    member   *memptr;

    ifstream purchFile;
    purchFile.open(inFile);

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
            while(day != dayptr->GetDate() && dayptr->GetDate() != "Other" && dayptr != NULL)
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
    cout << "Done loading purchases!\n";
}

string DeleteMembers(member *memberList)
{
    //ALWAYS DELETE MEMBERS BEFORE DAYS
    member   *memptr;
    Purchase *purchptr;

    ostringstream output;

    memptr = memberList;
    output << "\nMember list:\n";
    //delete all dynamically allocated memory
    while(memberList != NULL)
    {
        output << "Member name: " << memberList->GetName() << endl;
        output << "Member num : " << memberList->GetNumber() << endl;

        while(memptr->GetFirstPurchase() != NULL)
        {
            output << " -" << memptr->GetFirstPurchase()->getObjType() << endl;
            purchptr = memptr->GetFirstPurchase()->getNextDay(); //point to next purchase in day
            memptr->SetFirstPurchase(purchptr);
        }

        memptr = memberList->GetNextMember();
        delete memberList;
        memberList = memptr;
    }

    return output.str();
}

string DeleteDays(SalesDay *dayList)
{
    //ALWAYS DELETE MEMBERS BEFORE DAYS
    SalesDay *dayptr;
    Purchase *purchptr;

    ostringstream output;

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

    return output.str();
}

//void SaveData(string memFile, string purchFile, member *memberList, SalesDay dayList);
