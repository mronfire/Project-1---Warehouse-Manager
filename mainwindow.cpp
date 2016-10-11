#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username, password;

    username = ui->Edituser->text();
    password = ui->Editpassword->text();

    if(username == "Admin" || username == "admin")
    {
        if(password == "admin" || password == "password")
        {
            this->hide();
            UserWindow userInfo;
            userInfo.setModal(true);
            userInfo.exec();
        }
        else
        {
            QMessageBox::information(this, "Login", "Usename or password is not correct!");
        }
    }
    else
    {
        QMessageBox::information(this, "Login", "Usename or password is not correct!");
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
