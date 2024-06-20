#ifndef MENUBROWSER_H
#define MENUBROWSER_H

#include <QWidget>
#include <QStackedWidget>
#include <QListWidget>
#include "FoodItem.h"

namespace Ui {
class MenuBrowser;
}

class MenuBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBrowser(QWidget *parent = nullptr);
    ~MenuBrowser();
    void ClickFood();
    void ClickPack();

private:
    Ui::MenuBrowser *ui;
    QStackedWidget *stackedWidget;
    QListWidget *listWidget;
    QListWidget *FoodWidget;
    QListWidget *PackWidget;
    void AddFoodItem(const int &id, const int &type, const QString &name, const QString &imagePath, const QString &description);
    void AddPackItem(const int &id, const int &type, const QString &name, const QString &imagePath, const QString &description);
};

#endif // MENUBROWSER_H
