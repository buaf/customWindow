#ifndef WINDOWCUSTOMFRAME_H
#define WINDOWCUSTOMFRAME_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QResizeEvent>

class WindowCustomFrame : public QWidget
{
    Q_OBJECT

public:
    WindowCustomFrame(QWidget * root = nullptr);
    void show();
    void destroy();

    QPushButton * initPushButton(QString iconName);
    void removePushButton(QPushButton * button);

    void resizeEvent(QResizeEvent * event);

public slots:
    void maximize();
    void setHidden(bool hide);

private:
    QWidget * _root;
    QHBoxLayout _mainLayout;

    QPoint _dragPosition;

    QPushButton * _windowIconButton;
    QPushButton * _windowTextButton;
    QPushButton * _windowMinimizeButton;
    QPushButton * _windowMaximizeButton;
    QPushButton * _windowCloseButton;

    bool _isMaximize = false, _isAlive = false;
};

#endif // WINDOWCUSTOMFRAME_H
