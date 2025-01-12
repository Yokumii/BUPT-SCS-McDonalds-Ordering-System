#ifndef ORDERBROWSER_H
#define ORDERBROWSER_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTime>
#include <QTimer>
#include <QPushButton>
#include <global.h>

namespace Ui {
class orderbrowser;
}

class orderbrowser : public QWidget
{
    Q_OBJECT

public:
    explicit orderbrowser(QWidget *parent = nullptr);
    ~orderbrowser();

private slots:
    void updateorder();

private:
    Ui::orderbrowser *ui;
    QString secsToHMS(int totalSeconds);
};

#endif // ORDERBROWSER_H
