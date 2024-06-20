#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <Qsqldatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPixmap>
#include "global.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;

public:
    QSqlDatabase db;
    void ConnectMySQL(QSqlDatabase* db);

private:
    void OnClick_Login();
};

#endif // LOGINWINDOW_H
