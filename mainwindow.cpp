/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//! The constructor
/*!
 * \brief It will create the main window, plus create the list of members and days
 * \param parent
 *
 * \details Once the program is run, it will automatically create the linked lists
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memberList = CreateMemberList(memFile);         ///This will create the member list
    dayList = CreateDayList(NUMDAYS, "08/01/2015"); ///This will create the days list
    ReadPurchases(purchFile ,memberList, dayList);  ///This will read all purchases
}

//! The Destructor
/*!
 * \brief This will save all data, eliminate all members and days and the ui
 *
 * \details Once the program has ended, it will save all data and delete the linked list
 */
MainWindow::~MainWindow()
{
    SaveData(memFile, purchFile, memberList, dayList); ///Saves data after quitting program
    DeleteMembers(memberList);                         ///Always delete members before days!
    DeleteDays(dayList);                               ///Deletes days after members
    cout << "\nThank you for using my program!\n";
    delete ui;
}

//! Login button
/*!
 * \brief It will let you log in into the program
 *
 * \details It will requiere the user to enter a username and password
 *           if correct, then it will proceed, otherwise it will prompt
 *           user that username or password is incorrect
 */
void MainWindow::on_loginButton_clicked()
{
    QString username, password;

    username = ui->Edituser->text();      ///Read in the username
    password = ui->Editpassword->text();  ///Read in the password

    /*! \if correct username and password it will log in
     *  \else it will prompt the user that username or password isn't correct
     */
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

//! The close button
/*!
 * \brief The close button, to exit program
 *
 * \details This will close the program, but before save all data
 */
void MainWindow::on_closeButton_clicked()
{
    SaveData(memFile, purchFile, memberList, dayList); ///Saves all data
    this->close();
}

//! The add member button
/*!
 * \brief This button will add members to the list
 *
 * \details This will add members to the list. It requieres the user
 *          to enter a name, id, membership type, and date. If fields
 *          are empty it should prompt the user to enter all fields.
 */
void MainWindow::on_addButton_clicked()
{
    QString username, numID, date;
    member *myMember = NULL;

    myMember = new member;

    username  = ui->lineEdit_username->text();    ///reads username
    numID     = ui->lineEdit_numberID->text();    ///reads member id
    ui->radioButton_execituveType->toggled(true); ///reads membership type

    /*! \if radiio button is toggles it will set membership type to true
     *  \else it will set the membership type to false
     */
    if(ui->radioButton_execituveType->isChecked())
    {
        myMember->SetType(true);
    }
    else
    {
        myMember->SetType(false);
    }

    date      = ui->lineEdit_Date->text();

    /*! \if fields are empty it will prompt the user to enter info in all fields
     *  \else it will create the member and let the user know
     */
    if(username == NULL || numID == NULL || date == NULL)
    {
        QMessageBox::critical(this, "List of Members", "Please fill in all the fields required"
                              " in order to add a member!");
    }
    else
    {
        ///assign the member corresponding data
        myMember->SetName(username);
        myMember->SetNumber(numID);
        myMember->Renew(date);

        memberList->AddToMemberList(myMember); ///adds member to list

        QMessageBox::information(this, "List of Members", "The member has being added to "
                                 "the list!");
    }

    ///clears the line edits for next input
    ui->lineEdit_username->clear();
    ui->lineEdit_numberID->clear();
    ui->lineEdit_Date->clear();
}

//! The remove button
/*!
 * \brief This button will remove a member from the list
 *
 * \details It will allow us to remove a member from the list, base on the
 *          especifications entered by the user. It will find the member on
 *          the list and eliminate it.
 */
void MainWindow::on_removeButton_clicked()
{
    QString numID;
    member *myMember = memberList;
    member *prevMember = memberList;

    numID = ui->lineEdit_numberID->text();

    /*! \if member found is equal null, it will let the user know
     *  \else it will go thru the list and find the member, which then deletes
     *        the member chosen
     */
    if(myMember->GetThisMember(numID) == NULL)
    {
        QMessageBox::information(this, "List of Members", "There is not one member"
                                 " with that information in the database!");
    }
    else
    {
        if(myMember == memberList)
        {
            memberList = myMember->GetNextMember();
        }
        else
        {
            while(prevMember->GetNextMember() != myMember)
            {
                prevMember = prevMember->GetNextMember();
            }
            prevMember->SetNextMember(myMember->GetNextMember());
        }

        delete myMember;

        QMessageBox::information(this, "List of Members", "The member has being deleted "
                                 "from the list!");
    }

    ///clears the line edits for next input
    ui->lineEdit_username->clear();
    ui->lineEdit_numberID->clear();
    ui->lineEdit_Date->clear();
}

//! The view button
/*!
 * \brief This button will let you view all members
 */
void MainWindow::on_viewButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->viewMembersPage);
}

