/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
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
    SaveData(memFile, purchFile, memberList, dayList);
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

        memberList->AddToMemberList(myMember); //adds member to list

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
    if(memberList != NULL)
    {
        qint32 length = memberList->GetListLength();
        member *memptr = memberList;
        Purchase *purchptr;
        QString name;
        QString memNum;
        float   memSpent;
        int index = 0;


        while(index < length)
        {
            name = memptr->GetName();
            memNum = memptr->GetNumber();
            memSpent = memptr->GetSpent();
            ui->listWidget_members->addItem("Member : " + QString::number(index + 1));
            ui->listWidget_members->addItem("Name   : " + name);
            ui->listWidget_members->addItem("Number : " + memNum);
            ui->listWidget_members->addItem("Spent  : $" + QString::number(memSpent, 'f', 2));
            purchptr = memptr->GetFirstPurchase();
            while(purchptr != NULL)
            {
                ui->listWidget_members->addItem(" -" + purchptr->getObjType());
                purchptr = purchptr->getNextMember();
            }
            memptr = memptr->GetNextMember();
            index++;
        }
    }
    else
    {
        ui->listWidget_members->addItem("There are no items in member list!!!");
    }
}

/*
 * This buttom will generate the list of sales report and display it
 */
void MainWindow::on_pushButton_generateSales_clicked()
{
    if(dayList != NULL)
    {
        int numDays = NUMDAYS;
        int index = 0;
        SalesDay *dayptr = dayList;
        Purchase *purchptr = NULL;

        while(index < numDays)
        {
            ui->listWidget_salesReport->addItem("Sales Date : " + dayptr->GetDate());
            ui->listWidget_salesReport->addItem("Total Revenue: $" + QString::number(dayptr->GetRevenue(), 'f', 2));
            ui->listWidget_salesReport->addItem("Normal Members: " + QString::number(dayptr->GetMem()));
            ui->listWidget_salesReport->addItem("Executive Members: " + QString::number(dayptr->GetExec()));
            purchptr = dayptr->GetFirstPurchase();
            while(purchptr != NULL)
            {
                ui->listWidget_salesReport->addItem(" -" + purchptr->getObjType());
                purchptr = purchptr->getNextDay();
            }
            index++;
            dayptr = dayptr->GetNextDay();
        }
        if(dayptr->GetFirstPurchase() == NULL)
        {
            ui->listWidget_salesReport->addItem("There are no purchases in day \"Other\"");
        }
        else
        {
            ui->listWidget_salesReport->addItem("Out of Bounds Dates");
            ui->listWidget_salesReport->addItem("Total Revenue: $" + QString::number(dayptr->GetRevenue(), 'f', 2));
            ui->listWidget_salesReport->addItem("Normal Members: " + QString::number(dayptr->GetMem()));
            ui->listWidget_salesReport->addItem("Executive Members: " + QString::number(dayptr->GetExec()));
            purchptr = dayptr->GetFirstPurchase();
            while(purchptr != NULL)
            {
                ui->listWidget_salesReport->addItem(" -" + purchptr->getObjType());
                purchptr = purchptr->getNextDay();
            }
        }
    }
    else
    {
        ui->listWidget_salesReport->addItem("DayList is empty!!!");
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

/*
 * This buttom will exit the program from the main menu
 */
void MainWindow::on_pushButton_exitProgram_clicked()
{
    this->close();
}

/*
 * This buttom will take you the add purchases page
 */
void MainWindow::on_pushButton_addPurchasesPage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->AddPuchasePage);
}

/*
 * This buttom will take you back to the main menu from add purchases page
 */
void MainWindow::on_pushButton_backToMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

/*
 * This buttom add members to the list
 */
void MainWindow::on_pushButton_addPurchase_clicked()
{
    Purchase *purchptr;
    SalesDay *dayptr = dayList;
    member   *memptr = memberList;

    QString date;
    QString memNum;
    QString objType;
    float price = 0;
    int quant = 1;

    date = ui->dateLineEdit->text();
    memNum = ui->nameLineEdit->text();
    objType = ui->objTypeLineEdit->text();
    price = ui->priceLineEdit->text().remove('$').toFloat();
    quant = ui->quantLineEdit->text().toInt();

    if(date != NULL && memNum != NULL && objType != NULL)
    {
        purchptr = new Purchase(memNum, objType, price, quant, date);
        while(date != dayptr->GetDate() && dayptr->GetDate() != "Other")
        {
            dayptr = dayptr->GetNextDay();
        }

        while(memNum != memptr->GetNumber() && memptr != NULL)
        {
            memptr = memptr->GetNextMember();
        }

        if(memptr != NULL && dayptr->GetDate() != "Other")
        {
            dayptr->AddPurchase(purchptr, memberList);
            memptr->AddPurchase(purchptr);
        }
        else if(memptr == NULL)
        {
            QMessageBox::information(this, "Purchase List", "There is no such member in the list, please try again!");
        }
        else if(dayptr->GetDate() == "Other")
        {
            QMessageBox::information(this, "Purchase List", "Please try to enter a date between ---- to ----!!");
        }
    }
    else
    {
        QMessageBox::critical(this, "Purchase List", "Please fill in all the fields required"
                                  " in order to add a purchase!");
    }

    //clears all fields
    ui->dateLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->objTypeLineEdit->clear();
    ui->priceLineEdit->setText("$");
    ui->quantLineEdit->clear();
}

void MainWindow::on_pushButton_removePurchase_clicked()
{
    //work on this
}
