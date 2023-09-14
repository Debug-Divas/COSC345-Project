#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

#include "mp.h"
#include "finances.h"

class DbManager
{
public:
    
    DbManager(const QString& path);

    ~DbManager();

    bool isOpen() const;

    // Creates mps table from csv file
    bool createMpsTable();

    std::vector<MP> getAllMps();

    std::vector<MP> getAllMpsFromParty(const QString& party);

    MP getMpFromName(const QString& name);
    
    std::vector<Finances> getAllFinances();

    bool createFinancialInterestsTable();

    bool createSpeechTable();

    bool createSpeechContentTable();

    bool createDebateTable();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