//! The go back button
/*!
 * \brief This button will let you go back to main menu
 */
void MainWindow::on_pushButton_goBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->memberPage);

    ui->listWidget_members->clear();   ///clears the list widget
    ui->listWidget_memPurch->clear();  ///clears the purchase list
}

//! The return to menu button
/*!
 * \brief This buttom takes you to main menu from member page
 */
void MainWindow::on_pushButton_returnToMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

//! The take me to add members button
/*!
 * \brief This button will take you to the member page
 */
void MainWindow::on_pushButton_addMembers_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->memberPage);
}

//! The go back to menu button 2
/*!
 * \brief This buttom takes you to main menu from sales report
 */
void MainWindow::on_pushButton_goBacktoMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);

    ui->listWidget_salesReport->clear(); ///clears the list widget
}

//! The sales report button
/*!
 * \brief This buttom takes you to sales report page
 */
void MainWindow::on_pushButton_2_salesReport_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salesReportPage);
}

//! The generate list button
/*!
 * \brief This buttom will generate the list of members
 *
 * \details
 */
void MainWindow::on_pushButton_generateList_clicked()
{
    ui->listWidget_members->clear();

    /*! \if member list is not empty, it will generate the list to output
     *  \else it will let the user know such member does not exist
     */
    if(memberList != NULL)
    {
        qint32 length = memberList->GetListLength();
        member *memptr = memberList;
        QString name;
        QString memNum;
        int index = 0;

        while(index < length)
        {
            name = memptr->GetName();
            memNum = memptr->GetNumber();
            ui->listWidget_members->addItem(memNum + ": " + name);
            memptr = memptr->GetNextMember();
            index++;
        }
    }
    else
    {
        ui->listWidget_members->addItem("There are no items in member list!!!");
    }
}

//! The switch account button
/*!
 * \brief This buttom will switch the account type
 *
 * \details
 */
void MainWindow::on_pushButton_switchAccount_clicked()
{
    QListWidgetItem *item = ui->listWidget_members->currentItem();

    ui->listWidget_memPurch->clear();

    /*! \if a selected item was chosen then proceed
     *  \else it will let the user know that nothing was selected
     */
    if(item != NULL)
    {
        QString memNum = item->text().left(5);
        member *memptr = memberList->GetThisMember(memNum);
        Purchase *purchptr;
        QString name;
        float   memSpent;

        /*! \if member chosen exist on the list, it will output info about member
         */
        if(memptr != NULL)
        {
            name = memptr->GetName();
            memSpent = memptr->GetSpent();
            purchptr = memptr->GetFirstPurchase();
            ui->listWidget_memPurch->addItem("Member : " + name);
            ui->listWidget_memPurch->addItem("Number : " + memNum);
            ui->listWidget_memPurch->addItem("Total Spent:");
            ui->listWidget_memPurch->addItem("Before Tax : $" + QString::number(memSpent, 'f', 2));
            memSpent = memptr->GetTaxSpent();
            ui->listWidget_memPurch->addItem("After Tax : $" + QString::number(memSpent, 'f', 2));

            /*! \if membership type is true (executive) it will let the user know that he or she could
             *       save money switching to normal membership
             *  \else it will let the user know that he or she could save monet switching to executive type
             */
            if(memptr->GetType())
            {
                ExecClass *execptr = dynamic_cast<ExecClass*>(memptr);
                float memRebate = execptr->GetRebate();

                ui->listWidget_memPurch->addItem(name + " is an Executive Member!");

                if(memptr->isWrongType())
                {
                    ui->listWidget_memPurch->addItem("You could save money if you switched to a normal membership!");
                }
                ui->listWidget_memPurch->addItem("Rebate : $" + QString::number(memRebate, 'f', 2));
            }
            else
            {
                ui->listWidget_memPurch->addItem(name + " is an Normal Member!");

                if(memptr->isWrongType())
                {
                    ui->listWidget_memPurch->addItem("You could save money if you switched to an Executive membership!");
                }
            }

            if(purchptr != NULL)
            {
                while(purchptr != NULL)
                {
                    ui->listWidget_memPurch->addItem(" -" + purchptr->getObjType());
                    purchptr = purchptr->getNextMember();
                }
            }
            else
            {
                ui->listWidget_memPurch->addItem(name + " has not bought anything yet!");
            }
        }
    }
    else
    {
        ui->listWidget_memPurch->addItem("There is no member selected!!!");
    }
}

