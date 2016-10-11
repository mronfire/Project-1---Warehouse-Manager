#ifndef FILEPARSING_H
#define FILEPARSING_H

#include "header.h"
#include "purchase.h"
#include "sales.h"
#include "member.h"

member *CreateMemberList(string inFile);
SalesDay *CreateDayList(int numDays, string day1);
void ReadPurchases(string inFile, member *memberList, SalesDay *dayList);
string DeleteMembers(member *memberList);
string DeleteDays(SalesDay *dayList);
void SaveData(string memFileName, string purchFileName, member *memberList, SalesDay *dayList);


#endif // FILEPARSING_H
