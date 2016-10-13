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
    QString GetDate();
    int GetMem();
    int GetExec();
    float GetRevenue();
    void SetDate(QString today);
    void IncreaseRevenue(int addRevenue);
    void MemberCount(bool member);
    void AddPurchase(Purchase *a, member *memList);
    void SetFirstPurchase(Purchase *newFirst);
    void SetNextDay(SalesDay *a);
    void Print();
    ~SalesDay();
};

#endif // SALES_H
