#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "purchase.h"
#include "sales.h"
#include "member.h"
#include "fileparsing.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    member *memberList;
    SalesDay *dayList;

private slots:
    void on_loginButton_clicked();                   //login buttom
    void on_closeButton_clicked();                   //closes program
    void on_addButton_clicked();                     //add member
    void on_removeButton_clicked();                  //remove member
    void on_viewButton_clicked();                    //view members
    void on_pushButton_goBack_clicked();             //takes you back to main menu
    void on_pushButton_addMembers_clicked();         //takes you member page
    void on_pushButton_returnToMenu_clicked();       //return to main menu from member page
    void on_pushButton_goBacktoMenu_clicked();       //return to main menu from sales report
    void on_pushButton_2_salesReport_clicked();      //takes you to sales report page
    void on_pushButton_generateList_clicked();       //this will generate the list of members
    void on_pushButton_generateSales_clicked();      //this will generate the sales report list
    void on_pushButton_switchAccount_clicked();      //this should switch the account type
    void on_pushButton_exitProgram_clicked();        //this should quit the program
    void on_pushButton_addPurchasesPage_clicked();   //this will take you to the add purchases page
    void on_pushButton_backToMenu_clicked();         //takes you back to main menu from purchases page
    void on_pushButton_addPurchase_clicked();        //adds purchase
    void on_pushButton_removePurchase_clicked();     //remove purchase


private:
    Ui::MainWindow *ui;
//    QString memFile = "C:/Users/mnelson39/Desktop/Proj1/members.txt";
//    QString purchFile = "C:/Users/mnelson39/Desktop/Proj1/purchases.txt";

    QString memFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/members.txt";
    QString purchFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/purchases.txt";
};

#endif // MAINWINDOW_H
