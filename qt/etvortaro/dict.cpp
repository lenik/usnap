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

int Dict::indexOf(QString name) const {
    int begin = 0;
    int end = size();
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        Word *w = m_words.at(mid);
        if (name == w->getName())
            return mid;
        if (name < w->getName())
            end = mid;
        else
            begin = mid + 1;
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
