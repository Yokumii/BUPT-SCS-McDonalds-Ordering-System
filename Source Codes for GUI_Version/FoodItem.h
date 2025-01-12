#ifndef FOODITEM_H
#define FOODITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <Qsqldatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "hoverfillbutton.h"
#include "hoverfillbuttonbase.h"
#include "custombuttonbase.h"

class FoodItem : public QWidget
{
    Q_OBJECT

public:
    explicit FoodItem(const int &id, const int &type, const QString &name, const QString &imagePath, const QString &description, QWidget *parent = nullptr);

private slots:
    void orderButtonClicked();

private:
    int id;
    int type;
    QLabel *nameLabel;
    QLabel *imageLabel;
    QLabel *descriptionLabel;
    HoverFillButton *orderButton;
};

#endif // FOODITEM_H
