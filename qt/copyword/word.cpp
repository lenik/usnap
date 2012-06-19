#include "word.h"

Word::Word(QObject *parent) :
    QObject(parent)
{
}

QString Word::getName() {
    return name;
}

void Word::setName(QString name) {
    this->name = name;
}

QString Word::getSound() {
    return sound;
}

void Word::setSound(QString sound) {
    this->sound = sound;
}

QString Word::getExplanation() {
    return explanation;
}

void Word::setExplanation(QString explanation) {
    this->explanation = explanation;
}
