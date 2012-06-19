#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "book.h"

class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Book *book READ getBook WRITE setBook NOTIFY bookChanged)
    Q_PROPERTY(bool random READ isRandom WRITE setRandom NOTIFY modeChanged)
    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(int index READ getIndex WRITE setIndex NOTIFY indexChanged)
    Q_PROPERTY(QWord current READ getCurrent)
    Q_PROPERTY(QStringList candidates READ getCandidates)
    Q_PROPERTY(int answer READ getAnswer WRITE setANSWER NOTIFY answerChanged)
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)

public:
    explicit Session(QObject *parent = 0);


signals:
    void bookChanged();
    void modeChanged();
    void speedChanged();
    void countChanged();
    void indexChanged();
    void answerChanged();
    void scoreChanged();

public slots:

public:
    Book *getBook();
    void setBook(Book *book);
    bool isRandom();
    void setRandom(bool random);
    int getSpeed();
    void setSpeed(int speed);
    int getCount();
    void setCount(int count);
    int getIndex();
    void setIndex(int index);
    QWord getCurrent();
    QStringList getCandidates();
    int getAnswer();
    void setAnswer(int answer);
    int getScore();

    QStringList getSelection();
    QList<int> getAnswers();

private:
    Book *book;
    bool random;
    int count;
    int speed;
    QList<int> answers;
    int index;
};

#endif // SESSION_H
