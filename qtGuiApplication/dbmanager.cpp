#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <qevent.h>

#include <QFile>
#include <QTextStream>
#include <QStringList>

#include "mp.h"

DbManager::DbManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createMpsTable()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE mps( id INT, name VARCHAR(50) PRIMARY KEY, salutation VARCHAR(10) NULL, job_title VARCHAR(50), electorate VARCHAR(50) NULL, party VARCHAR(30), parliament_email VARCHAR(70));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'mps': one might already exist.";
        return false;
    }


    QFile file("../web-scrapers/transcripts-scraper/mp.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO mps (id, name, salutation, job_title, electorate, party, parliament_email) VALUES (?, ?, ?, ?, ?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        query.addBindValue(fields[0].toInt());
        query.addBindValue((fields[2].remove(" ") + " " + fields[1]).remove("\""));
        query.addBindValue(fields[3] == "\"\"" ? NULL : fields[3]);
        query.addBindValue(fields[4]);
        query.addBindValue(fields[5] == "\"\"" ? NULL : fields[5]);
        query.addBindValue(fields[6]);
        query.addBindValue(fields[7]);

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}

std::vector<MP> DbManager::getAllMps()
{
    std::vector<MP> allMps;
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM mps");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), 
            query.value(6).toString());
        allMps.push_back(mp);
    }
    return allMps;
}


MP DbManager::getMpFromName(const QString& name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM mps WHERE name = ?");
    query.bindValue(0, name);

    if (query.exec() && query.next())
    {
        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
                query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
                query.value(6).toString());
        return mp;
        
    }
    else
    {
        qDebug() << "person exists failed: " << query.lastError();
        return MP();
    }
}

bool DbManager::createFinancialInterestsTable()
{
    QSqlQuery query;

    query.prepare("DROP Table finances");
    query.exec();
                            
    query.prepare("CREATE TABLE finances( mp_name VARCHAR(50) PRIMARY KEY, company_directorships VARCHAR(800) NULL, other_companies VARCHAR(1600) NULL, employment VARCHAR(100) NULL, interest_trust VARCHAR(500) NULL, organizations VARCHAR(800) NULL, property VARCHAR(800) NULL, retirement VARCHAR(300) NULL, investment_schemes VARCHAR(500) NULL, debts_to_you VARCHAR(400) NULL, debts_owed_by_you VARCHAR(300) NULL, overseas_travel VARCHAR(1000) NULL, gifts VARCHAR(1000) NULL, payment_activities VARCHAR(500) NULL);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'finances': one might already exist.";
        return false;
    }

    QFile file("../web-scrapers/financial-scraper/output.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO finances (mp_name, company_directorships, other_companies, employment, interest_trust, organizations, property, retirement, investment_schemes, debts_to_you, debts_owed_by_you, overseas_travel, gifts, payment_activities) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        query.addBindValue(fields[0]);
        for (int i = 1; i < 14; i++) {
            query.addBindValue(fields[i] == "\"\"" ? NULL : fields[i]);
        }

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}


bool DbManager::createPersonTable()
{
    QSqlQuery query;

    query.prepare("DROP Table person");
    query.exec();

    query.prepare("CREATE TABLE person( name VARCHAR(50) PRIMARY KEY, is_mp INT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'person': one might already exist.";
        return false;
    }

    QFile file("../web-scrapers/transcripts-scraper/persons.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO person (name, is_mp) VALUES (?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        query.addBindValue(fields[0]);
        query.addBindValue(fields[1]);

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}

bool DbManager::createSpeechTable()
{
    QSqlQuery query;

    query.prepare("DROP Table speech");
    query.exec();

    query.prepare("CREATE TABLE speech(name VARCHAR(100), date_time DATETIME PRIMARY KEY, debate_time DATETIME);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'speech': one might already exist.";
        return false;
    }

    QFile file("../web-scrapers/transcripts-scraper/speeches.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO speech (name, date_time, debate_time) VALUES (?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        query.addBindValue(fields[0]);
        query.addBindValue(fields[1]);
        query.addBindValue(fields[2]);

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}

bool DbManager::createSpeechContentTable()
{
    QSqlQuery query;

    query.prepare("DROP Table speechContent");
    query.exec();

    query.prepare("CREATE TABLE speechContent(speechID Int PRIMARY KEY, type VARCHAR(10), name VARCHAR(50), text VARCHAR(1000), speech_time DATETIME);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'speechContent': one might already exist.";
        return false;
    }

    QFile file("../web-scrapers/transcripts-scraper/speechContent.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO speechContent (speechID, type, name, text, speech_time) VALUES (?, ?, ?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        for (int i = 0; i < 5; i++) {
            query.addBindValue(fields[i]);
        }

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}
bool DbManager::createDebateTable()
{
    QSqlQuery query;

    query.prepare("DROP Table debate");
    query.exec();

    query.prepare("CREATE TABLE debate( title VARCHAR(100), subtitle VARCHAR(200), datetime DATETIME PRIMARY KEY);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'debate': one might already exist.";
        return false;
    }

    QFile file("../web-scrapers/transcripts-scraper/debates.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO debate (title, subtitle, datetime) VALUES (?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        query.addBindValue(fields[0]);
        query.addBindValue(fields[1]);
        query.addBindValue(fields[2]);

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}

