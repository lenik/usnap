#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "dict.h"

class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Dict *dict READ getDict NOTIFY dictChanged)
    Q_PROPERTY(Dict *etDict READ getEtDict NOTIFY etDictChanged)
    Q_PROPERTY(Dict *zhDict READ getZhDict NOTIFY zhDictChanged)

public:
    explicit Session(QObject *parent = 0);

signals:
    void loaded();
    void dictChanged();
    void etDictChanged();
    void zhDictChanged();

public slots:
    Q_INVOKABLE bool load();

public:
    Dict *getDict();
    Dict *getEtDict();
    Dict *getZhDict();

private:
    Dict *m_dict; // merged single dict.
    Dict *m_etDict;
    Dict *m_zhDict;
};

#endif // SESSION_H
