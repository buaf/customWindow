#include <QDebug>
#include <QPainter>
#include <QFontDatabase>
#include <QPen>
#include <QFont>

#include "customtext.h"

#include "Utils/utils.h"

CustomText::CustomText(QWidget *parent) :
    QWidget(parent)
{
    initUi();
}

void CustomText::initUi()
{
    _currentFont = Utils::loadFont(":/font/Assets/font/AlternateGotNo3D.ttf", 15);
}

void CustomText::setText(QString text)
{
    _currentText = text;
    repaint();
}

void CustomText::resizeEvent(QResizeEvent * event)
{
    update();
}

void CustomText::paintEvent(QPaintEvent * event)
{
   /* QPainter painter(this);
    painter.setPen(Qt::gray);
    painter.setFont(_currentFont);
    painter.drawText(rect(), Qt::AlignCenter, _currentText);*/
}

