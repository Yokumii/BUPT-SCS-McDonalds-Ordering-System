#ifndef GLOBAL_H
#define GLOBAL_H

#include <QMainWindow>
#include <QTimer>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSplashScreen>
#include <iostream>
#include <fstream>

#define MAX_ORDERS 54001
#define MAX_DOING 101
#define MAX_FOOD_IN_PACK 5
#define MAX_FOODNAME 50
#define START_SECS 25200

struct Food {
    QString name;
    int id;
    int makeSecs;
    int nowNum;
    int cap;
    int clocks;
    int order[MAX_DOING];
    int head;
    int tail;
};

struct Pack {
    QString name;
    int id;
    int num;
    QVector<int> foodIds;
};

struct Order {
    QString name;
    int id;
    int bsecs;
    int state;
    int esecs;
    int num;
};

struct System
{
    int nowsecs;
    bool IsLocked;
    int W_1;
    int W_2;
    int NextOrder;
    int UnfinishNum;
    int TimeMultiplier;
};

extern QVector<Food> foods;
extern QVector<Pack> packs;
extern QVector<Order> orders;
extern System mcsystem;

extern bool isUpdatingClock;
extern bool isGetOrder;
extern bool isDividing;

#endif // GLOBAL_H
