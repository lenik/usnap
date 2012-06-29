#ifndef POINT_H
#define POINT_H

#include <QObject>

class Point : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double x READ getX WRITE setX NOTIFY xChanged)
    Q_PROPERTY(double y READ getY WRITE setY NOTIFY yChanged)

public:
    explicit Point(QObject *parent = 0);

signals:
    void xChanged();
    void yChanged();

public slots:
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

private:
    double m_x;
    double m_y;
};

#endif // POINT_H
