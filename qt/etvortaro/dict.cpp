#include "dict.h"

Dict::Dict(QObject *parent) :
    QObject(parent)
{
}

QDeclarativeListProperty<Word> Dict::getWords() {
    return QDeclarativeListProperty<Word>(0, m_words);
}

int Dict::size() const {
    return m_words.size();
}

Word *Dict::get(int index) const {
    return m_words.at(index);
}

int Dict::indexOf(QString key) const {
    int begin = 0;
    int end = size();
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        Word *w = m_words.at(mid);
        int cmp = compare(key, w->getName());
        if (cmp < 0)
            end = mid;
        else if (cmp > 0)
            begin = mid + 1;
        else
            return mid;
    }
    // assert begin == end;
    return -begin - 1;
}

void Dict::add(Word *word) {
    int pos = indexOf(word->getName());
    if (pos < 0)
        pos = -pos - 1;
    m_words.insert(pos, word);
}

Word *Dict::lazyCreate(const char *name) {
    return lazyCreate(QString::fromUtf8(name));
}

Word *Dict::lazyCreate(QString name) {
    Word *word;
    int pos = indexOf(name);
    if (pos >= 0)
        word = get(pos);
    else {
        pos = -pos - 1;
        word = new Word(this);
        word->setName(name);
        m_words.insert(pos, word);
    }
    return word;
}

int Dict::compare(QString s1, QString s2) const {
    QString lc1 = s1.toLower();
    QString lc2 = s2.toLower();
    if (lc1 < lc2)
        return -1;
    if (lc1 > lc2)
        return 1;
    return 0;
}
