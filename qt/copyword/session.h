#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVariantList>

#include "player.h"
#include "book.h"

class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Player *player READ getPlayer WRITE setPlayer)
    Q_PROPERTY(Book *book READ getBook WRITE setBook NOTIFY bookChanged)
    Q_PROPERTY(bool random READ isRandom WRITE setRandom NOTIFY modeChanged)
    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(int index READ getIndex WRITE setIndex NOTIFY indexChanged)
    Q_PROPERTY(Word *current READ getCurrent)
    Q_PROPERTY(QVariantList candidates READ getCandidates)
    Q_PROPERTY(int answer READ getAnswer WRITE setAnswer NOTIFY answerChanged)
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
    Player *getPlayer();
    void setPlayer(Player *player);
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
    Word *getCurrent();
    QVariantList getCandidates();
    int getAnswer();
    void setAnswer(int answer);
    int getScore();

    QVariantList getSelection();
    QVariantList getAnswers();

private:
    Player *player;
    Book *book;
    bool random;
    int count;
    int speed;
    QVariantList answers;
    int index;
    QVariantList candidates;
};

#endif // SESSION_H
