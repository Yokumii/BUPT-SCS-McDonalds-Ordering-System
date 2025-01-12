/********************************************************************************
** Form generated from reading UI file 'order_manager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_MANAGER_H
#define UI_ORDER_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_order_manager
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;

    void setupUi(QWidget *order_manager)
    {
        if (order_manager->objectName().isEmpty())
            order_manager->setObjectName("order_manager");
        order_manager->resize(750, 600);
        verticalLayoutWidget = new QWidget(order_manager);
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

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(order_manager);

        QMetaObject::connectSlotsByName(order_manager);
    } // setupUi

    void retranslateUi(QWidget *order_manager)
    {
        order_manager->setWindowTitle(QCoreApplication::translate("order_manager", "Form", nullptr));
        label->setText(QCoreApplication::translate("order_manager", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class order_manager: public Ui_order_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_MANAGER_H
