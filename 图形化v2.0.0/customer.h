#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QPaintEvent>
#include <QPropertyAnimation>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QtSql>
#include <QMovie>
#include <QMessageBox>
#include "ui_menubrowser.h"
#include "menubrowser.h"
#include "ui_orderbrowser.h"
#include "orderbrowser.h"
#include "ui_foodbrowser.h"
#include "foodbrowser.h"
#include "global.h"

class NavigationBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QRect sliderRect READ getSliderRect WRITE setSliderRect)

public:
    explicit NavigationBar(QWidget *parent = nullptr);
    void setTitle(const QStringList &list);

    const QRect &getSliderRect() const;
    void setSliderRect(const QRect &newSliderRect);


signals:
    void currIndexChange(int currIndex);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    QSize sizeHint() const override;

private:
    void updateEachArea();

    QStringList titleList;
    QList<int> widthOfEachAreaList;
    QList<QRect> eachAreaList;
    QRect sliderRect;
    int currIndex{0};
    QPropertyAnimation *animationSliderRect{nullptr};
    QLinearGradient linearGradient;
};

namespace Ui {
class Customer;
}

class Customer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Customer(QMainWindow *parent = nullptr);
    ~Customer();

private slots:
    void UpdateClock();
    void AdjustTimeSpeed(int speed);

private:
    Ui::Customer *ui;
    QStackedLayout *stackedLayout;
    NavigationBar *navBar;

    //时钟相关变量
    QTimer *McTimer;
    QLabel *clockLabel;
    QTime CurrentTime;
    void UpdateTimerInterval();

    //读取食物和套餐并缓存
    void ReadDateFromSql();
    int findFoodIdByName(const QString &name);

    void InitSystem();

    void MakeFood();

    QString secsToHMS(int totalSeconds);

    void OutputOrder();
    void OutWork();

};

#endif // CUSTOMER_H
