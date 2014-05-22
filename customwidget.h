#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QFont>
#include <QTimer>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget * root = nullptr);
    void initUi();

    void addRefreshCount(int count);

    void mousePressEvent(QMouseEvent * event);
    bool checkMouseHitToButton(QPoint point);

    void resizeEvent(QResizeEvent * event);
    void paintEvent(QPaintEvent * event);
    void resizeButtonSlider();
    void resizeBackground();

signals:
    void changeWindowStyle(bool isNewStyle);
    void hideFrame(bool show);

public slots:
    void changeStyle(bool isNewStyle);
    void slideButtonProcess();
    void refresh();
    void resizeToDefault();

private:
    QWidget * _root;

    QTimer _slideProcessTimer, _refreshTimer;
    bool _isNewStyle = false;
    int _refreshCount;

    QColor _currentBackgroundColor;
    QRect _backgroundRect, _buttonSlider;
    int _minSliderX, _currentSliderX, _maxSliderX;

    QString _currentText;
    QFont _currentUsagesTextFont, _currentStateTextFont;

};


#endif // CUSTOMWIDGET_H
