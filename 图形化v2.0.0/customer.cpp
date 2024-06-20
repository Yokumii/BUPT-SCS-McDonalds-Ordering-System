#include "customer.h"
#include "ui_customer.h"
#include <QScreen>

NavigationBar::NavigationBar(QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);

    auto font = this->font();
    font.setPixelSize(22);
    font.setBold(true);
    setFont(font);

    linearGradient.setColorAt(0.0, QColor(0xFFA500)); // 橙色
    linearGradient.setColorAt(1.0, QColor(0xFF8C00)); // 深橙色
}

void NavigationBar::setTitle(const QStringList &list) {
    if (list.isEmpty())
        return;

    titleList = list;
    widthOfEachAreaList.clear();
    int width{0};
    for (const auto &title : titleList) {
        width += 200;
        widthOfEachAreaList << width;
        qDebug() << "Setting title:" << title << "with width:" << width; // 调试输出
    }
    updateEachArea();
    update();
}

void NavigationBar::paintEvent(QPaintEvent *event) {
    const auto drawRect = event->rect();
    const auto drawHeight = drawRect.height();
    QPainter painter(this);
    painter.fillRect(drawRect.adjusted(0, 10, 0, -10), QColor(0xFFFFFF));
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(QColor(0xDDDDDD), 2));
    for (int i = 0; i < widthOfEachAreaList.size(); ++i) {
        painter.drawLine(QPoint(widthOfEachAreaList.at(i), 12), QPoint(widthOfEachAreaList.at(i), drawHeight - 12));
    }

    linearGradient.setStart(sliderRect.topLeft());
    linearGradient.setFinalStop(sliderRect.bottomLeft());
    painter.setBrush(linearGradient);
    painter.drawRoundedRect(sliderRect, 6, 6);

    QFont font = this->font();
    painter.setFont(font);
    painter.setPen(Qt::black);
    for (int i = 0; i < eachAreaList.size(); ++i) {
        painter.drawText(eachAreaList.at(i), Qt::AlignCenter, titleList.at(i));
    }
}

QSize NavigationBar::sizeHint() const {
    int width{0};
    for (const auto &title : titleList) {
        width += 200;
    }
    return QSize(width, 50);
}

void NavigationBar::resizeEvent(QResizeEvent *event) {
    updateEachArea();
    QWidget::resizeEvent(event);
}

void NavigationBar::mouseMoveEvent(QMouseEvent *event) {
    auto nowPos = event->pos();
    int lastIndex = currIndex;
    for (int i = 0; i < widthOfEachAreaList.size(); ++i) {
        if (eachAreaList.at(i).contains(nowPos)) {
            currIndex = i;
            break;
        }
    }
    if (lastIndex != currIndex) {
        if (animationSliderRect) {
            animationSliderRect->stop();
        } else {
            animationSliderRect = new QPropertyAnimation(this, "sliderRect");
        }
        animationSliderRect->setStartValue(sliderRect);
        animationSliderRect->setEndValue(eachAreaList.at(currIndex));
        animationSliderRect->setDuration(200);
        emit currIndexChange(currIndex);
        connect(animationSliderRect, &QPropertyAnimation::valueChanged, this, QOverload<>::of(&QWidget::update));
        animationSliderRect->start();
    }
    QWidget::mouseMoveEvent(event);
}

void NavigationBar::updateEachArea() {
    eachAreaList.clear();
    auto height = this->height();
    for (int i = 0; i < widthOfEachAreaList.size(); ++i) {
        QRect rect{i == 0 ? 0 : widthOfEachAreaList.at(i - 1),
                   0,
                   i == 0 ? widthOfEachAreaList.at(i) : widthOfEachAreaList.at(i) - widthOfEachAreaList.at(i - 1),
                   height};
        qDebug() << "Adding area:" << rect; // 调试输出
        eachAreaList << rect;
    }
    sliderRect = eachAreaList.first();
    currIndex = 0;
    emit currIndexChange(currIndex);
}

const QRect &NavigationBar::getSliderRect() const {
    return sliderRect;
}

void NavigationBar::setSliderRect(const QRect &newSliderRect) {
    sliderRect = newSliderRect;
}

