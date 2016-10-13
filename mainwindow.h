#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "purchase.h"
#include "sales.h"
#include "member.h"
#include "fileparsing.h"
//#include "userwindow.h"

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
    void on_loginButton_clicked();                           //login buttom
    void on_closeButton_clicked();                           //closes program
    void on_addButton_clicked();                             //add member
    void on_removeButton_clicked();                          //remove member
    void on_viewButton_clicked();                            //view members

private:
    Ui::MainWindow *ui;
    QString memFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/members.txt";
    QString purchFile = "C:/Users/marod/Desktop/Project-1---T.E.A.M/purchases.txt";
};

#endif // MAINWINDOW_H
