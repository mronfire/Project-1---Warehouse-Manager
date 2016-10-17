#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

/*
 * This is the constructor for the mainWindows class. It will create the
 *  member list and the days list and also read the purchases for all days
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memberList = CreateMemberList(memFile);
    dayList = CreateDayList(NUMDAYS, "08/01/2015");
    ReadPurchases(purchFile ,memberList, dayList);
}

/*
 * This is the destructor for the mainWindows class. It will save all data
 *  before deleting members first and then days
 */
MainWindow::~MainWindow()
{
    //SaveData(memFile, purchFile, memberList, dayList); //Out of order
    DeleteMembers(memberList); //always delete members before days!
    DeleteDays(dayList);
    cout << "\nThank you for using my program!\n";
    delete ui;
}

/*
 * This login widget logins if the username and password are correct, which then
 *  will take you into the user stacked widget
 */
void MainWindow::on_loginButton_clicked()
{
    QString username, password;

    username = ui->Edituser->text();
    password = ui->Editpassword->text();

    if(username == "Admin" || username == "admin")
    {
        if(password == "admin" || password == "password")
        {
            //If username and password are correct, go to main menu
            ui->stackedWidget->setCurrentWidget(ui->menuPage);
        }
        else
        {
            QMessageBox::critical(this, "Login", "Password is not correct!");
        }
    }
    else
    {
        QMessageBox::critical(this, "Login", "Username is not correct!");
    }
}

/*
 * This buttom will close the program properly and save all data
 */
void MainWindow::on_closeButton_clicked()
{
    SaveData(memFile, purchFile, memberList, dayList);
    this->close();
}

/*
 * This buttom will add the members after they input all information needed.
 *  It should prompt user if a field is missing or if member name or id is
 *  already in the system
 */
void MainWindow::on_addButton_clicked()
{
    QString username, numID, date;
    member *myMember = NULL;

    myMember = new member;

    username  = ui->lineEdit_username->text();
    numID     = ui->lineEdit_numberID->text();
    ui->radioButton_execituveType->toggled(true);

    if(ui->radioButton_execituveType->isChecked())
    {
        QMessageBox::information(this, "Title", "The member is executive!!"); //just for testing
        myMember->SetType(true);
    }
    else
    {
        QMessageBox::information(this, "Title", "The member is NOT executive!!"); //just for testing
        myMember->SetType(false);
    }

    date      = ui->lineEdit_Date->text();

    if(username == NULL || numID == NULL || date == NULL)
    {
        QMessageBox::critical(this, "List of Members", "Please fill in all the fields required"
                              " in order to add a member!");
    }
    else
    {
        //assign the member corresponding data
        myMember->SetName(username);
        myMember->SetNumber(numID);
        myMember->Renew(date);

        myMember->AddToMemberList(myMember); //adds member to list

        QMessageBox::information(this, "List of Members", "The member has being added to "
                                 "the list!");
    }

    //clears the line edits for next input
    ui->lineEdit_username->clear();
    ui->lineEdit_numberID->clear();
    ui->lineEdit_Date->clear();
}

/*
 * This buttom will remove the member especified by the user and either open
 *  up another window showing the information about that user being eliminated,
 *  or just show in a QMessage box, that a member has being eliminated
 */
void MainWindow::on_removeButton_clicked()
{
    //work on this******
    QString numID;
    member *myMember = memberList;

    numID = ui->lineEdit_numberID->text();

    if(myMember->GetThisMember(numID) == NULL)
    {
        QMessageBox::information(this, "List of Members", "There is not one member"
                                 " with that information in the database!");
    }
    else
    {
        delete myMember;

        QMessageBox::information(this, "List of Members", "The member has being deleted "
                                 "from the list!");
    }

    //clears the line edits for next input
    ui->lineEdit_username->clear();
    ui->lineEdit_numberID->clear();
    ui->lineEdit_Date->clear();
}

/*
 * This buttom will take you to the view members page
 */
void MainWindow::on_viewButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->viewMembersPage);
}

/*
 * This buttom will take you back to the main member page from the view member page
 */
void MainWindow::on_pushButton_goBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->memberPage);

    ui->listWidget_members->clear(); //clears the list widget
}

/*
 * This buttom will take you back to the main menu from the member page
*/
void MainWindow::on_pushButton_returnToMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

/*
 * This buttom will take you to member page from the main menu
 */
void MainWindow::on_pushButton_addMembers_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->memberPage);
}

/*
 * This buttom will take you back to the main menu from the sales report page
*/
void MainWindow::on_pushButton_goBacktoMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);

    ui->listWidget_salesReport->clear(); //clears the list widget
}

/*
 * This buttom will take you to sales report page from the main menu
 */
void MainWindow::on_pushButton_2_salesReport_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salesReportPage);
}

/*
 * This buttom will generate the list of members and display it
 */
void MainWindow::on_pushButton_generateList_clicked()
{

    for(int i = 0; i < 10; i++)
    {
        ui->listWidget_members->addItem(QString::number(i + 1) + " add member here!!!");
    }

}

/*
 * This buttom will generate the list of sales report and display it
 */
void MainWindow::on_pushButton_generateSales_clicked()
{

    for(int i = 0; i < 10; i++)
    {
        ui->listWidget_salesReport->addItem(QString::number(i + 1) + " add sales report here here!!!");
    }

}

/*
 * This buttom will switch the members account, either to normal or executive member
 */
void MainWindow::on_pushButton_switchAccount_clicked()
{
    QListWidgetItem *item = ui->listWidget_members->currentItem();

    item->setTextColor(Qt::red);

}
