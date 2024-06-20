/********************************************************************************
** Form generated from reading UI file 'foodbrowser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOODBROWSER_H
#define UI_FOODBROWSER_H

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

class Ui_FoodBrowser
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTableWidget *foodWidget;

    void setupUi(QWidget *FoodBrowser)
    {
        if (FoodBrowser->objectName().isEmpty())
            FoodBrowser->setObjectName("FoodBrowser");
        FoodBrowser->resize(600, 600);
        verticalLayoutWidget = new QWidget(FoodBrowser);
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
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        foodWidget = new QTableWidget(verticalLayoutWidget);
        foodWidget->setObjectName("foodWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(foodWidget->sizePolicy().hasHeightForWidth());
        foodWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(foodWidget);


        retranslateUi(FoodBrowser);

        QMetaObject::connectSlotsByName(FoodBrowser);
    } // setupUi

    void retranslateUi(QWidget *FoodBrowser)
    {
        FoodBrowser->setWindowTitle(QCoreApplication::translate("FoodBrowser", "Form", nullptr));
        label->setText(QCoreApplication::translate("FoodBrowser", "\351\243\237\347\211\251\345\256\236\346\227\266\345\244\247\345\261\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FoodBrowser: public Ui_FoodBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOODBROWSER_H
