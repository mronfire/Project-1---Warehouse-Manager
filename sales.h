/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#ifndef SALES_H
#define SALES_H

#include "header.h"
#include "purchase.h"
#include "member.h"

class SalesDay
{
private:
    float revenue;
    int numExec;
    int numMem;
    QString date;
    SalesDay *tomorrow;
    Purchase *firstPurchase;
    Purchase *lastPurchase;
public:
    SalesDay();
    SalesDay(float initRevenue, int initExec, int initMem, QString initDate, SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast);
    SalesDay(SalesDay *a);
    SalesDay *GetNextDay();
    Purchase *GetFirstPurchase();
    Purchase *GetLastPurchase();
    QString GetDate();
    int GetMem();
    int GetExec();
    float GetRevenue();
    void SetDate(QString today);
    void IncreaseRevenue(int addRevenue);
    void MemberCount(bool member);
    void AddPurchase(Purchase *a, member *memList);
    void SetFirstPurchase(Purchase *newFirst);
    void SetLastPurchase(Purchase *newLast);
    void SetNextDay(SalesDay *a);
    void Print();
    ~SalesDay();
};

#endif // SALES_H
