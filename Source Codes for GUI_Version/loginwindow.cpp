#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "customer.h"
#include "unistd.h"
#include <QScreen>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    //固定登录窗口大小

    setFixedSize(this->width(), this->height());
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // 计算窗口应该移动到的位置
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    // 将窗口移动到屏幕中心
    move(x, y);

    ui->widget->setStyleSheet("background-image: url(:/ui_icon/login.png);");
    ui->widget->lower();
    //初始化登录系统
    ConnectMySQL(&db);
    bool IsOpen = db.open();
    if (IsOpen)
    {
        QMessageBox::information(this, "提示", "系统启动中，请耐心等待哦",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this,"提示","启动失败,请再试一次",QMessageBox::Close);
    }
    ui->label->setStyleSheet("color: blue;");
    ui->label_2->setStyleSheet("color: blue;");
    ui->label_3->setStyleSheet("color: blue;");
    ui->label_4->setStyleSheet("color: blue;");
    ui->ID_Input->setStyleSheet("background-color: rgba(211, 211, 211, 200); border: 1px solid orange; color: black;");
    ui->Password_Input->setStyleSheet("background-color: rgba(211, 211, 211, 200); border: 1px solid orange; color: black;");
    ui->comboUserType->addItem("普通用户");
    ui->comboUserType->addItem("麦当劳管理员");
    ui->comboUserType->setStyleSheet(
        "QComboBox {"
        "   border: 2px solid yellow;"
        "   background-color: orange;"
        "   font: 14pt Arial;"
        "}"
        "QComboBox QAbstractItemView {"
        "   border: 2px solid yellow;"
        "   selection-background-color: orange;"
        "   selection-color: black;"
        "}"
        "QComboBox QAbstractItemView::item:selected {"
        "   background-color: transparent;"
        "   border: 2px solid red;"
        "}"
        "QComboBox QAbstractItemView::item:hover {"
        "   background-color: transparent;"
        "   border: 2px solid yellow;"
        "}"
        );

    ui->Password_Input->setEchoMode(QLineEdit::Password);

    ui->pushButton->setFixedSize(80, 30);
    ui->pushButton->setStyleSheet("QPushButton { border: 2px solid #fff700; border-radius: 6px; padding: 5px; font: bold 14px; color: white; background-color: #ffa958; }");


    connect(ui->pushButton, &QPushButton::clicked, this, &LoginWindow::OnClick_Login);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::OnClick_Login()
{
    QString userid = ui->ID_Input->text();
    QString password = ui->Password_Input->text();
    QString usertype = ui->comboUserType->currentText();

    QSqlQuery sqlquery;
    sqlquery.prepare("SELECT * FROM user WHERE UserID = :userid AND UserPassword = :password AND UserType = :usertype");
    sqlquery.bindValue(":userid", userid);
    sqlquery.bindValue(":password", password);
    sqlquery.bindValue(":usertype", usertype);
    if (sqlquery.exec() && sqlquery.next())
    {
        QString username = sqlquery.value("UserName").toString();
        QMessageBox::information(this, "登录成功", "欢迎 " + username + " 光临北邮人麦当劳！快来点餐吧！🍔🍟💫",QMessageBox::Yes);
        if (usertype == "麦当劳管理员")
        {
            QMessageBox::information(this, "提示", "服务端待开发，暂不支持",QMessageBox::Yes);
        }
        else
        {
            Customer *customer = new Customer();
            customer->setWindowIcon(QIcon(":/button_icon/icon.jpg"));
            customer->show();
            this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误，请重新输入!",QMessageBox::Yes);
    }


}

void LoginWindow::ConnectMySQL(QSqlDatabase* db)
{
    *db = QSqlDatabase::addDatabase("QMYSQL");
    db->setHostName("localhost");
    db->setUserName("root");
    db->setPort(3306);
    db->setDatabaseName("byr_mcdonald");
    db->setPassword("12345678"); //请根据实际情况输入
}
