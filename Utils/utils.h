#ifndef UTILS_H
#define UTILS_H

#include <QPoint>
#include <QFont>

class Utils
{
public:
    static QPoint getCenterPos(int windowWidth, int windowHeight);
    static QFont loadFont(QString fileName, int size);
    static QFont loadFont(QString fileName);
    static int calculateLength(QPoint p1, QPoint p2);
};

#endif // UTILS_H
