/********************************************************************************
** Form generated from reading UI file 'food_manager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOOD_MANAGER_H
#define UI_FOOD_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_food_manager
{
public:
    QWidget *verticalLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableView *tableView;

    void setupUi(QWidget *food_manager)
    {
        if (food_manager->objectName().isEmpty())
            food_manager->setObjectName("food_manager");
        food_manager->resize(750, 600);
        verticalLayoutWidget = new QWidget(food_manager);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 30, 571, 551));
        gridLayout = new QGridLayout(verticalLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 2, 0, 1, 1);


        retranslateUi(food_manager);

        QMetaObject::connectSlotsByName(food_manager);
    } // setupUi

    void retranslateUi(QWidget *food_manager)
    {
        food_manager->setWindowTitle(QCoreApplication::translate("food_manager", "Form", nullptr));
        label->setText(QCoreApplication::translate("food_manager", "\351\243\237\347\211\251\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("food_manager", "\346\267\273\345\212\240\351\243\237\347\211\251", nullptr));
        pushButton_2->setText(QCoreApplication::translate("food_manager", "\346\233\264\346\226\260\351\243\237\347\211\251", nullptr));
        pushButton_3->setText(QCoreApplication::translate("food_manager", "\345\210\240\351\231\244\351\243\237\347\211\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class food_manager: public Ui_food_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOOD_MANAGER_H
