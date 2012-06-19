#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>
#include <QMap>

#include "word.h"

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)

public:
    explicit Book(QObject *parent = 0);

signals:
    void titleChanged();

public slots:

public:
    QString getName();
    void setName(QString name);
    QString getTitle();
    void setTitle(QString title);
    QMap<QString, Word *> *getWords();

protected:
    QString name;
    QString title;
    QMap<QString, Word *> words;
};

#endif // BOOK_H
