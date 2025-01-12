#include "custombuttonbase.h"

CustomButtonBase::CustomButtonBase(QWidget *parent)
    : QPushButton(parent)
{
    initializeMemberVariable();
}

CustomButtonBase::CustomButtonBase(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    initializeMemberVariable();
}

CustomButtonBase::CustomButtonBase(const QIcon &icon, const QString &text, QWidget *parent)
    : QPushButton(icon, text, parent)
{
    initializeMemberVariable();
}

void CustomButtonBase::addShadow(int right, int down, qreal blurRadius, const QColor &shadowColor)
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(right, down);
    shadow->setColor(shadowColor);
    shadow->setBlurRadius(blurRadius);
    this->setGraphicsEffect(shadow);
}

void CustomButtonBase::setTextColor(const QColor& normalTextColor, const QColor &hoverTextColor)
{
    hover_text_color = hoverTextColor;
    palette().setColor(QPalette::ButtonText, normalTextColor);
}

QPalette &CustomButtonBase::palette() const
{
    return const_cast<QPalette &>(QPushButton::palette());
}

void CustomButtonBase::refreshRadius(int radius)
{
    this->radius = radius;
    path.clear();
    path.addRoundedRect(rect(), radius, radius);
}

void CustomButtonBase::initializeMemberVariable()
{
    path.addRoundedRect(rect(), radius, radius);
}

void CustomButtonBase::resizeEvent(QResizeEvent *event)
{
    QPushButton::resizeEvent(event);
    path.clear();
    path.addRoundedRect(rect(), radius, radius);
}

void CustomButtonBase::enterEvent(QEnterEvent *event)
{
    QPushButton::enterEvent(event);
    is_cursor_inside = true;
}

void CustomButtonBase::leaveEvent(QEvent *event)
{
    QPushButton::leaveEvent(event);
    is_cursor_inside = false;
}
