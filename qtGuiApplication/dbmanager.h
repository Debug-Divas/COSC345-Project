#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include "mp.h"
#include "finances.h"
#include "speech.h"
#include "vote.h"

class DbManager
{
public:
    DbManager(const QString &path);

    ~DbManager();

    bool isOpen() const;

    // Creates mps table from csv file
    bool createMpsTable();

    std::vector<MP> getAllMps();

    std::vector<MP> getAllMpsFromParty(const QString &party);

    MP getMpFromName(const QString &name);

    std::vector<Finances> getAllFinances();

    std::vector<Speech> getSpeechFromName(const QString& name);

    std::vector<Vote> getAllVotes();

    bool createFinancialInterestsTable();

    bool createSpeechTable();

    bool createSpeechContentTable();

    bool createDebateTable();

    bool createVotesTable();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