Customer::Customer(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::Customer)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // 计算窗口应该移动到的位置
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    // 将窗口移动到屏幕中心
    move(x, y);

    ui->widget->setStyleSheet("background-image: url(:/ui_icon/background.png);");
    ui->widget->lower();

    ui->label_2->setScaledContents(true);
    QMovie *movie = new QMovie(":/anime/anime.gif");
    movie->setCacheMode(QMovie::CacheAll); // 提高性能
    movie->start(); // 启动播放
    ui->label_2->setMovie(movie);

    ui->SystemTime->setStyleSheet(
        "QLCDNumber {"
        "   background-color: rgba(211, 211, 211, 150);"
        "   color: black;"
        "   border: 2px solid orange;"
        "   border-radius: 5px;"
        "}"
        );

    //读取数据
    ReadDateFromSql();

    InitSystem();
    //时钟相关初始化
    McTimer = new QTimer(this);
    clockLabel = new QLabel(this);
    ui->SpeedSlider->setRange(1, 300);
    ui->SpeedSlider->setValue(1);
    CurrentTime = QTime(6, 59, 59); // 设置初始时间为7:00:00
    mcsystem.nowsecs = START_SECS - 1;
    connect(McTimer, &QTimer::timeout, this, &Customer::UpdateClock);
    connect(ui->SpeedSlider, &QSlider::valueChanged, this, &Customer::AdjustTimeSpeed);
    ui->SpeedLabel->setText(QString("%1").arg(mcsystem.TimeMultiplier));
    UpdateTimerInterval();  // 设置初始计时器间隔
    McTimer->start();

    // Create navigation bar and set titles
    NavigationBar * navBar = new NavigationBar;
    navBar->setTitle(QStringList() << "菜单目录" << "订单浏览" << "食物大屏");

    // Create stacked layout for content pages
    MenuBrowser * menuBrowser = new MenuBrowser;
    orderbrowser * orderBrowser = new orderbrowser;
    FoodBrowser * foodBrowser = new FoodBrowser;

    stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(menuBrowser);
    stackedLayout->addWidget(orderBrowser);
    stackedLayout->addWidget(foodBrowser);

    // Add navBar and stackedLayout to the existing placeholders
    ui->navBar->setLayout(new QVBoxLayout());
    ui->navBar->layout()->addWidget(navBar);

    ui->contentWidget->setLayout(stackedLayout);
    ui->contentWidget->setAttribute(Qt::WA_TranslucentBackground);
    ui->navBar->setAttribute(Qt::WA_TranslucentBackground);

    ui->pushButton->setFixedSize(80,30);
    ui->pushButton->setStyleSheet("QPushButton { border: 2px solid #fff700; border-radius: 6px; padding: 5px; font: bold 14px; color: white; background-color: #ffa958; }");
    connect(ui->pushButton, &QPushButton::clicked, this, &Customer::OutWork);

    connect(navBar, &NavigationBar::currIndexChange, this, [this](int currIndex) {
        stackedLayout->setCurrentIndex(currIndex);
    });
}

Customer::~Customer()
{
    delete ui;
}

void Customer::UpdateClock()
{
    if (isUpdatingClock) return;  // 如果正在更新，直接返回
    isUpdatingClock = true;       // 设置标志位，表示正在更新

    mcsystem.nowsecs++;
    CurrentTime = CurrentTime.addSecs(1);
    ui->SystemTime->display(CurrentTime.toString("hh:mm:ss"));
    if (mcsystem.nowsecs > 79200)
        mcsystem.IsLocked = 1;

    MakeFood();
    if (mcsystem.UnfinishNum == 0 && mcsystem.nowsecs > 79200 || mcsystem.nowsecs > 86400)
    {
        OutputOrder();
        QMessageBox::information(this,"系统关闭","所有订单都完成啦，系统休息了哦！",QMessageBox::Yes);
        QCoreApplication::exit(0);
    }
    if (mcsystem.UnfinishNum > mcsystem.W_1 && mcsystem.IsLocked == 0)
        mcsystem.IsLocked = 1;
    if (mcsystem.UnfinishNum < mcsystem.W_2 && mcsystem.IsLocked == 1 && mcsystem.nowsecs <= 79200)
        mcsystem.IsLocked = 0;

    isUpdatingClock = false;  // 更新完成，清除标志位
}


void Customer::AdjustTimeSpeed(int speed) {
    mcsystem.TimeMultiplier = speed;
    ui->SpeedLabel->setText(QString("%1").arg(mcsystem.TimeMultiplier));
    UpdateTimerInterval();  // 更新计时器间隔
}

void Customer::UpdateTimerInterval() {
    // 根据时间流逝速率调整计时器间隔（1~300，例：10倍率表示1秒相当于10秒）
    McTimer->setInterval(static_cast<int>(1000.0 / mcsystem.TimeMultiplier));
}

