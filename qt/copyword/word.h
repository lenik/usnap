#ifndef WORD_H
#define WORD_H

#include <QObject>

class Word : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString sound READ getSound WRITE setSound)
    Q_PROPERTY(QString explanation READ getExplanation WRITE setExplanation)

public:
    explicit Word(QObject *parent = 0);

signals:

public slots:

public:
    QString getName();
    void setName(QString name);
    QString getSound();
    void setSound(QString sound);
    QString getExplanation();
    void setExplanation(QString explanation);

private:
    QString name;
    QString sound; // pronouncation.
    QString explanation;
};

#endif // WORD_H
