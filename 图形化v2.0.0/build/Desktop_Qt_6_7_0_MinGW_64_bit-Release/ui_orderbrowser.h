/********************************************************************************
** Form generated from reading UI file 'orderbrowser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERBROWSER_H
#define UI_ORDERBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orderbrowser
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTableWidget *orderWidget;

    void setupUi(QWidget *orderbrowser)
    {
        if (orderbrowser->objectName().isEmpty())
            orderbrowser->setObjectName("orderbrowser");
        orderbrowser->resize(600, 600);
        verticalLayoutWidget = new QWidget(orderbrowser);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 601, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 5, 10, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\224\220\345\255\227\351\200\274\346\240\274\351\235\222\346\230\245\344\275\223\347\256\2002.0")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        orderWidget = new QTableWidget(verticalLayoutWidget);
        orderWidget->setObjectName("orderWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(orderWidget->sizePolicy().hasHeightForWidth());
        orderWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(orderWidget);


        retranslateUi(orderbrowser);

        QMetaObject::connectSlotsByName(orderbrowser);
    } // setupUi

    void retranslateUi(QWidget *orderbrowser)
    {
        orderbrowser->setWindowTitle(QCoreApplication::translate("orderbrowser", "Form", nullptr));
        label->setText(QCoreApplication::translate("orderbrowser", "\350\256\242\345\215\225\346\265\217\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderbrowser: public Ui_orderbrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERBROWSER_H
