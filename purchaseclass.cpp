#include "purchaseclass.h"

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

Purchase::Purchase(string num, string type, float cost, int amount,
                             string date)
{
    memberNum    = num;
    objectType   = type;
    price        = cost;
    quantity     = amount;
    purchaseDate = date;
    nextMember   = NULL;
    nextDay      = NULL;
}

void Purchase::setMemberNum(string num)
{
    memberNum = num;
}

void Purchase::setObjType(string type)
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

void Purchase::setPurchaseDate(string date)
{
    purchaseDate = date;
}

string Purchase::getMemberNum() const
{
    return memberNum;
}

string Purchase::getObjType() const
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

string Purchase::getPurchaseDate() const
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
