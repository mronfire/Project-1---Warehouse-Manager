#include "purchase.h"

Purchase::Purchase()
{
    memberNum.clear();
    objectType.clear();
    price         = 0.00;
    quantity      = 0;
    purchaseDate.clear();
    nextMember    = NULL;
    nextDay       = NULL;
}

Purchase::Purchase(QString num, QString type, float cost, int amount,
                             QString date)
{
    memberNum    = num;
    objectType   = type;
    price        = cost;
    quantity     = amount;
    purchaseDate = date;
    nextMember   = NULL;
    nextDay      = NULL;
}

void Purchase::setMemberNum(QString num)
{
    memberNum = num;
}

void Purchase::setObjType(QString type)
{
    objectType = type;
}

void Purchase::setObjPrice(float cost)
{
    price = cost;
}

void Purchase::setObjQuantity(int amount)
{
    quantity = amount;
}

void Purchase::setPurchaseDate(QString date)
{
    purchaseDate = date;
}

void Purchase::setNextMember(Purchase *otherMember)
{
    nextMember = otherMember;
}

void Purchase::setNextDay(Purchase *otherDay)
{
    nextDay = otherDay;
}

QString Purchase::getMemberNum() const
{
    return memberNum;
}

QString Purchase::getObjType() const
{
    return objectType;
}

float Purchase::getObjPrice() const
{
    return price;
}

int Purchase::getObjQuantity() const
{
    return quantity;
}

QString Purchase::getPurchaseDate() const
{
    return purchaseDate;
}

Purchase *Purchase::getNextMember() const
{
    return nextMember;
}

Purchase *Purchase::getNextDay() const
{
    return nextDay;
}
