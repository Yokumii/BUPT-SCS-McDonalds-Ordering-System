#include "foodbrowser.h"
#include "ui_foodbrowser.h"

FoodBrowser::FoodBrowser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FoodBrowser)
{
    ui->setupUi(this);

    ui->foodWidget->setColumnCount(5);
    ui->foodWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList headers = {"食物序号", "食物名称", "食物指定容量", "食物当前数量", "距离完成下一个所需时间"};
    ui->foodWidget->setHorizontalHeaderLabels(headers);

    ui->foodWidget->setColumnWidth(0, 60);
    ui->foodWidget->setColumnWidth(1, 140);
    ui->foodWidget->setColumnWidth(2, 100);
    ui->foodWidget->setColumnWidth(3, 100);
    ui->foodWidget->setColumnWidth(4, 140);

    ui->foodWidget->setStyleSheet(
        "QTableWidget {"
        "   border: 2px solid yellow;"
        "   background-color: rgba(211, 211, 211, 150);"
        "   font: 9pt Times New Roman;"
        "   gridline-color: orange;"
        "}"
        "QHeaderView::section {"
        "   background-color: orange;"
        "   color: white;"
        "   padding: 4px;"
        "   border: 1px solid yellow;"
        "   font: bold 9pt;"
        "}"
        );

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &FoodBrowser::updatefood);
    timer->start(3);
}

FoodBrowser::~FoodBrowser()
{
    delete ui;
}

void FoodBrowser::updatefood()
{
    ui->foodWidget->setRowCount(0);
    int row = 0;
    for (Food food : foods) {
        ui->foodWidget->insertRow(row);
        int id = food.id;
        QString idStr = QString("%1").arg(id, 5, 10, QLatin1Char('0'));
        QString name = food.name;
        int cap = food.cap;
        int num = food.nowNum;
        int sec = food.clocks;

        ui->foodWidget->setItem(row, 0, new QTableWidgetItem(idStr));
        ui->foodWidget->setItem(row, 1, new QTableWidgetItem(name));
        ui->foodWidget->setItem(row, 2, new QTableWidgetItem(QString::number(cap)));
        ui->foodWidget->setItem(row, 3, new QTableWidgetItem(QString::number(num)));
        ui->foodWidget->setItem(row, 4, new QTableWidgetItem(QString::number(sec)));
        row++;
    }
}
