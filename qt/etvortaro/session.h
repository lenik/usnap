#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "dict.h"

class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Dict *dict READ getDict)

public:
    explicit Session(QObject *parent = 0);

signals:
    void loaded();

public slots:
    Q_INVOKABLE bool load();

public:
    Dict *getDict();

private:
    //    Dict etDict;
    //    Dict zhDict;
    Dict *m_dict; // merged single dict.
};

#endif // SESSION_H
