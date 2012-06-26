#include "word.h"

Word::Word(QObject *parent) :
    QObject(parent)
{
}

bool Word::operator==(const Word &word) const {
    return m_name == word.m_name;
}

bool Word::operator<(const Word &word) const {
    return m_name < word.m_name;
}

QString Word::getName() {
    return m_name;
}

void Word::setName(QString name) {
    m_name = name;
}

QString Word::getDescription() {
    return m_description;
}

void Word::setDescription(QString description) {
    m_description = description;
}

void Word::addTranslation(QString translation) {
    if (! m_description.isEmpty())
        m_description.append("; ");
    m_description.append(translation);
}
