#include "player.h"

Player::Player(QObject *parent) :
    QObject(parent)
{
}

QString Player::getName() {
    return name;
}

void Player::setName(QString name) {
    this->name = name;
}
