/********************************************************************************
** Form generated from reading UI file 'menubrowser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUBROWSER_H
#define UI_MENUBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuBrowser
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *MenuBrowser)
    {
        if (MenuBrowser->objectName().isEmpty())
            MenuBrowser->setObjectName("MenuBrowser");
        MenuBrowser->resize(600, 600);
        verticalLayoutWidget = new QWidget(MenuBrowser);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 601, 604));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 0, 10, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\261\211\344\273\252\350\217\261\345\277\203\344\275\223\347\256\200")});
        font.setPointSize(10);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(verticalLayoutWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(580, 570));
        page = new QWidget();
        page->setObjectName("page");
        sizePolicy.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        sizePolicy.setHeightForWidth(page_2->sizePolicy().hasHeightForWidth());
        page_2->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(MenuBrowser);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuBrowser);
    } // setupUi

    void retranslateUi(QWidget *MenuBrowser)
    {
        MenuBrowser->setWindowTitle(QCoreApplication::translate("MenuBrowser", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MenuBrowser", "\345\215\225\345\223\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MenuBrowser", "\345\245\227\351\244\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuBrowser: public Ui_MenuBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBROWSER_H
