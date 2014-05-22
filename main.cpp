#include <QApplication>
#include <QVBoxLayout>
#include <QFrame>
#include <QGraphicsDropShadowEffect>


#include "customwidget.h"
#include "windowcustomframe.h"

int main(int argc,char ** argv)
{
    QApplication app(argc,argv);


    QWidget mainWidget;
    mainWidget.setPalette(Qt::white);
    QVBoxLayout mainLayout;

    WindowCustomFrame frame(&mainWidget);
    frame.setHidden(true);
    frame.setMinimumHeight(50);
    frame.setMaximumHeight(50);
    mainLayout.addWidget(&frame);

    QFrame finishLine;
    finishLine.setFrameShape(QFrame::HLine);
    finishLine.setFrameShadow(QFrame::Raised);
    finishLine.setPalette(QPalette(Qt::gray));
    finishLine.setHidden(true);
    mainLayout.addWidget(&finishLine);

    CustomWidget customWidget(&mainWidget);
    customWidget.setWindowTitle("Standart Window");
    customWidget.resize(700, 500);
    mainLayout.addWidget(&customWidget);

    QObject::connect(&customWidget, SIGNAL(hideFrame(bool)), &frame, SLOT(setHidden(bool)));
    QObject::connect(&customWidget, SIGNAL(hideFrame(bool)), &finishLine, SLOT(setHidden(bool)));
    QObject::connect(&customWidget, SIGNAL(hideFrame(bool)), &customWidget, SLOT(resizeToDefault()));


    mainWidget.setLayout(&mainLayout);
    mainWidget.show();

    return app.exec();
}
