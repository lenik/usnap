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
    ccptr_t tokens[32];
    int tokenMax = sizeof(tokens) / sizeof(ccptr_t);

    while (! file.atEnd()) {
        int cc = file.readLine(line, sizeof(line));
        if (cc < 0)
            break;

        char *p = line;
        tokens[0] = p;
        int tokenCount = 0;

        for (int i = 0; i <= cc; i++) {
            if (*p == '\n') { *p++ = '\0'; continue; }
            if (*p == ',') *p = '\0';
            if (*p++ == '\0') {
                if (tokenCount < tokenMax)
                    tokens[++tokenCount] = p;
            }
        }
        if (tokenCount < 2)
            continue;

        QString et = QString::fromUtf8(tokens[0]);

        for (int i = 1; i < tokenCount; i++) {
            QString zh = QString::fromUtf8(tokens[i]);

            // et => zh
            Word *etWord = m_etDict->lazyCreate(et);
            etWord->addTranslation(zh);

            // zh => et
            Word *zhWord = m_zhDict->lazyCreate(zh);
            zhWord->addTranslation(et);
        }
    }

    file.close();
    return true;
}
