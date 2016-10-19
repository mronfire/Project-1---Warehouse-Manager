/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
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

//!  The MainWindow class.
/*!
 * This class is the mother of all. It is the main window which contains
 * all slots and widgets running the program.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    member *memberList;                              /*!< A Member pointer to the list. */
    SalesDay *dayList;                               /*!< A SalesDay pointer to the list. */

private slots:
    void on_loginButton_clicked();                   /*!< The login buttom */
    void on_closeButton_clicked();                   /*!< The close buttom, to exit program */
    void on_addButton_clicked();                     /*!< The add member buttom */
    void on_removeButton_clicked();                  /*!< The remove member buttom */
    void on_viewButton_clicked();                    /*!< The view members buttom */
    void on_pushButton_goBack_clicked();             /*!< This buttom takes you back to main menu */
    void on_pushButton_addMembers_clicked();         /*!< This buttom takes you member page */
    void on_pushButton_returnToMenu_clicked();       /*!< This buttom takes you to main menu from member page */
    void on_pushButton_goBacktoMenu_clicked();       /*!< This buttom takes you to main menu from sales report */
    void on_pushButton_2_salesReport_clicked();      /*!< This buttom takes you to sales report page */
    void on_pushButton_generateList_clicked();       /*!< This buttom will generate the list of members */
    void on_pushButton_generateSales_clicked();      /*!< This buttom will generate the sales report list */
    void on_pushButton_switchAccount_clicked();      /*!< This buttom should switch the account type */
    void on_pushButton_exitProgram_clicked();        /*!< This buttom should quit the program */
    void on_pushButton_addPurchasesPage_clicked();   /*!< This buttom will take you to the add purchases page */
    void on_pushButton_backToMenu_clicked();         /*!< This buttom takes you back to main menu from purchases page */
    void on_pushButton_addPurchase_clicked();        /*!< This buttom adds purchase */
    void on_pushButton_removePurchase_clicked();     /*!< This buttom removes purchase */


private:
    Ui::MainWindow *ui;                              /*!< A MainWindow pointer to UI */

    //These don't work but they might
    //QString memFile = ":/myresources/MyFiles/members.txt";
    //QString purchFile = ":/myresources/MyFiles/purchases.txt";

    QString memFile = "C:/Users/mnelson39/Desktop/Proj1/members.txt";
    QString purchFile = "C:/Users/mnelson39/Desktop/Proj1/purchases.txt";

    //QString memFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/members.txt";
    //QString purchFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/purchases.txt";
};

#endif // MAINWINDOW_H
