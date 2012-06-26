#include "session.h"

// #include "csvfile.h"
#include <QFile>

Session::Session(QObject *parent) :
    QObject(parent)
{
    m_dict = new Dict(this);
    m_etDict = new Dict(this);
    m_zhDict = new Dict(this);
}

Dict *Session::getDict() {
    return m_dict;
}

Dict *Session::getEtDict() {
    return m_etDict;
}

Dict *Session::getZhDict() {
    return m_zhDict;
}

typedef const char *ccptr_t;

bool Session::load() {
    QFile file(":/data/vortaro.csv");
    if (! file.open(QFile::ReadOnly | QFile::Text)) {
        // emit error();
        return false;
    }

    char line[1024];
    ccptr_t tokens[16];
    int tokenMax = sizeof(tokens) / sizeof(ccptr_t);

    while (! file.atEnd()) {
        int cc = file.readLine(line, sizeof(line));
        if (cc <= 0)
            break;

        char *p = line;
        tokens[0] = p;
        int tokenCount = 0;

        while (*p) {
            if (*p == ',') *p = '\0';
            if (*p++ == '\0') {
                if (tokenCount < tokenMax)
                    tokens[++tokenCount] = p;
            }
        }

        // et => zh
        Word *et = m_etDict->lazyCreate(tokens[0]);
        QString word = et->getName();
        for (int i = 1; i < tokenCount; i++) {
            QString tr = QString::fromUtf8(tokens[i]);
            et->addTranslation(tr);
        }

        // zh => et
        for (int i = 1; i < tokenCount; i++) {
            Word *zh = m_zhDict->lazyCreate(tokens[i]);
            zh->addTranslation(word);
        }
    }

    file.close();
    return true;
}
