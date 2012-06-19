#include "book.h"

Book::Book(QObject *parent) :
    QObject(parent)
{
}

QString Book::getName() {
    return name;
}

void Book::setName(QString name) {
    this->name = name;
}

QString Book::getTitle() {
    return title;
}

void Book::setTitle(QString title) {
    this->title = title;
}

QMap<QString, Word *> *Book::getWords() {
    return &words;
}
