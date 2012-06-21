#include "session.h"

Session::Session(QObject *parent) :
    QObject(parent)
{
    player = new Player(this);
    file = new CsvFile(this);
}

Player *Session::getPlayer() {
    return player;
}

void Session::setPlayer(Player *player) {
    this->player = player;
}

CsvFile *Session::getFile() {
    return file;
}
