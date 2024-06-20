/********************************************************************************
** Form generated from reading UI file 'customer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_H
#define UI_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Customer
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *MainWindow;
    QWidget *contentWidget;
    QWidget *navBar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *SystemTime;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *SpeedLabel;
    QSlider *SpeedSlider;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Customer)
    {
        if (Customer->objectName().isEmpty())
            Customer->setObjectName("Customer");
        Customer->resize(600, 800);
        centralwidget = new QWidget(Customer);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 100, 602, 822));
        MainWindow = new QVBoxLayout(verticalLayoutWidget);
        MainWindow->setSpacing(0);
        MainWindow->setObjectName("MainWindow");
        MainWindow->setContentsMargins(0, 0, 0, 0);
        contentWidget = new QWidget(verticalLayoutWidget);
        contentWidget->setObjectName("contentWidget");
        contentWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentWidget->sizePolicy().hasHeightForWidth());
        contentWidget->setSizePolicy(sizePolicy);
        contentWidget->setMinimumSize(QSize(600, 600));
        contentWidget->setMaximumSize(QSize(600, 600));

        MainWindow->addWidget(contentWidget);

        navBar = new QWidget(verticalLayoutWidget);
        navBar->setObjectName("navBar");
        sizePolicy.setHeightForWidth(navBar->sizePolicy().hasHeightForWidth());
        navBar->setSizePolicy(sizePolicy);
        navBar->setMinimumSize(QSize(600, 220));
        navBar->setMaximumSize(QSize(600, 200));

        MainWindow->addWidget(navBar);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 602, 114));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\224\220\345\255\227\351\200\274\346\240\274\351\235\222\346\230\245\344\275\223\347\256\2002.0")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        SystemTime = new QLCDNumber(horizontalLayoutWidget);
        SystemTime->setObjectName("SystemTime");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SystemTime->sizePolicy().hasHeightForWidth());
        SystemTime->setSizePolicy(sizePolicy2);
        SystemTime->setMinimumSize(QSize(120, 40));
        SystemTime->setMaximumSize(QSize(120, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(15);
        font1.setBold(true);
        SystemTime->setFont(font1);
        SystemTime->setLayoutDirection(Qt::LeftToRight);
        SystemTime->setFrameShape(QFrame::Box);
        SystemTime->setFrameShadow(QFrame::Raised);
        SystemTime->setLineWidth(2);
        SystemTime->setMidLineWidth(2);
        SystemTime->setSmallDecimalPoint(false);
        SystemTime->setDigitCount(8);

        verticalLayout_2->addWidget(SystemTime);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(120, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\224\220\345\255\227\351\200\274\346\240\274\351\235\222\346\230\245\344\275\223\347\256\2002.0")});
        font2.setPointSize(10);
        font2.setBold(false);
        label->setFont(font2);
        label->setContextMenuPolicy(Qt::NoContextMenu);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        SpeedLabel = new QLabel(horizontalLayoutWidget);
        SpeedLabel->setObjectName("SpeedLabel");
        sizePolicy.setHeightForWidth(SpeedLabel->sizePolicy().hasHeightForWidth());
        SpeedLabel->setSizePolicy(sizePolicy);
        SpeedLabel->setMinimumSize(QSize(35, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(9);
        SpeedLabel->setFont(font3);
        SpeedLabel->setLayoutDirection(Qt::LeftToRight);
        SpeedLabel->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(SpeedLabel);

        SpeedSlider = new QSlider(horizontalLayoutWidget);
        SpeedSlider->setObjectName("SpeedSlider");
        sizePolicy.setHeightForWidth(SpeedSlider->sizePolicy().hasHeightForWidth());
        SpeedSlider->setSizePolicy(sizePolicy);
        SpeedSlider->setMinimumSize(QSize(80, 20));
        SpeedSlider->setMaximumSize(QSize(120, 50));
        SpeedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(SpeedSlider);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-1, -1, 601, 800));
        Customer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Customer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 25));
        Customer->setMenuBar(menubar);
        statusbar = new QStatusBar(Customer);
        statusbar->setObjectName("statusbar");
        Customer->setStatusBar(statusbar);

        retranslateUi(Customer);

        QMetaObject::connectSlotsByName(Customer);
    } // setupUi

    void retranslateUi(QMainWindow *Customer)
    {
        Customer->setWindowTitle(QCoreApplication::translate("Customer", "\351\272\246\345\275\223\345\212\263\345\234\250\347\272\277\347\202\271\351\244\220\347\263\273\347\273\237For BYR   By Yokumi", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Customer", "\346\254\242\350\277\216\345\205\211\344\270\264\351\272\246\345\275\223\345\212\263\347\202\271\351\244\220\347\263\273\347\273\237\357\274\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Customer", "\344\270\213\347\217\255", nullptr));
        label->setText(QCoreApplication::translate("Customer", "\346\227\266\351\227\264\346\265\201\351\200\235\351\200\237\347\216\207", nullptr));
        SpeedLabel->setText(QCoreApplication::translate("Customer", "300", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Customer: public Ui_Customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
