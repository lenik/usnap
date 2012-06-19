#include "session.h"

Session::Session(QObject *parent) :
    QObject(parent)
{
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

QWord Session::getCurrent() {
    this->book->getWords();
}

QStringList Session::getCandidates();
int Session::getAnswer() {
    return answers[index];
}

void Session::setAnswer(int answer) {
    answers[index] = answer;
}

int Session::getScore() {
    int score = 0;
    return score;
}

QStringList Session::getSelection() {
    QStringList selection;
    for (int i = 0; i < count; i++) {

    }
}

QList<int> *Session::getAnswers() {
    return answer;
}
