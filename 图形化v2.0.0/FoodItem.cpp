#include "FoodItem.h"
#include "global.h"
#include <QPixmap>
#include <QMessageBox>

FoodItem::FoodItem(const int &id, const int &type, const QString &name, const QString &imagePath, const QString &description, QWidget *parent)
    : QWidget(parent),id(id),type(type)
{
    // Change font format for nameLabel
    QFont font;
    font.setStyleName("Times New Roman");
    font.setPointSize(14); // Set font size
    font.setBold(true); // Set font to bold

    QWidget * backgroundWidget;
    backgroundWidget = new QWidget(this);
    backgroundWidget->setStyleSheet("background-image: url(:/ui_icon/panel.png);");
    backgroundWidget->setFixedSize(560,120);
    nameLabel = new QLabel(name, this);
    nameLabel->setFont(font); // Apply the font to nameLabel

    imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap(imagePath));
    imageLabel->setFixedSize(100, 100);
    imageLabel->setScaledContents(true);
    if (!imageLabel->pixmap()) {
        qDebug() << "Image could not be displayed.";
        imageLabel->setPixmap(QPixmap("./food_icon/imageerror.png"));
    } else {
        qDebug() << "Image displayed successfully.";
    }

    descriptionLabel = new QLabel(description, this);
    descriptionLabel->setWordWrap(true);
    descriptionLabel->setFixedWidth(400);
    descriptionLabel->setStyleSheet("QLabel { font-family: Arial; font-size: 12px; }");

    orderButton = new HoverFillButton("下单", this);
    orderButton->setFixedSize(80, 30);
    orderButton->setStyleSheet("QPushButton { border: 2px solid #fff700; border-radius: 6px; padding: 5px; font: bold 14px; color: white; background-color: #ffa958; }");
    orderButton->setAnimationType(HoverFillButton::AnimationType::DiagonalRectangle);

    connect(orderButton, &QPushButton::clicked, this, &FoodItem::orderButtonClicked);

    // Layout for text and button
    QVBoxLayout *textLayout = new QVBoxLayout();
    textLayout->addWidget(nameLabel);
    textLayout->addWidget(descriptionLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QSpacerItem *spacer = new QSpacerItem(300, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);
    buttonLayout->addItem(spacer);
    buttonLayout->addWidget(orderButton);
    textLayout->addLayout(buttonLayout);

    // Main layout
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(imageLabel);
    mainLayout->addLayout(textLayout);

    setLayout(mainLayout);
    backgroundWidget->lower();
}

void FoodItem::orderButtonClicked()
{
    Order order;
    order.id = mcsystem.NextOrder;
    if (type == 0)
    {
        order.name = foods[id].name;
    }
    else
    {
        order.name = packs[id].name;
    }
    if (mcsystem.IsLocked == 1)
    {
        order.state = -1;
        orders.append(order);
        if (mcsystem.nowsecs <= 79200)
            QMessageBox::warning(this,"下单失败","现在订单太多了，排队排到天边了，系统撑不住啦，下单失败啦！❤️",QMessageBox::Cancel);
        else
            QMessageBox::warning(this,"下单失败","嘿，老板已经叫我收工了，明天再来下单吧！大家晚安哦！❤️",QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(this,"下单成功","下单成功了哦，慢慢等吧！💖✨",QMessageBox::Yes);
        isGetOrder = true;
        if (type == 0)
        {
            order.state = 0;
            order.num = 1;
            foods[id].order[foods[id].tail] = order.id;
            foods[id].tail = (foods[id].tail + 1) % MAX_DOING;
        }
        else
        {
            order.state = 0;
            order.num = packs[id].num;
            for (int include : packs[id].foodIds)
            {
                foods[include].order[foods[include].tail] = order.id;
                foods[include].tail = (foods[include].tail + 1) % MAX_DOING;
            }
        }
        while (isDividing)
        {
            continue;
        }
        order.bsecs = mcsystem.nowsecs + 1;
        orders.append(order);
        mcsystem.UnfinishNum++;
    }
    mcsystem.NextOrder++;
    isGetOrder = false;
}
