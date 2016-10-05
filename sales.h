#ifndef SALES_H
#define SALES_H

#include "header.h"
#include "purchase.h"

class SalesDay
{
private:
    float revenue;
    int numExec;
    int numMem;
    string date;
    SalesDay *tomorrow;
    Purchase *firstPurchase;
    Purchase *lastPurchase;
public:
    SalesDay();
    SalesDay(float initRevenue, int initExec, int initMem, std::string initDate, SalesDay *initTomorrow, Purchase *initFirst, Purchase *initLast);
    SalesDay(SalesDay *a);
    SalesDay *GetNextDay();
    Purchase *GetFirstPurchase();
    string GetDate();
    void SetDate(string today);
    void IncreaseRevenue(int addRevenue);
    void MemberCount(bool member);
    void AddPurchase(Purchase *a);
    void SetFirstPurchase(Purchase *newFirst);
    void SetNextDay(SalesDay *a);
    void Print();
    ~SalesDay();
};

#endif // SALES_H