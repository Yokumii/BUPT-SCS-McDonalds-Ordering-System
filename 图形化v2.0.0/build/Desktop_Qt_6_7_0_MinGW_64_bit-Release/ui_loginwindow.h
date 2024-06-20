/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Input;
    QLabel *label;
    QLineEdit *ID_Input;
    QLabel *label_2;
    QLineEdit *Password_Input;
    QLabel *label_3;
    QComboBox *comboUserType;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 600);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 240, 351, 297));
        Input = new QVBoxLayout(verticalLayoutWidget);
        Input->setSpacing(10);
        Input->setObjectName("Input");
        Input->setSizeConstraint(QLayout::SetDefaultConstraint);
        Input->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\261\211\344\273\252\350\217\261\345\277\203\344\275\223\347\256\200")});
        font.setPointSize(12);
        label->setFont(font);

        Input->addWidget(label);

        ID_Input = new QLineEdit(verticalLayoutWidget);
        ID_Input->setObjectName("ID_Input");
        QFont font1;
        font1.setPointSize(15);
        ID_Input->setFont(font1);

        Input->addWidget(ID_Input);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        Input->addWidget(label_2);

        Password_Input = new QLineEdit(verticalLayoutWidget);
        Password_Input->setObjectName("Password_Input");
        Password_Input->setFont(font1);

        Input->addWidget(Password_Input);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        Input->addWidget(label_3);

        comboUserType = new QComboBox(verticalLayoutWidget);
        comboUserType->setObjectName("comboUserType");
        comboUserType->setFont(font1);

        Input->addWidget(comboUserType);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\261\211\344\273\252\350\217\261\345\277\203\344\275\223\347\256\200")});
        font2.setPointSize(12);
        font2.setBold(false);
        pushButton->setFont(font2);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        Input->addLayout(horizontalLayout_2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 0, 161, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\224\220\345\255\227\351\200\274\346\240\274\351\235\222\346\230\245\344\275\223\347\256\2002.0")});
        font3.setPointSize(15);
        font3.setBold(true);
        label_4->setFont(font3);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, -1, 401, 581));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 25));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\345\214\227\351\202\256\344\272\272\351\272\246\345\275\223\345\212\263\345\234\250\347\272\277\347\202\271\351\244\220\342\200\224\342\200\224\347\273\237\344\270\200\350\272\253\344\273\275\350\256\244\350\257\201", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\245\345\255\246\345\267\245\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225\346\226\271\345\274\217", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "\347\273\237\344\270\200\350\272\253\344\273\275\350\256\244\350\257\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
