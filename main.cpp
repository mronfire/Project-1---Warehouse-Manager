/*
 * Yo dis is main. I feel like I'm dying, but hey let's code!
 */

#include "header.h"
#include "test.h"

int main()
{
	string line; //used to process input
	char day;
	member *memberList = new member;
	member *memptr = memberList;
	salesDay *dayList = new salesDay;
	salesDay *dayptr = dayList;
	purchase *purchptr = NULL;
	dayList->day = 1; //first day is day 1
	ifstream memFile ("members.txt");
	ifstream purchFile ("purchases.txt");
	if (memFile.is_open())
	{
		while(getline(memFile,line))
		{
			memptr->name = line;
			getline(memFile,line);
			memptr->num = line;
			getline(memFile,line);
			if(line == "Executive")
			{
				memptr->exec = true;
			}
			else
			{
				memptr->exec = false;
			}
			getline(memFile,line);
			memptr->date = line;
			memptr->ptr = new member;
			memptr = memptr->ptr;
		}
	}
	memFile.close();
	cout << "done loading members!\n";


	while(dayptr->day < NUMDAYS)
	{
		dayptr->ptr = new salesDay;
		dayptr->ptr->day = dayptr->day +1;
		dayptr = dayptr->ptr;
	}

	if(purchFile.is_open())
	{
		while(getline(purchFile, line))
		{
			//generate new purchase
			purchptr = new purchase;
			purchptr->date = line;
			//day = purchptr->date.at(4);
			getline(purchFile, line);
			purchptr->memNum = line;
			getline(purchFile, line);
			purchptr->item = line;
			purchFile>>purchptr->price;
			purchFile>>purchptr->quant;
			purchFile.ignore(1,'\n');

			//find and assign day
			dayptr = dayList;
			while(false && day != char(dayptr->day))
			{
				cout << dayptr->day << " and " << day << endl;
				dayptr = dayptr->ptr;
				while(dayptr == NULL)
				{
					cout << "oob";
					cin.ignore(9001,'\n');
				} //waits so the program no asplode
			}
			if(dayptr != NULL) //if we have the right day
			{
				if(dayptr->purchList == NULL) //if nothing in list
				{
					dayptr->purchList = purchptr;
					//set as first item in list
				}
				else //if there's stuff in the list
				{
					dayptr->lastPurch->dayptr = purchptr;
					//set it after the last item in the list
				}
				dayptr->lastPurch = purchptr;
				//set new last item in list
			}
			else //if this runs, I am finding an out of bounds day
			{
				cout << "PLEASE ONLY USE DAYS BETWEEN 1 AND " << NUMDAYS;
			}
		}
	}


	purchFile.close();
	cout << "done loading purchases!\n";

	cout << "This is where the menu and stuff goes!\n";

	//delete all dynamically allocated memory
	while(memberList != NULL)
	{
		cout << memberList->name << endl;
		cout << memberList->num << endl;
		memptr = memberList->ptr;
		delete memberList;
		memberList = memptr;
	}

	while(dayList != NULL) //day is on charge of deallocating purchases
	{
		cout << "Day number: " << dayList->day << endl;
		while(dayptr->purchList != NULL)
		{
			cout << " -" << dayptr->purchList->item << endl;
			purchptr = dayptr->purchList->dayptr; //point to next purchase in day
			delete dayptr->purchList;
			dayptr->purchList = purchptr;
		}
		dayptr = dayList->ptr;
		delete dayList;
		dayList = dayptr;
	}

	cout << "You have reached the end of the demo!";

	return 0;
}


