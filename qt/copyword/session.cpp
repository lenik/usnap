#include "session.h"

Session::Session(QObject *parent) :
    QObject(parent)
{
}

Player *Session::getPlayer() {
    return player;
}

void Session::setPlayer(Player *player) {
    this->player = player;
}

Book *Session::getBook() {
    return book;
}

void Session::setBook(Book *book) {
    this->book = book;
    emit bookChanged();
}

bool Session::isRandom() {
    return random;
}

void Session::setRandom(bool random) {
    this->random = random;
    emit modeChanged();
}

int Session::getSpeed() {
    return speed;
}

void Session::setSpeed(int speed) {
    this->speed = speed;
    emit speedChanged();
}

int Session::getCount() {
    return count;
}

void Session::setCount(int count) {
    this->count = count;
    emit countChanged();
}

int Session::getIndex() {
    return index;
}

void Session::setIndex(int index) {
    this->index = index;
    emit indexChanged();
}

Word *Session::getCurrent() {
    return 0;
}

QVariantList Session::getCandidates() {
    QVariantList list;
    return list;
}

int Session::getAnswer() {
    return 0;
}

void Session::setAnswer(int answer) {
    // answers[index] = answer;
}

int Session::getScore() {
    int score = 0;
    return score;
}

QVariantList Session::getSelection() {
    QVariantList list;
    return list;
}

QVariantList Session::getAnswers() {
    QVariantList list;
    return list;
}
