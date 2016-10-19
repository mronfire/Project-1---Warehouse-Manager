/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
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
//QString outputMembers(member *memberList);


#endif // FILEPARSING_H
