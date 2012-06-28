#include "csvfile.h"

CsvFile::CsvFile(QObject *parent) :
    QObject(parent)
{
    // m_fileName = "";
    m_file = 0;
    m_minColumns = 1;
    m_maxColumns = 16;
    m_loaded = false;
}

void CsvFile::open() {
    if (m_file != 0)
        return;
    if (m_fileName.isEmpty()) // throw new IllegalStateException()
        return;
    m_file = new QFile(m_fileName, this);
    if (m_file->open(QFile::ReadOnly | QFile::Text)) {
        emit opened();
    }
    m_loaded = false;
}

void CsvFile::close() {
    if (m_file != 0) {
        // if (m_file->isOpen())
        m_file->close();
        delete m_file;
        m_file = 0;
        emit closed();
    }
    m_loaded = false;
    m_records.clear();
}

QString CsvFile::getFileName() {
    return m_fileName;
}

void CsvFile::setFileName(QString fileName) {
    this->close();
    this->m_fileName = fileName;
}

QFile *CsvFile::getFile() {
    return m_file;
}

int CsvFile::getMinColumns() {
    return m_minColumns;
}

void CsvFile::setMinColumns(int minColumns) {
    this->m_minColumns = minColumns;
}

int CsvFile::getMaxColumns() {
    return m_maxColumns;
}

void CsvFile::setMaxColumns(int maxColumns) {
    this->m_maxColumns = maxColumns;
}

QVariantList CsvFile::getRecords() {
    const char delim = ',';
    char line[1024];

    if (! m_loaded) { // lazy-load
        m_records.clear();
        while (! m_file->atEnd()) {
            int cc = m_file->readLine(line, sizeof(line));

            QStringList row;
            char *token = line;
            char *p = line;
            int columns = 0;
            for (int i = 0; i <= cc; i++) {
                if (*p == '\n') *p = '\0';
                if (*p == delim && columns < m_maxColumns)
                    *p = '\0';
                if (! *p++) {
                    row.append(QString::fromUtf8(token));
                    token = p;
                    columns++;
                }
            }

            if (row.size() < m_minColumns)
                continue;
            m_records.append(row);
        }
        m_loaded = true;
    }
    return m_records;
}
