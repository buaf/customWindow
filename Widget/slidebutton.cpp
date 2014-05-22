#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QDebug>

#include "slidebutton.h"

#include "Utils/utils.h"

SlideButton::SlideButton(QWidget *parent) :
    QWidget(parent)
{
    initUi();
}

void SlideButton::initUi()
{
    _currentFont = Utils::loadFont(":/font/Assets/font/AlternateGotNo3D.ttf", 22);
}

void SlideButton::resizeUi()
{
/*

    //qDebug() << "SlideButton resize  width:" << windowWidth << "  height:" << windowHeight;

    /*_backgroundRect.setWidth(windowWidth * 0.5);
    _backgroundRect.setHeight(windowHeight * 0.5);
    _backgroundRect.setX((windowWidth * 0.5) - (_backgroundRect.width() * 0.5));
    _backgroundRect.setY((windowHeight * 0.5) - (_backgroundRect.height() * 0.5));

    _minSliderX = (windowWidth * 0.5) - (_backgroundRect.width() * 0.5) + _buttonSlider.width() * 0.1;
    _maxSliderX = (windowWidth * 0.5) - (_backgroundRect.width() * 0.5) + _buttonSlider.width() * 0.1;

    _buttonSlider.setWidth(windowHeight * 0.4);
    _buttonSlider.setHeight(windowHeight * 0.4);
    _buttonSlider.setX(_maxSliderX);
    _buttonSlider.setY((windowHeight * 0.5) - (_buttonSlider.height() * 0.5));*/

}


void SlideButton::resizeEvent(QResizeEvent * event)
{
    update();
}

void SlideButton::paintEvent(QPaintEvent * event)
{
    /*QPainter painter(this);

    resizeUi();

    if (!_slideProcessTimer.isActive())
    {
        if (_isButtonOn)
        {
            _currentBackgroundColor = QColor(146, 220, 92);
        }
        else
        {
            _currentBackgroundColor = QColor(230, 222, 211);
        }
    }
    painter.setPen(_currentBackgroundColor);
    painter.setBrush(_currentBackgroundColor);

    painter.drawRoundedRect(_backgroundRect, 100, 100);

    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(_buttonSlider);


    if (!_slideProcessTimer.isActive())
    {
        if (_isButtonOn)
        {
            painter.setFont(_currentFont);
            QRect onRect = _backgroundRect;
            onRect.setX(onRect.x() - (onRect.width() * 0.5));
            painter.drawText(onRect, Qt::AlignCenter, "ON");
        }
        else
        {
            painter.setFont(_currentFont);
            QRect offRect = _backgroundRect;
            offRect.setX(offRect.x() + (offRect.width() * 0.5));
            painter.drawText(offRect, Qt::AlignCenter, "OFF");
        }
    }*/
}

void SlideButton::mousePressEvent(QMouseEvent * event)
{
    /*if (checkMouseTapToButton(event->pos()))
    {*/
        _isButtonOn = !_isButtonOn;
        if (_slideProcessTimer.isActive())
        {
            _slideProcessTimer.stop();
        }
        //connect (&_slideProcessTimer, SIGNAL(timeout()), SLOT(processSlideButton()));
        _slideProcessTimer.start(0);
    //}
}

bool SlideButton::checkMouseTapToButton(QPoint point)
{
    /*if ((point.x() > _rectX && point.x() < _rectX + _rectWidth) &&
            (point.y() > _rectY && point.y() < _rectY + _rectHeight))
    {
        return true;
    }

    if ((_rectHeight * 0.5) > Utils::calculateLength(QPoint(_centerX - _rectWidth * 0.5, _rectY + _rectHeight * 0.5), point))
    {
        return true;
    }

    if ((_rectHeight * 0.5) > Utils::calculateLength(QPoint(_centerX + _rectWidth * 0.5, _rectY + _rectHeight * 0.5), point))
    {
        return true;
    }*/

    return false;
}

void SlideButton::processSlideButton()
{
    /*if(_isButtonOn)
    {
        if ((++_ellipseXpos) >= _maxEllipseX)
        {
            _slideProcessTimer.stop();
            emit clicked(_isButtonOn);
        }
    }
    else
    {
        if ((++_ellipseXpos) <= _minEllipseX)
        {
            _slideProcessTimer.stop();
            emit clicked(_isButtonOn);
        }
    }*/

    //repaint();
}
