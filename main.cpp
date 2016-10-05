#include "mainwindow.h"
#include <QApplication>
#include "purchase.h"
#include "sales.h"
#include "member.h"
#include "fileparsing.h"

int main(int argc, char *argv[])
{
    member *memberList;
    SalesDay *dayList;
    string memFile = "C:/Users/mnelson39/Desktop/Proj1/members.txt";
    string purchFile = "C:/Users/mnelson39/Desktop/Proj1/purchases.txt";

    //need to input location of folders on your system for some reason
    memberList = CreateMemberList(memFile);
    dayList = CreateDayList(NUMDAYS, "08/01/2015");
    ReadPurchases(purchFile ,memberList, dayList);
    cout << DeleteMembers(memberList); //always delete members before days!
    cout << DeleteDays(dayList);
    cout << "\n\nYou have reached the end of the demo!\n";

    QApplication a(argc, argv); //main menu goes here
    MainWindow w;
    w.show();

    return a.exec();
}
