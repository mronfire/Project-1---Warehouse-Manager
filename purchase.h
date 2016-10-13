#ifndef PURCHASECLASS_H
#define PURCHASECLASS_H

#include "header.h"

class Purchase
{
public:
    /**********************************
     * Constructors & Destructor
     **********************************/
    Purchase();
    Purchase(QString num, QString type, float cost, int amount,
                  QString date);

    //MUTATRORS
    void setMemberNum(QString num);
    void setObjType(QString type);
    void setObjPrice(float cost);
    void setObjQuantity(int amount);
    void setPurchaseDate(QString date);
    void setNextMember(Purchase *otherMember);
    void setNextDay(Purchase *otherDay);

    //ACCESSORS
    QString getPurchaseDate() const;
    QString getMemberNum() const;
    QString getObjType() const;
    float getObjPrice() const;
    int getObjQuantity() const;
    Purchase *getNextMember() const;
    Purchase *getNextDay() const;

private:

    QString memberNum;
    QString objectType;
    float  price;
    int    quantity;
    QString purchaseDate;
    Purchase *nextMember;
    Purchase *nextDay;

};

#endif // PURCHASECLASS_H
