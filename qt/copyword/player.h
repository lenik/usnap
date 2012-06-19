#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMap>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

public:
    explicit Player(QObject *parent = 0);

signals:
    void nameChanged();

public slots:

public:
    QString getName();
    void setName(QString name);

private:
    QString name;
    // QString face;
    QMap<QString, int> scores; // book => score
};

#endif // PLAYER_H
