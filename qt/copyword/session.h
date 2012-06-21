#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVariantList>

#include "player.h"
#include "csvfile.h"

class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Player *player READ getPlayer WRITE setPlayer NOTIFY playerChanged)
    Q_PROPERTY(CsvFile *file READ getFile CONSTANT)

public:
    explicit Session(QObject *parent = 0);

signals:
    void playerChanged();

public slots:
public:
    Player *getPlayer();
    void setPlayer(Player *player);
    CsvFile *getFile();

private:
    Player *player;
    CsvFile *file;
};

#endif // SESSION_H
