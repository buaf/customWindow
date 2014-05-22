#include "windowcustomframe.h"

WindowCustomFrame::WindowCustomFrame(QWidget * root) :
    QWidget(root)
{
    _root = root;
    setLayout(&_mainLayout);
}

void WindowCustomFrame::show()
{
    if (!_isAlive)
    {
        _isAlive = true;

        _windowIconButton = initPushButton(":/images/Assets/images/custom_icon.png");
        _windowTextButton = new QPushButton(_root);
        _windowTextButton->setStyleSheet("border: none; text-align: left;");
        _windowTextButton->setText("Custom window");
        _windowTextButton->setMinimumHeight(50);
        _windowTextButton->setMaximumHeight(50);
        _mainLayout.addWidget(_windowTextButton);
        _windowMinimizeButton = initPushButton(":/images/Assets/images/minimize.png");
        _windowMaximizeButton = initPushButton(":/images/Assets/images/maximize.png");
        _windowCloseButton = initPushButton(":/images/Assets/images/close.png");

        connect(_windowMinimizeButton, SIGNAL(clicked()), _root, SLOT(showMinimized()));
        connect(_windowMaximizeButton, SIGNAL(clicked()), SLOT(maximize()));
        connect(_windowCloseButton, SIGNAL(clicked()), _root, SLOT(close()));
    }
}

void WindowCustomFrame::destroy()
{
    if (_isAlive)
    {
        _isAlive = false;

        disconnect(_windowMinimizeButton, SIGNAL(clicked()), _root, SLOT(showMinimized()));
        connect(_windowMaximizeButton, SIGNAL(clicked()), this, SLOT(maximize()));
        connect(_windowCloseButton, SIGNAL(clicked()), _root, SLOT(close()));

        removePushButton(_windowIconButton);
        removePushButton(_windowTextButton);
        removePushButton(_windowMinimizeButton);
        removePushButton(_windowMaximizeButton);
        removePushButton(_windowCloseButton);
    }
}

QPushButton * WindowCustomFrame::initPushButton(QString iconName)
{
    QPushButton * button = new QPushButton(_root);
    button->setIcon(QIcon(iconName));
    button->setIconSize(QSize(50,50));
    button->setStyleSheet("border: none;");

    button->setMinimumHeight(50);
    button->setMaximumHeight(50);

    button->setMinimumWidth(50);
    button->setMaximumWidth(50);

    _mainLayout.addWidget(button);
    return button;
}

void WindowCustomFrame::removePushButton(QPushButton * button)
{
    if (button == nullptr)
    {
        return;
    }

    _mainLayout.removeWidget(button);
    delete button;
    button = nullptr;
}

void WindowCustomFrame::resizeEvent(QResizeEvent * event)
{
    if (_isAlive)
    {
        _windowTextButton->setMaximumWidth(event->size().width() * 0.6);
        _windowTextButton->setMinimumWidth(event->size().width() * 0.6);
    }
}

void WindowCustomFrame::maximize()
{
    if(_isAlive)
    {
        if (_isMaximize)
        {
            _windowMaximizeButton->setIcon(QIcon(":/images/Assets/images/maximize.png"));
            _root->showNormal();
        }
        else
        {
            _windowMaximizeButton->setIcon(QIcon(":/images/Assets/images/restore.png"));
            _root->showMaximized();
        }

        _isMaximize = !_isMaximize;
    }
}

void WindowCustomFrame::setHidden(bool hide)
{
    if (hide)
    {
        destroy();
    }
    else
    {
        show();
    }

    QWidget::setHidden(hide);
}
