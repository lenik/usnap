#ifndef DICT_H
#define DICT_H

#include <QObject>
#include <QDeclarativeListProperty>
#include "word.h"

class Dict : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int size READ size)
    Q_PROPERTY(QDeclarativeListProperty<Word> words READ getWords)

public:
    explicit Dict(QObject *parent = 0);

signals:

public slots:
    QDeclarativeListProperty<Word> getWords();
    int size() const;
    Word *get(int index) const;
    Q_INVOKABLE int indexOf(QString name) const;
    void add(Word *word);
    Word *lazyCreate(const char *name);
    Word *lazyCreate(QString name);

private:
    QList<Word *> m_words;
};

#endif // DICT_H