void Customer::ReadDateFromSql()
{
    QSqlQuery query;

    // Load foods
    query.exec("SELECT FoodID, FoodName, FoodMakeSec, FoodCap FROM food");
    while (query.next()) {
        Food food;
        food.id = query.value(0).toInt();
        food.name = query.value(1).toString();
        food.makeSecs = query.value(2).toInt();
        food.cap = query.value(3).toInt();
        food.nowNum = 0;
        food.clocks = -1;
        food.head = 0;
        food.tail = 0;
        memset(food.order, -1, sizeof(food.order));
        foods.append(food);
    }

    // Load packs
    query.exec("SELECT PackID, PackName, PackInclude FROM pack");
    while (query.next()) {
        Pack pack;
        pack.id = query.value(0).toInt();
        pack.name = query.value(1).toString();
        pack.num = 0;
        QJsonDocument doc = QJsonDocument::fromJson(query.value(2).toByteArray());
        QJsonArray foodArray = doc.array();
        for (const QJsonValue &value : foodArray) {
            QString foodName = value.toString();
            int foodId = findFoodIdByName(foodName);
            if (foodId != -1) {
                pack.foodIds.append(foodId);
            }
            pack.num++;
        }
        packs.append(pack);
    }
}

int Customer::findFoodIdByName(const QString &name)
{
    for (const Food &food : foods) {
        if (food.name == name) {
            return food.id;
        }
    }
    return -1; // Not found
}

void Customer::InitSystem()
{
    mcsystem.IsLocked = 0;
    mcsystem.NextOrder = 0;
    mcsystem.UnfinishNum = 0;
    mcsystem.TimeMultiplier = 1;
    QSqlQuery query;
    query.exec("SELECT W_1,W_2 FROM setting");
    while (query.next()) {
        mcsystem.W_1 = query.value(0).toInt();
        mcsystem.W_2 = query.value(1).toInt();
    }
}

void Customer::MakeFood()
{
    for (int i = 0; i < foods.size(); ++i) {
        Food &food = foods[i];
        // 如果食物正在制作中，更新制作时间
        if (food.clocks > 0) {
            food.clocks--;
        }
        if (food.clocks == 0) {
            food.nowNum++;
            food.clocks = -1;
        }
    }
    while (isGetOrder)
    {
        continue;
    }
    isDividing = true;
    for (int i = 0; i < foods.size(); ++i){
        Food &food = foods[i];
        int ptr = food.head;
        while (food.nowNum > 0 && ptr != food.tail) {
            food.nowNum--;
            orders[food.order[ptr]].num--;
            if (orders[food.order[ptr]].num == 0 ) {
                orders[food.order[ptr]].state = 1;
                orders[food.order[ptr]].esecs = mcsystem.nowsecs;
                mcsystem.UnfinishNum--;
                QMessageBox::information(this,"完成提示","订单"+QString("%1").arg(food.order[ptr]+1, 5, 10, QLatin1Char('0'))+"制作完成，请及时取餐哦！",QMessageBox::Yes);
            }
            food.order[ptr] = -1;
            ptr = (ptr + 1) % MAX_DOING;
            food.head = ptr;
        }
        if (food.nowNum < food.cap && food.clocks == -1) {
            food.clocks = food.makeSecs;
        }
    }
    isDividing = false;
}

QString Customer::secsToHMS(int totalSeconds) {
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;
    return QString("%1:%2:%3")
        .arg(hours, 2, 10, QLatin1Char('0'))
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}

void Customer::OutputOrder()
{
    std::ofstream outputFile("output.txt");
    outputFile << "订单序号" << " " << "订单名称" << " " << "下单时间" << " " << "状态" << " " << "完成时间" << '\n';
    // 将每个订单的信息输出到文件
    for (const auto& order : orders) {
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
        case -1: stateStr = "失败"; break;
        case 0: stateStr = "制作中"; break;
        case 1: stateStr = "完成"; break;
        }
        outputFile << idStr.toStdString() << " " << name.toStdString() << " " << bsecsStr.toStdString() << " " << stateStr.toStdString() << " " << esecsStr.toStdString() << '\n';
    }

    // 关闭文件
    outputFile.close();
}

void Customer::OutWork()
{
    if (mcsystem.UnfinishNum != 0 )
    {
        QMessageBox::warning(this,"系统提示","当前仍有订单未完成，不能下班哦！",QMessageBox::Cancel);
    }
    else
    {
        OutputOrder();
        QMessageBox::information(this,"系统关闭","所有订单都完成啦，系统休息了哦！",QMessageBox::Yes);
        QCoreApplication::exit(0);
    }
}
