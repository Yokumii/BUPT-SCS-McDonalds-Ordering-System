/********************************************************************************
** Form generated from reading UI file 'user_manager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MANAGER_H
#define UI_USER_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_manager
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableView *tableView;

    void setupUi(QWidget *user_manager)
    {
        if (user_manager->objectName().isEmpty())
            user_manager->setObjectName("user_manager");
        user_manager->resize(750, 600);
        verticalLayoutWidget = new QWidget(user_manager);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 30, 571, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(user_manager);

        QMetaObject::connectSlotsByName(user_manager);
    } // setupUi

    void retranslateUi(QWidget *user_manager)
    {
        user_manager->setWindowTitle(QCoreApplication::translate("user_manager", "Form", nullptr));
        label->setText(QCoreApplication::translate("user_manager", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("user_manager", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("user_manager", "\346\233\264\346\226\260\347\224\250\346\210\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("user_manager", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_manager: public Ui_user_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MANAGER_H
