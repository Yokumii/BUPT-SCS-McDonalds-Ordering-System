#ifndef FOODBROWSER_H
#define FOODBROWSER_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include "global.h"

namespace Ui {
class FoodBrowser;
}

class FoodBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit FoodBrowser(QWidget *parent = nullptr);
    ~FoodBrowser();

private slots:
    void updatefood();

private:
    Ui::FoodBrowser *ui;



};

#endif // FOODBROWSER_H