//! The generate sales button
/*!
 * \brief This buttom will generate the sales report list
 */
void MainWindow::on_pushButton_generateSales_clicked()
{
    ui->listWidget_salesReport->clear();

    /*! \if day list is not empty it will generate the list and output details
     *  \else it will let the user know that day list is empty
     */
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

            purchptr = dayptr->GetFirstPurchase(); ///assigns to pointer first purchase of the date specified

            /*! \brief it will go thru the purchase list and output each one of them
             */
            while(purchptr != NULL)
            {
                ui->listWidget_salesReport->addItem(" -" + purchptr->getObjType());
                purchptr = purchptr->getNextDay();
            }

            index++;
            dayptr = dayptr->GetNextDay();
        }

        /*!
         * \if the firdt purchase for the specified date doesnt exist it will let the user know
         * \else it will output detailed info of the members and purchases of that date
         */
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

            /*! \brief it will go thru the purchases and output all of them */
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

//! The exit program button
/*!
 * \brief This buttom will quit the program
 */
void MainWindow::on_pushButton_exitProgram_clicked()
{
    this->close();
}

//! The add purchases page button
/*!
 * \brief This buttom will take you to the add purchases page
 */
void MainWindow::on_pushButton_addPurchasesPage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->AddPuchasePage);
}

//! The back to menu 3 button
/*!
 * \brief This buttom takes you back to main menu from purchases page
 */
void MainWindow::on_pushButton_backToMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

//! The add purchase button
/*!
 * \brief This buttom will add purchases to the list
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

    /*!
     * \if all fields have been entered correctly, it will create a new purchase
     * \else it will let the user know to enter all fields
     */
    if(date != NULL && memNum != NULL && objType != NULL)
    {
        ///creates new purchase
        purchptr = new Purchase(memNum, objType, price, quant, date);

        /*! \brief it will create the new purchase, and look the right date and member  */
        while(date != dayptr->GetDate() && dayptr->GetDate() != "Other")
        {
            dayptr = dayptr->GetNextDay();
        }

        while(memNum != memptr->GetNumber() && memptr != NULL)
        {
            memptr = memptr->GetNextMember();
        }

        /*! \if member exist and date exist different than other it will add the purchase to
         *       especific member list and day list
         *  \elseif member points to no one, it will let the user know
         *  \elseif day points to other, it will let the user know
         */
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

    ///clears all fields
    ui->dateLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->objTypeLineEdit->clear();
    ui->priceLineEdit->setText("$");
    ui->quantLineEdit->clear();
}

//! The remove purchase button
/*!
 * \brief This buttom removes purchases from the list
 */
void MainWindow::on_pushButton_removePurchase_clicked()
{
    //work on this
}

//! The view all purchases button
/*!
 * \brief This buttom lets you view all purchases made
 */
void MainWindow::on_pushButton_viewAllPurchases_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PurchViewPage);
}

//! The back to menu button
/*!
 * \brief This buttom takes you back to menu
 */
void MainWindow::on_pushButton_backMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->AddPuchasePage);
}

//! The generate item list button
/*!
 * \brief This buttom will generate the item list
 */
