/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInfo_about_our_Team;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *userlabel;
    QSpacerItem *verticalSpacer;
    QLabel *passwordlabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *Editpassword;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *closeButton;
    QLineEdit *Edituser;
    QWidget *menuPage;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QLabel *label_menuHeader;
    QPushButton *pushButton_addPurchasesPage;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_2_addMember;
    QLabel *label_4;
    QLabel *label_3_sales;
    QLabel *label;
    QPushButton *pushButton_exitProgram;
    QPushButton *pushButton_2_salesReport;
    QPushButton *pushButton_addMembers;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_renewMembership;
    QLabel *label_12;
    QWidget *memberPage;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_Header;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_numberID;
    QLabel *label_executive;
    QLineEdit *lineEdit_numberID;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_Date;
    QRadioButton *radioButton_execituveType;
    QLabel *label_Date;
    QPushButton *addButton;
    QPushButton *removeButton;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *viewButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_returnToMenu;
    QWidget *viewMembersPage;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QLabel *label_3;
    QListWidget *listWidget_members;
    QListWidget *listWidget_memPurch;
    QPushButton *pushButton_goBack;
    QPushButton *pushButton_switchAccount;
    QPushButton *pushButton_generateList;
    QWidget *salesReportPage;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_goBacktoMenu;
    QListWidget *listWidget_salesReport;
    QLabel *label_2;
    QPushButton *pushButton_generateSales;
    QWidget *PurchViewPage;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_14;
    QListWidget *listWidget_ItemsSimple;
    QListWidget *listWidget_Items;
    QPushButton *pushButton_generateItemList;
    QLabel *label_11;
    QPushButton *pushButton_backMenu;
    QWidget *AddPuchasePage;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_addPurchase;
    QLabel *label_8;
    QLineEdit *objTypeLineEdit;
    QLabel *label_7;
    QLineEdit *dateLineEdit;
    QPushButton *pushButton_removePurchase;
    QPushButton *pushButton_backToMenu;
    QLineEdit *nameLineEdit;
    QLabel *label_6;
    QLineEdit *quantLineEdit;
    QLineEdit *priceLineEdit;
    QLabel *label_9;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_viewAllPurchases;
    QWidget *ExpirationPage;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_16;
    QListWidget *listWidget_expMem;
    QListWidget *listWidget_expMemPlus;
    QPushButton *pushButton_renewExec;
    QPushButton *pushButton_renewNormal;
    QPushButton *pushButton_generateExpDate;
    QLabel *label_13;
    QPushButton *pushButton_inspectMember;
    QPushButton *pushButton_backToMain;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(838, 628);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setProperty("loginIcon", QVariant(QPixmap(QString::fromUtf8(":/MyImages/img/customerlogin.PNG"))));
        actionInfo_about_our_Team = new QAction(MainWindow);
        actionInfo_about_our_Team->setObjectName(QStringLiteral("actionInfo_about_our_Team"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        loginPage = new QWidget();
        loginPage->setObjectName(QStringLiteral("loginPage"));
        gridLayout_4 = new QGridLayout(loginPage);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 4, 1, 1);

        userlabel = new QLabel(loginPage);
        userlabel->setObjectName(QStringLiteral("userlabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        userlabel->setFont(font);

        gridLayout->addWidget(userlabel, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 3, 1, 1);

        passwordlabel = new QLabel(loginPage);
        passwordlabel->setObjectName(QStringLiteral("passwordlabel"));
        passwordlabel->setFont(font);

        gridLayout->addWidget(passwordlabel, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        Editpassword = new QLineEdit(loginPage);
        Editpassword->setObjectName(QStringLiteral("Editpassword"));
        Editpassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(Editpassword, 2, 3, 1, 1);

        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setIconSize(QSize(16, 16));

        gridLayout->addWidget(loginButton, 3, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        closeButton = new QPushButton(loginPage);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout->addWidget(closeButton, 4, 3, 1, 1);

        Edituser = new QLineEdit(loginPage);
        Edituser->setObjectName(QStringLiteral("Edituser"));
        Edituser->setAutoFillBackground(false);
        Edituser->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(Edituser, 1, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(loginPage);
        menuPage = new QWidget();
        menuPage->setObjectName(QStringLiteral("menuPage"));
        gridLayout_9 = new QGridLayout(menuPage);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_menuHeader = new QLabel(menuPage);
        label_menuHeader->setObjectName(QStringLiteral("label_menuHeader"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_menuHeader->setFont(font1);
        label_menuHeader->setCursor(QCursor(Qt::ArrowCursor));
        label_menuHeader->setLayoutDirection(Qt::LeftToRight);

        gridLayout_8->addWidget(label_menuHeader, 0, 0, 1, 1);

        pushButton_addPurchasesPage = new QPushButton(menuPage);
        pushButton_addPurchasesPage->setObjectName(QStringLiteral("pushButton_addPurchasesPage"));

        gridLayout_8->addWidget(pushButton_addPurchasesPage, 8, 1, 1, 1);

        label_5 = new QLabel(menuPage);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_8->addWidget(label_5, 8, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_6, 11, 1, 1, 1);

        label_2_addMember = new QLabel(menuPage);
        label_2_addMember->setObjectName(QStringLiteral("label_2_addMember"));

        gridLayout_8->addWidget(label_2_addMember, 6, 0, 1, 1);

        label_4 = new QLabel(menuPage);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_8->addWidget(label_4, 10, 0, 1, 1);

        label_3_sales = new QLabel(menuPage);
        label_3_sales->setObjectName(QStringLiteral("label_3_sales"));

        gridLayout_8->addWidget(label_3_sales, 7, 0, 1, 1);

        label = new QLabel(menuPage);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        gridLayout_8->addWidget(label, 4, 0, 1, 1);

        pushButton_exitProgram = new QPushButton(menuPage);
        pushButton_exitProgram->setObjectName(QStringLiteral("pushButton_exitProgram"));

        gridLayout_8->addWidget(pushButton_exitProgram, 10, 1, 1, 1);

        pushButton_2_salesReport = new QPushButton(menuPage);
        pushButton_2_salesReport->setObjectName(QStringLiteral("pushButton_2_salesReport"));

        gridLayout_8->addWidget(pushButton_2_salesReport, 7, 1, 1, 1);

        pushButton_addMembers = new QPushButton(menuPage);
        pushButton_addMembers->setObjectName(QStringLiteral("pushButton_addMembers"));

        gridLayout_8->addWidget(pushButton_addMembers, 6, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_7, 0, 1, 1, 1);

        pushButton_renewMembership = new QPushButton(menuPage);
        pushButton_renewMembership->setObjectName(QStringLiteral("pushButton_renewMembership"));

        gridLayout_8->addWidget(pushButton_renewMembership, 9, 1, 1, 1);

        label_12 = new QLabel(menuPage);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_8->addWidget(label_12, 9, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 1, 0, 1, 4);

        stackedWidget->addWidget(menuPage);
        memberPage = new QWidget();
        memberPage->setObjectName(QStringLiteral("memberPage"));
        gridLayout_5 = new QGridLayout(memberPage);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_Header = new QLabel(memberPage);
        label_Header->setObjectName(QStringLiteral("label_Header"));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(10);
        font3.setUnderline(true);
        label_Header->setFont(font3);

        gridLayout_2->addWidget(label_Header, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 2, 1, 1);

        label_numberID = new QLabel(memberPage);
        label_numberID->setObjectName(QStringLiteral("label_numberID"));

        gridLayout_2->addWidget(label_numberID, 3, 1, 1, 1);

        label_executive = new QLabel(memberPage);
        label_executive->setObjectName(QStringLiteral("label_executive"));

        gridLayout_2->addWidget(label_executive, 4, 1, 1, 1);

        lineEdit_numberID = new QLineEdit(memberPage);
        lineEdit_numberID->setObjectName(QStringLiteral("lineEdit_numberID"));

        gridLayout_2->addWidget(lineEdit_numberID, 3, 2, 1, 1);

        label_username = new QLabel(memberPage);
        label_username->setObjectName(QStringLiteral("label_username"));

        gridLayout_2->addWidget(label_username, 2, 1, 1, 1);

        lineEdit_username = new QLineEdit(memberPage);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        gridLayout_2->addWidget(lineEdit_username, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        lineEdit_Date = new QLineEdit(memberPage);
        lineEdit_Date->setObjectName(QStringLiteral("lineEdit_Date"));

        gridLayout_2->addWidget(lineEdit_Date, 5, 2, 1, 1);

        radioButton_execituveType = new QRadioButton(memberPage);
        radioButton_execituveType->setObjectName(QStringLiteral("radioButton_execituveType"));
        radioButton_execituveType->setCheckable(true);
        radioButton_execituveType->setChecked(false);

        gridLayout_2->addWidget(radioButton_execituveType, 4, 2, 1, 1);

        label_Date = new QLabel(memberPage);
        label_Date->setObjectName(QStringLiteral("label_Date"));

        gridLayout_2->addWidget(label_Date, 5, 1, 1, 1);

        addButton = new QPushButton(memberPage);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout_2->addWidget(addButton, 7, 1, 1, 1);

        removeButton = new QPushButton(memberPage);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        gridLayout_2->addWidget(removeButton, 7, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 6, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 4, 1, 1);

        viewButton = new QPushButton(memberPage);
        viewButton->setObjectName(QStringLiteral("viewButton"));

        gridLayout_2->addWidget(viewButton, 7, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 9, 2, 1, 1);

        pushButton_returnToMenu = new QPushButton(memberPage);
        pushButton_returnToMenu->setObjectName(QStringLiteral("pushButton_returnToMenu"));

        gridLayout_2->addWidget(pushButton_returnToMenu, 8, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(memberPage);
        viewMembersPage = new QWidget();
        viewMembersPage->setObjectName(QStringLiteral("viewMembersPage"));
        gridLayout_7 = new QGridLayout(viewMembersPage);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_3 = new QLabel(viewMembersPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        label_3->setFont(font4);

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);

        listWidget_members = new QListWidget(viewMembersPage);
        listWidget_members->setObjectName(QStringLiteral("listWidget_members"));
        listWidget_members->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listWidget_members->setSortingEnabled(false);

        gridLayout_6->addWidget(listWidget_members, 1, 0, 1, 1);

        listWidget_memPurch = new QListWidget(viewMembersPage);
        listWidget_memPurch->setObjectName(QStringLiteral("listWidget_memPurch"));

        gridLayout_6->addWidget(listWidget_memPurch, 1, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        pushButton_goBack = new QPushButton(viewMembersPage);
        pushButton_goBack->setObjectName(QStringLiteral("pushButton_goBack"));

        gridLayout_7->addWidget(pushButton_goBack, 3, 0, 1, 1);

        pushButton_switchAccount = new QPushButton(viewMembersPage);
        pushButton_switchAccount->setObjectName(QStringLiteral("pushButton_switchAccount"));

        gridLayout_7->addWidget(pushButton_switchAccount, 2, 0, 1, 1);

        pushButton_generateList = new QPushButton(viewMembersPage);
        pushButton_generateList->setObjectName(QStringLiteral("pushButton_generateList"));

        gridLayout_7->addWidget(pushButton_generateList, 1, 0, 1, 1);

        stackedWidget->addWidget(viewMembersPage);
        salesReportPage = new QWidget();
        salesReportPage->setObjectName(QStringLiteral("salesReportPage"));
        gridLayout_11 = new QGridLayout(salesReportPage);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        pushButton_goBacktoMenu = new QPushButton(salesReportPage);
        pushButton_goBacktoMenu->setObjectName(QStringLiteral("pushButton_goBacktoMenu"));

        gridLayout_10->addWidget(pushButton_goBacktoMenu, 3, 0, 1, 1);

        listWidget_salesReport = new QListWidget(salesReportPage);
        listWidget_salesReport->setObjectName(QStringLiteral("listWidget_salesReport"));

        gridLayout_10->addWidget(listWidget_salesReport, 1, 0, 1, 1);

        label_2 = new QLabel(salesReportPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font4);

        gridLayout_10->addWidget(label_2, 0, 0, 1, 1);

        pushButton_generateSales = new QPushButton(salesReportPage);
        pushButton_generateSales->setObjectName(QStringLiteral("pushButton_generateSales"));

        gridLayout_10->addWidget(pushButton_generateSales, 2, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);

        stackedWidget->addWidget(salesReportPage);
        PurchViewPage = new QWidget();
        PurchViewPage->setObjectName(QStringLiteral("PurchViewPage"));
        gridLayout_15 = new QGridLayout(PurchViewPage);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        listWidget_ItemsSimple = new QListWidget(PurchViewPage);
        listWidget_ItemsSimple->setObjectName(QStringLiteral("listWidget_ItemsSimple"));

        gridLayout_14->addWidget(listWidget_ItemsSimple, 0, 0, 1, 1);

        listWidget_Items = new QListWidget(PurchViewPage);
        listWidget_Items->setObjectName(QStringLiteral("listWidget_Items"));

        gridLayout_14->addWidget(listWidget_Items, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_14, 1, 0, 1, 1);

        pushButton_generateItemList = new QPushButton(PurchViewPage);
        pushButton_generateItemList->setObjectName(QStringLiteral("pushButton_generateItemList"));

        gridLayout_15->addWidget(pushButton_generateItemList, 2, 0, 1, 1);

        label_11 = new QLabel(PurchViewPage);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_15->addWidget(label_11, 0, 0, 1, 1);

        pushButton_backMenu = new QPushButton(PurchViewPage);
        pushButton_backMenu->setObjectName(QStringLiteral("pushButton_backMenu"));

        gridLayout_15->addWidget(pushButton_backMenu, 3, 0, 1, 1);

        stackedWidget->addWidget(PurchViewPage);
        AddPuchasePage = new QWidget();
        AddPuchasePage->setObjectName(QStringLiteral("AddPuchasePage"));
        gridLayout_13 = new QGridLayout(AddPuchasePage);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        pushButton_addPurchase = new QPushButton(AddPuchasePage);
        pushButton_addPurchase->setObjectName(QStringLiteral("pushButton_addPurchase"));

        gridLayout_12->addWidget(pushButton_addPurchase, 7, 2, 1, 1);

        label_8 = new QLabel(AddPuchasePage);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_12->addWidget(label_8, 3, 1, 1, 1);

        objTypeLineEdit = new QLineEdit(AddPuchasePage);
        objTypeLineEdit->setObjectName(QStringLiteral("objTypeLineEdit"));

        gridLayout_12->addWidget(objTypeLineEdit, 3, 2, 1, 1);

        label_7 = new QLabel(AddPuchasePage);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_12->addWidget(label_7, 2, 1, 1, 1);

        dateLineEdit = new QLineEdit(AddPuchasePage);
        dateLineEdit->setObjectName(QStringLiteral("dateLineEdit"));

        gridLayout_12->addWidget(dateLineEdit, 2, 2, 1, 1);

        pushButton_removePurchase = new QPushButton(AddPuchasePage);
        pushButton_removePurchase->setObjectName(QStringLiteral("pushButton_removePurchase"));

        gridLayout_12->addWidget(pushButton_removePurchase, 8, 2, 1, 1);

        pushButton_backToMenu = new QPushButton(AddPuchasePage);
        pushButton_backToMenu->setObjectName(QStringLiteral("pushButton_backToMenu"));

        gridLayout_12->addWidget(pushButton_backToMenu, 10, 2, 1, 1);

        nameLineEdit = new QLineEdit(AddPuchasePage);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout_12->addWidget(nameLineEdit, 1, 2, 1, 1);

        label_6 = new QLabel(AddPuchasePage);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_12->addWidget(label_6, 1, 1, 1, 1);

        quantLineEdit = new QLineEdit(AddPuchasePage);
        quantLineEdit->setObjectName(QStringLiteral("quantLineEdit"));

        gridLayout_12->addWidget(quantLineEdit, 6, 2, 1, 1);

        priceLineEdit = new QLineEdit(AddPuchasePage);
        priceLineEdit->setObjectName(QStringLiteral("priceLineEdit"));

        gridLayout_12->addWidget(priceLineEdit, 4, 2, 1, 1);

        label_9 = new QLabel(AddPuchasePage);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_12->addWidget(label_9, 4, 1, 1, 1);

        label_10 = new QLabel(AddPuchasePage);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_12->addWidget(label_10, 6, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_8, 11, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_9, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_6, 4, 3, 1, 1);

        pushButton_viewAllPurchases = new QPushButton(AddPuchasePage);
        pushButton_viewAllPurchases->setObjectName(QStringLiteral("pushButton_viewAllPurchases"));

        gridLayout_12->addWidget(pushButton_viewAllPurchases, 9, 2, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 0, 0, 1, 1);

        stackedWidget->addWidget(AddPuchasePage);
        ExpirationPage = new QWidget();
        ExpirationPage->setObjectName(QStringLiteral("ExpirationPage"));
        gridLayout_17 = new QGridLayout(ExpirationPage);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        listWidget_expMem = new QListWidget(ExpirationPage);
        listWidget_expMem->setObjectName(QStringLiteral("listWidget_expMem"));

        gridLayout_16->addWidget(listWidget_expMem, 1, 0, 1, 1);

        listWidget_expMemPlus = new QListWidget(ExpirationPage);
        listWidget_expMemPlus->setObjectName(QStringLiteral("listWidget_expMemPlus"));

        gridLayout_16->addWidget(listWidget_expMemPlus, 1, 1, 1, 1);

        pushButton_renewExec = new QPushButton(ExpirationPage);
        pushButton_renewExec->setObjectName(QStringLiteral("pushButton_renewExec"));

        gridLayout_16->addWidget(pushButton_renewExec, 5, 1, 1, 1);

        pushButton_renewNormal = new QPushButton(ExpirationPage);
        pushButton_renewNormal->setObjectName(QStringLiteral("pushButton_renewNormal"));

        gridLayout_16->addWidget(pushButton_renewNormal, 5, 0, 1, 1);

        pushButton_generateExpDate = new QPushButton(ExpirationPage);
        pushButton_generateExpDate->setObjectName(QStringLiteral("pushButton_generateExpDate"));

        gridLayout_16->addWidget(pushButton_generateExpDate, 3, 0, 1, 2);

        label_13 = new QLabel(ExpirationPage);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_16->addWidget(label_13, 0, 0, 1, 1);

        pushButton_inspectMember = new QPushButton(ExpirationPage);
        pushButton_inspectMember->setObjectName(QStringLiteral("pushButton_inspectMember"));

        gridLayout_16->addWidget(pushButton_inspectMember, 4, 0, 1, 2);


        gridLayout_17->addLayout(gridLayout_16, 0, 0, 1, 1);

        pushButton_backToMain = new QPushButton(ExpirationPage);
        pushButton_backToMain->setObjectName(QStringLiteral("pushButton_backToMain"));

        gridLayout_17->addWidget(pushButton_backToMain, 1, 0, 1, 1);

        stackedWidget->addWidget(ExpirationPage);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 838, 21));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(Edituser, Editpassword);
        QWidget::setTabOrder(Editpassword, loginButton);
        QWidget::setTabOrder(loginButton, closeButton);
        QWidget::setTabOrder(closeButton, pushButton_addMembers);
        QWidget::setTabOrder(pushButton_addMembers, pushButton_2_salesReport);
        QWidget::setTabOrder(pushButton_2_salesReport, pushButton_exitProgram);
        QWidget::setTabOrder(pushButton_exitProgram, lineEdit_username);
        QWidget::setTabOrder(lineEdit_username, lineEdit_numberID);
        QWidget::setTabOrder(lineEdit_numberID, radioButton_execituveType);
        QWidget::setTabOrder(radioButton_execituveType, lineEdit_Date);
        QWidget::setTabOrder(lineEdit_Date, addButton);
        QWidget::setTabOrder(addButton, removeButton);
        QWidget::setTabOrder(removeButton, viewButton);
        QWidget::setTabOrder(viewButton, pushButton_returnToMenu);
        QWidget::setTabOrder(pushButton_returnToMenu, listWidget_members);
        QWidget::setTabOrder(listWidget_members, pushButton_goBacktoMenu);
        QWidget::setTabOrder(pushButton_goBacktoMenu, listWidget_salesReport);

        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addSeparator();
        menuAbout->addAction(actionInfo_about_our_Team);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        listWidget_members->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionInfo_about_our_Team->setText(QApplication::translate("MainWindow", "Info about our Team", 0));
        userlabel->setText(QApplication::translate("MainWindow", "User Name:", 0));
        passwordlabel->setText(QApplication::translate("MainWindow", "Password:", 0));
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0));
        closeButton->setText(QApplication::translate("MainWindow", "Exit Program", 0));
        label_menuHeader->setText(QApplication::translate("MainWindow", "MAIN MENU", 0));
        pushButton_addPurchasesPage->setText(QApplication::translate("MainWindow", "GO", 0));
        label_5->setText(QApplication::translate("MainWindow", "3 - Add Purchases", 0));
        label_2_addMember->setText(QApplication::translate("MainWindow", "1 - Add, Remove or View Members", 0));
        label_4->setText(QApplication::translate("MainWindow", "5 - Exit Program", 0));
        label_3_sales->setText(QApplication::translate("MainWindow", "2 - Produce a Sales Report", 0));
        label->setText(QApplication::translate("MainWindow", "Please choose an option from the menu:", 0));
        pushButton_exitProgram->setText(QApplication::translate("MainWindow", "EXIT", 0));
        pushButton_2_salesReport->setText(QApplication::translate("MainWindow", "GO", 0));
        pushButton_addMembers->setText(QApplication::translate("MainWindow", "GO", 0));
        pushButton_renewMembership->setText(QApplication::translate("MainWindow", "GO", 0));
        label_12->setText(QApplication::translate("MainWindow", "4 - Renew Membership", 0));
        label_Header->setText(QApplication::translate("MainWindow", "Enter Member Information", 0));
        label_numberID->setText(QApplication::translate("MainWindow", "Member Number ID", 0));
        label_executive->setText(QApplication::translate("MainWindow", "Executive Member", 0));
        label_username->setText(QApplication::translate("MainWindow", "Member Name", 0));
        radioButton_execituveType->setText(QString());
        label_Date->setText(QApplication::translate("MainWindow", "Date", 0));
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        viewButton->setText(QApplication::translate("MainWindow", "View", 0));
        pushButton_returnToMenu->setText(QApplication::translate("MainWindow", "Return to Main Menu", 0));
        label_3->setText(QApplication::translate("MainWindow", "List of Members", 0));
        pushButton_goBack->setText(QApplication::translate("MainWindow", "Go back", 0));
        pushButton_switchAccount->setText(QApplication::translate("MainWindow", "View Member", 0));
        pushButton_generateList->setText(QApplication::translate("MainWindow", "Generate List", 0));
        pushButton_goBacktoMenu->setText(QApplication::translate("MainWindow", "Go Back", 0));
        label_2->setText(QApplication::translate("MainWindow", "The Sales Report", 0));
        pushButton_generateSales->setText(QApplication::translate("MainWindow", "Generate Sales Report", 0));
        pushButton_generateItemList->setText(QApplication::translate("MainWindow", "Generate Item List", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; text-decoration: underline;\">Item List</span></p></body></html>", 0));
        pushButton_backMenu->setText(QApplication::translate("MainWindow", "Go Back", 0));
        pushButton_addPurchase->setText(QApplication::translate("MainWindow", "Add Purchase", 0));
        label_8->setText(QApplication::translate("MainWindow", "Object Type :", 0));
        label_7->setText(QApplication::translate("MainWindow", "Date :", 0));
        pushButton_removePurchase->setText(QApplication::translate("MainWindow", "Remove Purchase", 0));
        pushButton_backToMenu->setText(QApplication::translate("MainWindow", "Back to Main Menu", 0));
        label_6->setText(QApplication::translate("MainWindow", "Member Number : ", 0));
        priceLineEdit->setText(QApplication::translate("MainWindow", "$", 0));
        label_9->setText(QApplication::translate("MainWindow", "Price :", 0));
        label_10->setText(QApplication::translate("MainWindow", "Quantity :", 0));
        pushButton_viewAllPurchases->setText(QApplication::translate("MainWindow", "View All Purchases", 0));
        pushButton_renewExec->setText(QApplication::translate("MainWindow", "Renew as Executive Member", 0));
        pushButton_renewNormal->setText(QApplication::translate("MainWindow", "Renew as normal member", 0));
        pushButton_generateExpDate->setText(QApplication::translate("MainWindow", "Generate Expiration Date List", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; text-decoration: underline;\">Expiration Data</span></p></body></html>", 0));
        pushButton_inspectMember->setText(QApplication::translate("MainWindow", "Inspect Member", 0));
        pushButton_backToMain->setText(QApplication::translate("MainWindow", "Return to Main Menu", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
