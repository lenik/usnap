#include "point.h"

Point::Point(QObject *parent) :
    QObject(parent)
{
    m_x = m_y = 0;
}

double Point::getX() {
    return m_x;
}

void Point::setX(double x) {
    m_x = x;
}

double Point::getY() {
    return m_y;
}

void Point::setY(double y) {
    m_y = y;
}