void MainWindow::on_pushButton_generateItemList_clicked()
{
    Purchase *purchList = NULL;
    Purchase *purchptr;
    Purchase *purchNav;
    SalesDay *dayptr = dayList;
    bool isNewItem;

    /*!
     * \brief this while loop will go thru the purchases and add them into a new
     *        list
     */
    while(dayptr != NULL)
    {
        purchptr = dayptr->GetFirstPurchase();

        /*!
         * \brief this will run as long as their is purchases in this day
         */
        while(purchptr != NULL)
        {
            /*!
             * \if there is no purchases in the day, it will create purchase and assign
             *     it to the front of the list
             * \else if there is purchases in the list, it will check if item already exist
             */
            if(purchList == NULL)
            {
                purchList = new Purchase(purchptr);
            }
            else
            {
                isNewItem = true;
                purchNav = purchList;

                /*!
                 * \brief while we are still navigating purchlist and has not found one of our item
                 */
                while(purchNav->getNextDay() != NULL && isNewItem)
                {
                    /*!
                     * \if item is not first of its kind, it will set newItem to false
                     * \else it will move thru the list
                     */
                    if(purchNav->getObjType() == purchptr->getObjType())
                    {
                        isNewItem = false;
                    }
                    else
                    {
                        purchNav = purchNav->getNextDay();
                    }
                }

                /*!
                 * \if is not a new item, it will increase the quantity of the object into existing member
                 * \else it will create a new purchase and add it to the end of the list
                 */
                if(!isNewItem)
                {
                    purchNav->setObjQuantity(purchNav->getObjQuantity() + purchptr->getObjQuantity());
                }
                else
                {
                    purchNav->setNextDay(new Purchase(purchptr));
                }
            }
            purchptr = purchptr->getNextDay(); ///point to next purchase in day
        }

        dayptr = dayptr->GetNextDay(); ///point to next day
    }

    purchptr = purchList;///point to start of list

    /*! \brief while purchase list is not empty, it will output the purchases info */
    while(purchptr != NULL)
    {
        ui->listWidget_ItemsSimple->addItem(purchptr->getObjType());
        ui->listWidget_Items->addItem("Sale of : " + purchptr->getObjType());
        ui->listWidget_Items->addItem("Quantity: " + QString::number(purchptr->getObjQuantity()));
        ui->listWidget_Items->addItem("Revenue : $" + QString::number(purchptr->getObjQuantity() * purchptr->getObjPrice(), 'f', 2));

        purchptr = purchptr->getNextDay();
    }

    /*! \brief while purchase list is not empty, it will delete all purchases */
    while(purchList != NULL)
    {
        purchptr = purchList->getNextDay();
        delete purchList;
        purchList = purchptr;
    }
}

//! The back to main button
/*!
 * \brief This buttom takes you back to main menu
 */
void MainWindow::on_pushButton_backToMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
    ui->listWidget_expMem->clear();     ///clears widget
    ui->listWidget_expMemPlus->clear(); ///clears widget
}

//! The renew membership button
/*!
 * \brief This buttom will take you to date expiration page
 */
void MainWindow::on_pushButton_renewMembership_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ExpirationPage);
}

//! The generate expiration date button
/*!
 * \brief This buttom will generate the expiration dates from members
 */
void MainWindow::on_pushButton_generateExpDate_clicked()
{
    ui->listWidget_expMem->clear();

    member *memptr = memberList;

    /*! \brief while member list is not empty, it will output the member name and expiration date */
    while(memptr != NULL)
    {
        ui->listWidget_expMem->addItem(memptr->GetNumber() + ": " + memptr->GetName() + ": " + memptr->GetExpiration());
        memptr = memptr->GetNextMember();
    }
}

//! The inspect member button
/*!
 * \brief This buttom will inspect selected member and display info
 */
void MainWindow::on_pushButton_inspectMember_clicked()
{
    QListWidgetItem *item = ui->listWidget_expMem->currentItem();

    ui->listWidget_expMemPlus->clear();

    /*!
     * \if an item from the list has being selected, it will proceed
     *  \else it will let the user know nothing has being selected
     */
    if(item != NULL)
    {
        QString memNum = item->text().left(5);
        member *memptr = memberList->GetThisMember(memNum);
        QString name;
        QString date;

        /*! \if member list is not empty, it will output the members name, number ID, and
         *      expiration date
         */
        if(memptr != NULL)
        {
            name = memptr->GetName();
            date = memptr->GetExpiration();
            ui->listWidget_expMemPlus->addItem("Member : " + name);
            ui->listWidget_expMemPlus->addItem("Number : " + memNum);
            ui->listWidget_expMemPlus->addItem("Expiration Date: " + date);

            /*!
             *  \if member is executive, it will type cast the member to executive, so it
             *      access the rebate and output members info
             *  \else it will display members info, and tell him or her to how much money it could
             *        save if he switches to executive membership
             */
            if(memptr->GetType())
            {
                ExecClass *execptr = dynamic_cast<ExecClass*>(memptr); ///dynamic cast executive pointer
                float memRebate = execptr->GetRebate();

                ui->listWidget_expMemPlus->addItem(name + " is an Executive Member!");
                ui->listWidget_expMemPlus->addItem("Cost to Renew: $95");

                /*! \if member should be a normal type membership, it will display that the user could save
                 *      an amount of money depending on the rebate if he switches to normal membership
                 */
                if(memptr->isWrongType())
                {
                    ui->listWidget_expMemPlus->addItem("You could save $" + QString::number(10 - memRebate, 'f', 2) + " if you switched to a normal membership!");
                }
            }
            else
            {
                ui->listWidget_expMemPlus->addItem(name + " is an Normal Member!");
                ui->listWidget_expMemPlus->addItem("Cost to Renew: $85");

                /*! \if member should be a executive type membership, it will display that the user could save
                 *      an amount of money depending on the rebate if he switches to executive membership
                 */
                if(memptr->isWrongType())
                {
                    ui->listWidget_expMemPlus->addItem("You could save $" + QString::number((memptr->GetSpent()*REBATE_RATE) - 10, 'f', 2) + " if you switched to an Executive membership!");
                }
            }
        }
    }
    else
    {
        ui->listWidget_expMemPlus->addItem("There is no member selected!!!");
    }
}

