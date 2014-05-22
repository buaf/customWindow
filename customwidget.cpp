#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QApplication>
#include <QStyle>


#include "customwidget.h"

#include "Utils/utils.h"

CustomWidget::CustomWidget(QWidget * root) :
    QWidget(root)
{
    initUi();
    _root = root;
}

void CustomWidget::initUi()
{
    _currentUsagesTextFont = Utils::loadFont(":/font/Assets/font/AlternateGotNo3D.ttf", 10);
    _currentText = tr("USE SLIDER TO SWITCH WINDOW STATES");
    _currentStateTextFont = Utils::loadFont(":/font/Assets/font/AlternateGotNo3D.ttf", 20);

    setMinimumWidth(700);
    setMinimumHeight(500);

    connect(&_refreshTimer, SIGNAL(timeout()), SLOT(refresh()));
    connect(&_slideProcessTimer, SIGNAL(timeout()), SLOT(slideButtonProcess()));
    connect(this, SIGNAL(changeWindowStyle(bool)), SLOT(changeStyle(bool)));

    move(Utils::getCenterPos(width(), height()));
}

void CustomWidget::addRefreshCount(int count)
{
    _refreshCount += count;
    if (!_refreshTimer.isActive())
    {
        _refreshTimer.start(10);
    }
}

void CustomWidget::mousePressEvent(QMouseEvent * event)
{
    if (checkMouseHitToButton(event->pos()))
    {
        _slideProcessTimer.start(2);
    }
}

bool CustomWidget::checkMouseHitToButton(QPoint point)
{
    if ((point.x() > _backgroundRect.x() && point.x() < _backgroundRect.x() + _backgroundRect.width()) &&
            (point.y() > _backgroundRect.y() && point.y() < _backgroundRect.y() + _backgroundRect.height()))
    {
        return true;
    }

    return false;
}

void CustomWidget::resizeEvent(QResizeEvent * event)
{   
    addRefreshCount(5);    
}


void CustomWidget::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);

    if (!_slideProcessTimer.isActive())
    {
        if (_isNewStyle)
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

    resizeBackground();
    painter.drawRoundedRect(_backgroundRect, 120, 120);

    resizeButtonSlider();
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(_buttonSlider);


    if (!_slideProcessTimer.isActive())
    {
        painter.setFont(_currentStateTextFont);

        if (_isNewStyle)
        {
            QRect onRect = _backgroundRect;
            onRect.setX(onRect.x() - (onRect.width() * 0.5));
            painter.drawText(onRect, Qt::AlignCenter, "ON");
        }
        else
        {
            QRect offRect = _backgroundRect;
            offRect.setX(offRect.x() + (offRect.width() * 0.5));
            painter.drawText(offRect, Qt::AlignCenter, "OFF");
        }
    }

    painter.setPen(Qt::gray);
    painter.setFont(_currentUsagesTextFont);
    painter.drawText(width() / 2 - 150, height() - (height() / 10), 300, 50, Qt::AlignHCenter, _currentText);
}

void CustomWidget::resizeButtonSlider()
{
    _buttonSlider.setWidth(height() / 2.2);
    _buttonSlider.setHeight(height() / 2.2);

    int indent = (_backgroundRect.height() - _buttonSlider.height()) / 2;
    _minSliderX = _backgroundRect.x() + indent;
    _maxSliderX = (_backgroundRect.x() + (_backgroundRect.width() - _buttonSlider.width())) - indent;

    if (!_slideProcessTimer.isActive())
    {
        if (_isNewStyle)
        {
            _buttonSlider.setX(_maxSliderX);
        }
        else
        {
            _buttonSlider.setX(_minSliderX);
        }
        _currentSliderX = 0;
    }
    else
    {
        if (_currentSliderX != 0)
        {
            _buttonSlider.setX(_currentSliderX);
        }
    }

    _buttonSlider.setY((height() - _buttonSlider.height()) / 2);
}

void CustomWidget::resizeBackground()
{
    _backgroundRect.setWidth(width() / 1.5);
    _backgroundRect.setHeight(height() / 2);

    _backgroundRect.setX((width() - _backgroundRect.width()) / 2);
    _backgroundRect.setY(_backgroundRect.height() - _backgroundRect.height() / 2);
}

void CustomWidget::changeStyle(bool isNewStyle)
{
    if (isNewStyle)
    {
        _root->setWindowTitle("Custom Window");
        _root->setWindowFlags(Qt::Window | Qt::FramelessWindowHint  | Qt::WindowStaysOnTopHint );
    }
    else
    {
        _root->setWindowTitle("Standart Window");
        _root->setWindowFlags(Qt::Window);
        _root->setWindowIcon(QIcon());
    }

    _root->show();
    emit hideFrame(!isNewStyle);
}

void CustomWidget::slideButtonProcess()
{
    addRefreshCount(1);

    if (_currentSliderX == 0)
    {
        if (_isNewStyle)
        {
            _currentSliderX = _maxSliderX;
        }
        else
        {
            _currentSliderX = _minSliderX;
        }
    }

    int pixelPerFrame = width() / 350;
    if (pixelPerFrame < 1)
    {
        pixelPerFrame = 1;
    }

    if (_isNewStyle)
    {
        if ((_currentSliderX -= pixelPerFrame) <= _minSliderX)
        {
            _slideProcessTimer.stop();
            _isNewStyle = !_isNewStyle;
            emit changeStyle(_isNewStyle);
        }
    }
    else
    {
        if ((_currentSliderX += pixelPerFrame) >= _maxSliderX)
        {
            _slideProcessTimer.stop();
            _isNewStyle = !_isNewStyle;
            emit changeStyle(_isNewStyle);
        }
    }
}

void CustomWidget::refresh()
{
    if (--_refreshCount < 1)
    {
        _refreshTimer.stop();
    }
    else
    {
        update();
    }
}

void CustomWidget::resizeToDefault()
{
    resize(700, 500);
}
