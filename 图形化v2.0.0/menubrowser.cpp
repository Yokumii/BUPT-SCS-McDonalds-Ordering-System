#include "customer.h"
#include "menubrowser.h"
#include "ui_menubrowser.h"
#include <QVBoxLayout>
#include <QListWidgetItem>

MenuBrowser::MenuBrowser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MenuBrowser)
{
    ui->setupUi(this);
    while (ui->stackedWidget->count() > 0) {
        QWidget* widget = ui->stackedWidget->widget(0);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
    ui->stackedWidget->setMinimumSize(580,570);
    FoodWidget = new QListWidget();
    PackWidget = new QListWidget();
    FoodWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    PackWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    FoodWidget->setStyleSheet(
        "QListWidget {"
        "   border: 3px solid orange;"
        "   background-color: rgba(211, 211, 211, 100);"
        "   font: 14pt Arial;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: transparent;"
        "   border: 2px solid blue;"
        "   color: white;"
        "}"
        "QListWidget::item:hover {"
        "   background-color: transparent;"
        "   border: 2px solid yellow;"
        "}"
        "QScrollBar:vertical {"
        "   border: 2px solid yellow;"
        "   background-color: lightyellow;"
        "}"
        );
    PackWidget->setStyleSheet(
        "QListWidget {"
        "   border: 3px solid orange;"
        "   background-color: rgba(211, 211, 211, 100);"
        "   font: 14pt Arial;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: transparent;"
        "   border: 2px solid blue;"
        "   color: white;"
        "}"
        "QListWidget::item:hover {"
        "   background-color: transparent;"
        "   border: 2px solid yellow;"
        "}"
        "QScrollBar:vertical {"
        "   border: 2px solid yellow;"
        "   background-color: lightyellow;"
        "}"
        );

    QSqlQuery query1("SELECT FoodID, FoodName, FoodImage, FoodDescription FROM food");
    while (query1.next()) {
        int id = query1.value(0).toInt();
        QString name = query1.value(1).toString();
        QString imagePath = query1.value(2).toString();
        QString description = query1.value(3).toString();
        AddFoodItem(id, 0, name, imagePath, description);
    }

    QSqlQuery query2("SELECT PackID, PackName, PackImage, PackInclude FROM pack");
    while (query2.next()) {
        int id = query2.value(0).toInt();
        QString name = query2.value(1).toString();
        QString imagePath = query2.value(2).toString();
        QString description = "该套餐包括：" + query2.value(3).toString();
        AddPackItem(id, 1, name, imagePath, description);
    }

    ui->stackedWidget->addWidget(FoodWidget);
    ui->stackedWidget->addWidget(PackWidget);
    ui->stackedWidget->setCurrentIndex(0);

    ui->pushButton->setFixedSize(80, 30);
    ui->pushButton->setStyleSheet("QPushButton { border: 2px solid #fff700; padding: 5px; font: bold 10px; color: white; background-color: #ffa958; }");
    ui->pushButton_2->setFixedSize(80, 30);
    ui->pushButton_2->setStyleSheet("QPushButton { border: 2px solid #fff700; padding: 5px; font: bold 10px; color: white; background-color: #ffa958; }");
    connect(ui->pushButton, &QPushButton::clicked, this, &MenuBrowser::ClickFood);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MenuBrowser::ClickPack);

}

MenuBrowser::~MenuBrowser()
{
    delete ui;
}

void MenuBrowser::AddFoodItem(const int &id, const int &type, const QString &name, const QString &imagePath, const QString &description)
{
    FoodItem *itemWidget = new FoodItem(id, type, name, imagePath, description);
    QListWidgetItem *listItem = new QListWidgetItem(FoodWidget);
    listItem->setSizeHint(itemWidget->sizeHint());
    FoodWidget->addItem(listItem);
    FoodWidget->setItemWidget(listItem, itemWidget);
}

void MenuBrowser::AddPackItem(const int &id, const int &type, const QString &name, const QString &imagePath, const QString &description)
{
    FoodItem *itemWidget = new FoodItem(id, type, name, imagePath, description);
    QListWidgetItem *listItem = new QListWidgetItem(PackWidget);
    listItem->setSizeHint(itemWidget->sizeHint());
    PackWidget->addItem(listItem);
    PackWidget->setItemWidget(listItem, itemWidget);
}

void MenuBrowser::ClickFood()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MenuBrowser::ClickPack()
{
    ui->stackedWidget->setCurrentIndex(1);
}
