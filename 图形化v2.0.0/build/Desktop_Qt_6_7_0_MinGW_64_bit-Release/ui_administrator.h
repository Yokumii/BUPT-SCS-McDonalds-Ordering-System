/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_administrator
{
public:

    void setupUi(QWidget *administrator)
    {
        if (administrator->objectName().isEmpty())
            administrator->setObjectName("administrator");
        administrator->resize(400, 300);

        retranslateUi(administrator);

        QMetaObject::connectSlotsByName(administrator);
    } // setupUi

    void retranslateUi(QWidget *administrator)
    {
        administrator->setWindowTitle(QCoreApplication::translate("administrator", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class administrator: public Ui_administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
