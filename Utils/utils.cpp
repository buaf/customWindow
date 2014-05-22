#include <QDesktopWidget>
#include <QApplication>
#include <QFontDatabase>

#include "utils.h"

QPoint Utils::getCenterPos(int windowWidth, int windowHeight)
{
    QDesktopWidget * desctopWidget =  qApp->desktop();
    int descWidth = desctopWidget->width();
    int descHeight = desctopWidget->height();
    return QPoint((descWidth / 2) - (windowWidth / 2), (descHeight / 2) - (windowHeight / 2));
}

QFont Utils::loadFont(QString fileName)
{
    return loadFont(fileName, 30);
}

QFont Utils::loadFont(QString fileName, int size)
{
    int fontId = QFontDatabase::addApplicationFont(fileName);
    QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    QString family = loadedFontFamilies.first();
    return QFont(family, size);
}

int Utils::calculateLength(QPoint p1, QPoint p2)
{
    QPoint p3 = p1 - p2;
    return sqrt(pow(p3.x(), 2) + pow(p3.y(), 2));
}
