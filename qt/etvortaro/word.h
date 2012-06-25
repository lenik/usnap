#ifndef WORD_H
#define WORD_H

#include <QObject>
#include <QString>

class Word : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription)

public:
    explicit Word(QObject *parent = 0);

signals:

public slots:

public:
    bool operator==(const Word &word) const;
    bool operator<(const Word &word) const;
    inline bool operator>(const Word &word) const { return word < *this; }
    inline bool operator!=(const Word &word) const { return !operator==(word); }
    inline bool operator<=(const Word &word) const { return !operator>(word); }
    inline bool operator>=(const Word &word) const { return !operator<(word); }

public:
    QString getName();
    void setName(QString name);
    QString getDescription();
    void setDescription(QString description);
    void addTranslation(QString translation);

private:
    QString m_name;
    QString m_description;
};

#endif // WORD_H
