#include "orderbrowser.h"
#include "ui_orderbrowser.h"

orderbrowser::orderbrowser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::orderbrowser)
{
    ui->setupUi(this);

    ui->orderWidget->setColumnCount(5);

    QStringList headers = {"订单编号", "订单名称", "下单时间", "订单状态", "完成时间"};
    ui->orderWidget->setHorizontalHeaderLabels(headers);
    ui->orderWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->orderWidget->setColumnWidth(0, 60);  // 订单编号
    ui->orderWidget->setColumnWidth(1, 140); // 订单名称
    ui->orderWidget->setColumnWidth(2, 90); // 下单时间
    ui->orderWidget->setColumnWidth(3, 170); // 订单状态
    ui->orderWidget->setColumnWidth(4, 90); // 完成时间

    ui->orderWidget->setStyleSheet(
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

    connect(timer, &QTimer::timeout, this, &orderbrowser::updateorder);

    timer->start(3);

}

orderbrowser::~orderbrowser()
{
    delete ui;
}

void orderbrowser::updateorder()
{
    ui->orderWidget->setRowCount(0);
    int row = 0;
    for (Order order : orders) {
        ui->orderWidget->insertRow(row);
        int id = order.id;
        QString idStr = QString("%1").arg(id+1, 5, 10, QLatin1Char('0'));
        QString name = order.name;
        int bsecs = order.bsecs;
        int state = order.state;
        int esecs = order.esecs;
        QString bsecsStr = secsToHMS(bsecs);
        QString esecsStr = (state == 1) ? secsToHMS(esecs) : "/";

        QString stateStr;
        switch (state) {
        case -1: stateStr = "下单失败"; break;
        case 0: stateStr = "订单制作中，请耐心等待"; break;
        case 1: stateStr = "订单已完成，请及时取餐"; break;
        }

        ui->orderWidget->setItem(row, 0, new QTableWidgetItem(idStr));
        ui->orderWidget->setItem(row, 1, new QTableWidgetItem(name));
        ui->orderWidget->setItem(row, 2, new QTableWidgetItem(bsecsStr));
        ui->orderWidget->setItem(row, 3, new QTableWidgetItem(stateStr));
        ui->orderWidget->setItem(row, 4, new QTableWidgetItem(esecsStr));
        row++;
    }
}

QString orderbrowser::secsToHMS(int totalSeconds) {
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;
    return QString("%1:%2:%3")
        .arg(hours, 2, 10, QLatin1Char('0'))
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}
