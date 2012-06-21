#ifndef CSVFILE_H
#define CSVFILE_H

#include <QObject>
#include <QAbstractListModel>
#include <QDeclarativeListProperty>
#include <QFile>
#include <QVariantList>
#include <QStringList>

class CsvFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(int minColumns READ getMinColumns WRITE setMinColumns)
    Q_PROPERTY(int maxColumns READ getMaxColumns WRITE setMaxColumns)
    Q_PROPERTY(QVariantList records READ getRecords)

public:
    explicit CsvFile(QObject *parent = 0);

signals:
    void opened();
    void closed();
    void fileNameChanged();

public slots:
    Q_INVOKABLE void open();
    Q_INVOKABLE void close();

public:
    QString getFileName();
    void setFileName(QString fileName);
    QFile *getFile();
    // void setFile(QFile *file);

    int getMinColumns();
    void setMinColumns(int minColumns);
    int getMaxColumns();
    void setMaxColumns(int maxColumns);

    QVariantList getRecords();

private:
    QString m_fileName;
    QFile *m_file;

    // QChar m_delim;
    int m_minColumns;
    int m_maxColumns;

    bool m_loaded;
    QVariantList m_records;
};

#endif // CSVFILE_H
