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
            //instead of using different windows and adding more files to our
            //project, i figure out how to work the stacked widget
            ui->stackedWidget->setCurrentWidget(ui->memberPage);

        }
        else
        {
            QMessageBox::critical(this, "Login", "Password is not correct!");
        }
    }
    else
    {
        QMessageBox::critical(this, "Login", "Usename is not correct!");
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
    QString username, password, date;
    bool    executive;
    member *myMember = NULL;

    username  = ui->lineEdit_username->text();
    password  = ui->lineEdit_numberID->text();
    executive = ui->radioButton_execituveType;
    date      = ui->lineEdit_Date->text();

    //work on this
    myMember->SetName(username);
    myMember->SetNumber(password);
    myMember->SetType(executive);
    myMember->Renew(date);

    myMember->AddToMemberList(myMember);

    QMessageBox::information(this, "List of Members", "The member has being added to "
                             "the list!");
}

/*
 * This buttom will remove the member especified by the user and either open
 *  up another window showing the information about that user being eliminated,
 *  or just show in a QMessage box, that a member has being eliminated
 */
void MainWindow::on_removeButton_clicked()
{
    //work on this

}

/*
 * This buttom will output in a differet stacked widget a list of the members
 *  in the linked list
 */
void MainWindow::on_viewButton_clicked()
{
    //work on this

}
