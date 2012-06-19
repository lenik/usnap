#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMap>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name
               READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QMap scores)

public:
    explicit Player(QObject *parent = 0);

private:
    QString name;
    QMap<Book, int> scores;

public:

signals:

public slots:

};

#endif // PLAYER_H
