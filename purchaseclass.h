#ifndef PURCHASECLASS_H
#define PURCHASECLASS_H

using namespace std;

class Purchase
{
public:
    /**********************************
     * Constructors & Destructor
     **********************************/
    Purchase();
    Purchase(string num, string type, float cost, int amount,
                  string date);

    //MUTATRORS
    void setMemberNum(string num);
    void setObjType(string type);
    void setObjPrice(float cost);
    void setObjQuantity(int amount);
    void setPurchaseDate(string date);
    void setNextMember(Purchase *otherMember);
    void setNextDay(Purchase *otherDay);

    //ACCESSORS
    string getMemberNum() const;
    string getObjType() const;
    float getObjPrice() const;
    int getObjQuantity() const;
    string getPurchaseDate() const;
    Purchase *getNextMember() const;
    Purchase *getNextDay() const;

private:

    string memberNum;
    string objectType;
    float  price;
    int    quantity;
    string purchaseDate;
    Purchase *nextMember;
    Purchase *nextDay;

};

#endif // PURCHASECLASS_H
