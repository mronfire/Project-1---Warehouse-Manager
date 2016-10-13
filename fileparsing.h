#ifndef FILEPARSING_H
#define FILEPARSING_H

#include "header.h"
#include "purchase.h"
#include "sales.h"
#include "member.h"

member *CreateMemberList(QString inFile);
SalesDay *CreateDayList(int numDays, QString day1);
void ReadPurchases(QString inFile, member *memberList, SalesDay *dayList);
void DeleteMembers(member *memberList);
void DeleteDays(SalesDay *dayList);
void SaveData(QString memFileName, QString purchFileName, member *memberList, SalesDay *dayList);


#endif // FILEPARSING_H