//! The renew to normal button
/*!
 * \brief This buttom will let you switch an member account to normal
 */
void MainWindow::on_pushButton_renewNormal_clicked()
{
    QListWidgetItem *item = ui->listWidget_expMem->currentItem(); ///points to selected item in widget

    /*!
     *  \if an item has being selected from the list widget, it will proceed
     *  \else it will let the user know that nothing has being selected
     */
    if(item != NULL)
    {
        /*!
         * \brief memNum will be taken from member selected in the list widget
         * \brief Then memptr will point to the member, which we are going to look for in the list
         */
        QString memNum = item->text().left(5);
        member *memptr = memberList->GetThisMember(memNum);
        QString name = memptr->GetName();
        QString num = memptr->GetNumber();
        QString date = memptr->GetExpiration();
        date = date.left(6) + QString::number(date.right(4).toInt() + 1); ///adds one year to exp date
        Purchase *purchptr = memptr->GetFirstPurchase();

        member *renewMember = new member(name, num, false, date); ///constructs replacement member

        /*! \brief while purchase list is not empty, its going to populate the new member with all purchases
         *         that the member had before switching membership type
         */
        while(purchptr != NULL)
        {
            renewMember->AddPurchase(purchptr);
            purchptr = purchptr->getNextMember();
        }

        memberList->AddToMemberList(renewMember); ///adds it to end of list

        member *prevMember = memberList; ///from here on out, we remove the old copy of the member from the list

        /*!
         *  \if memptr points to the first member in the list, then skip that member, and delete it
         *  \else find the memptr that points to the member we want to delete and delete it for good
         */
        if(memptr == memberList)
        {
            memberList = memptr->GetNextMember();
        }
        else
        {
            while(prevMember->GetNextMember() != memptr)
            {
                prevMember = prevMember->GetNextMember();
            }
            prevMember->SetNextMember(memptr->GetNextMember());
        }
        delete memptr;

    }

    /*! \brief it will refresh both list widgets to output correct data */
    on_pushButton_inspectMember_clicked();
    on_pushButton_generateExpDate_clicked();
}

//! The renew to executive button
/*!
 * \brief This buttom will let you switch an member account to executive
 */
void MainWindow::on_pushButton_renewExec_clicked()
{
    QListWidgetItem *item = ui->listWidget_expMem->currentItem(); ///points to selected item in widget

    /*!
     *  \if an item has being selected from the list widget, it will proceed
     *  \else it will let the user know that nothing has being selected
     */
    if(item != NULL)
    {
        /*!
         * \brief memNum will be taken from member selected in the list widget
         * \brief Then memptr will point to the member, which we are going to look for in the list
         */
        QString memNum = item->text().left(5);
        member *memptr = memberList->GetThisMember(memNum); //gets our member to renew
        QString name = memptr->GetName();
        QString num = memptr->GetNumber();
        QString date = memptr->GetExpiration();
        date = date.left(6) + QString::number(date.right(4).toInt() + 1); //adds one year to exp date
        Purchase *purchptr = memptr->GetFirstPurchase();

        member *renewMember = new ExecClass(name, num, true, date); //constructs replacement member

        /*! \brief while purchase list is not empty, its going to populate the new member with all purchases
         *         that the member had before switching membership type
         */
        while(purchptr != NULL)
        {
            renewMember->AddPurchase(purchptr);
            purchptr = purchptr->getNextMember();
        }

        memberList->AddToMemberList(renewMember); ///adds it to end of list

        member *prevMember = memberList; ///from here on out, we remove the old copy of the member from the list

        /*!
         *  \if memptr points to the first member in the list, then skip that member, and delete it
         *  \else find the memptr that points to the member we want to delete and delete it for good
         */
        if(memptr == memberList)
        {
            memberList = memptr->GetNextMember();
        }
        else
        {
            while(prevMember->GetNextMember() != memptr)
            {
                prevMember = prevMember->GetNextMember();
            }
            prevMember->SetNextMember(memptr->GetNextMember());
        }
        delete memptr;

    }

    /*! \brief it will refresh both list widgets to output correct data */
    on_pushButton_inspectMember_clicked();
    on_pushButton_generateExpDate_clicked();
}
