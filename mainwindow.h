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
 * \brief This class is the mother of all. It is the main window which contains
 *        all slots and widgets running the program.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! The constructor
    /*!
     * \brief It will create the main window, plus create the list of members and days
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    //! The Destructor
    /*!
     * \brief This will save all data, eliminate all members and days and the ui
     */
    ~MainWindow();

    member *memberList;          /*!< A Member pointer to the list. */
    SalesDay *dayList;           /*!< A SalesDay pointer to the list. */

private slots:
    //! Login button
    /*!
     * \brief It will let you log in into the program
     */
    void on_loginButton_clicked();

    //! The close button
    /*!
     * \brief The close button, to exit program
     */
    void on_closeButton_clicked();

    //! The add member button
    /*!
     * \brief This button will add members to the list
     */
    void on_addButton_clicked();

    //! The remove button
    /*!
     * \brief This button will remove a member from the list
     */
    void on_removeButton_clicked();

    //! The view button
    /*!
     * \brief This button will let you view all members
     */
    void on_viewButton_clicked();

    //! The go back button
    /*!
     * \brief This button will let you go back to main menu
     */
    void on_pushButton_goBack_clicked();

    //! The take me to add members button
    /*!
     * \brief This button will take you to the member page
     */
    void on_pushButton_addMembers_clicked();

    //! The return to menu button
    /*!
     * \brief This buttom takes you to main menu from member page
     */
    void on_pushButton_returnToMenu_clicked();

    //! The go back to menu button 2
    /*!
     * \brief This buttom takes you to main menu from sales report
     */
    void on_pushButton_goBacktoMenu_clicked();

    //! The sales report button
    /*!
     * \brief This buttom takes you to sales report page
     */
    void on_pushButton_2_salesReport_clicked();

    //! The generate list button
    /*!
     * \brief This buttom will generate the list of members
     */
    void on_pushButton_generateList_clicked();

    //! The generate sales button
    /*!
     * \brief This buttom will generate the sales report list
     */
    void on_pushButton_generateSales_clicked();

    //! The switch account button
    /*!
     * \brief This buttom will switch the account type
     */
    void on_pushButton_switchAccount_clicked();

    //! The exit program button
    /*!
     * \brief This buttom will quit the program
     */
    void on_pushButton_exitProgram_clicked();

    //! The add purchases page button
    /*!
     * \brief This buttom will take you to the add purchases page
     */
    void on_pushButton_addPurchasesPage_clicked();

    //! The back to menu 3 button
    /*!
     * \brief This buttom takes you back to main menu from purchases page
     */
    void on_pushButton_backToMenu_clicked();

    //! The add purchase button
    /*!
     * \brief This buttom will add purchases to the list
     */
    void on_pushButton_addPurchase_clicked();

    //! The remove purchase button
    /*!
     * \brief This buttom removes purchases from the list
     */
    void on_pushButton_removePurchase_clicked();

    //! The view all purchases button
    /*!
     * \brief This buttom lets you view all purchases made
     */
    void on_pushButton_viewAllPurchases_clicked();

    //! The back to menu button
    /*!
     * \brief This buttom takes you back to menu
     */
    void on_pushButton_backMenu_clicked();

    //! The generate item list button
    /*!
     * \brief This buttom will generate the item list
     */
    void on_pushButton_generateItemList_clicked();

    //! The back to main button
    /*!
     * \brief This buttom takes you back to main menu
     */
    void on_pushButton_backToMain_clicked();

    //! The renew membership button
    /*!
     * \brief This buttom will take you to date expiration page
     */
    void on_pushButton_renewMembership_clicked();

    //! The generate expiration date button
    /*!
     * \brief This buttom will generate the expiration dates from members
     */
    void on_pushButton_generateExpDate_clicked();

    //! The inspect member button
    /*!
     * \brief This buttom will inspect selected member and display info
     */
    void on_pushButton_inspectMember_clicked();

    //! The renew to normal button
    /*!
     * \brief This buttom will let you switch an member account to normal
     */
    void on_pushButton_renewNormal_clicked();

    //! The renew to executive button
    /*!
     * \brief This buttom will let you switch an member account to executive
     */
    void on_pushButton_renewExec_clicked();

private:
    Ui::MainWindow *ui;     /*!< A MainWindow pointer to UI */

    //These don't work but they might
    //QString memFile = ":/myresources/MyFiles/members.txt";
    //QString purchFile = ":/myresources/MyFiles/purchases.txt";

//    QString memFile = "C:/Users/mnelson39/Desktop/Proj1/members.txt";
//    QString purchFile = "C:/Users/mnelson39/Desktop/Proj1/purchases.txt";

    QString memFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/members.txt";
    QString purchFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/purchases.txt";
};

#endif // MAINWINDOW_H
