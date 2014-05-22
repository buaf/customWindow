#ifndef CUSTOMTEXT_H
#define CUSTOMTEXT_H

#include <QWidget>
#include <QPaintEvent>
#include <QGraphicsItem>
#include <QPainter>

class CustomText : public QWidget
{
    Q_OBJECT

public:
    CustomText(QWidget * parent = nullptr);
    void initUi();
    void setText(QString text);

    void resizeEvent(QResizeEvent * event);
    void paintEvent(QPaintEvent * event);


private:
    QString _currentText;
    QFont _currentFont;

};

#endif // CUSTOMTEXT_H
