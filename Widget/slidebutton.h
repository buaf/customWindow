#ifndef SLIDEBUTTON_H
#define SLIDEBUTTON_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QGraphicsItem>

class SlideButton : public QWidget
{
    Q_OBJECT

public:
    SlideButton(QWidget *parent = nullptr);

    void initUi();
    void resizeUi();


    void resizeEvent(QResizeEvent * event);
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);
    bool checkMouseTapToButton(QPoint point);



signals:
    void clicked(bool buttonStatus);

public slots:
    void processSlideButton();

private:
    QTimer _slideProcessTimer;
    bool _isButtonOn = false;

    QFont _currentFont;
    QColor _currentBackgroundColor;

    QRect _backgroundRect;
    QRect _buttonSlider;
    int _minSliderX, _currentSliderX, _maxSliderX;

};

#endif // SLIDEBUTTON_H
