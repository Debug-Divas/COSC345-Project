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
#include "finances.h"
#include "debate.h"
#include "speech.h"
#include "speechcontent.h"
#include "vote.h"

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
    QSqlQuery query("SELECT mps.*, finances.* FROM mps LEFT JOIN Finances ON mps.name = Finances.mp_name;");
    while (query.next())
    {
        QStringList cd = query.value(8).toString().split("|");
        QStringList oc = query.value(9).toString().split("|");
        QStringList emp = query.value(10).toString().split("|");
        QStringList it = query.value(11).toString().split("|");
        QStringList orgs = query.value(12).toString().split("|");
        QStringList prop = query.value(13).toString().split("|");
        QStringList ret = query.value(14).toString().split("|");
        QStringList is = query.value(15).toString().split("|");
        QStringList to_you = query.value(16).toString().split("|");
        QStringList by_you = query.value(17).toString().split("|");
        QStringList os = query.value(18).toString().split("|");
        QStringList gifts = query.value(19).toString().split("|");
        QStringList pa = query.value(20).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you, os, gifts, pa);

        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), 
            query.value(6).toString(), finances);
        allMps.push_back(mp);
    }
    return allMps;
}

std::vector<MP> DbManager::getAllMpsFromParty(const QString& party)
{
    std::vector<MP> allMps;
    qDebug() << "Persons in db:";
    QSqlQuery query;
    query.prepare("SELECT mps.*, finances.* FROM mps LEFT JOIN Finances ON mps.name = Finances.mp_name WHERE mps.party = ?;");
    query.bindValue(0, party);

    /**/
    if (query.exec()) {
        // Query executed successfully
        qDebug() << "Query executed successfully";
    }
    else {
        // Error occurred during query execution
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    while (query.next())
    {
        QStringList cd = query.value(8).toString().split("|");
        QStringList oc = query.value(9).toString().split("|");
        QStringList emp = query.value(10).toString().split("|");
        QStringList it = query.value(11).toString().split("|");
        QStringList orgs = query.value(12).toString().split("|");
        QStringList prop = query.value(13).toString().split("|");
        QStringList ret = query.value(14).toString().split("|");
        QStringList is = query.value(15).toString().split("|");
        QStringList to_you = query.value(16).toString().split("|");
        QStringList by_you = query.value(17).toString().split("|");
        QStringList os = query.value(18).toString().split("|");
        QStringList gifts = query.value(19).toString().split("|");
        QStringList pa = query.value(20).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you, os, gifts, pa);

        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), 
            query.value(6).toString(), finances);
        allMps.push_back(mp);
    }
    return allMps;
}


MP DbManager::getMpFromName(const QString& name)
{
    QSqlQuery query;
    query.prepare("SELECT mps.*, finances.* FROM mps LEFT JOIN Finances ON mps.name = Finances.mp_name WHERE mps.name = ?;");
    query.bindValue(0, name);

    if (query.exec() && query.next())
    {
        QStringList cd = query.value(8).toString().split("|");
        QStringList oc = query.value(9).toString().split("|");
        QStringList emp = query.value(10).toString().split("|");
        QStringList it = query.value(11).toString().split("|");
        QStringList orgs = query.value(12).toString().split("|");
        QStringList prop = query.value(13).toString().split("|");
        QStringList ret = query.value(14).toString().split("|");
        QStringList is = query.value(15).toString().split("|");
        QStringList to_you = query.value(16).toString().split("|");
        QStringList by_you = query.value(17).toString().split("|");
        QStringList os = query.value(18).toString().split("|");
        QStringList gifts = query.value(19).toString().split("|");
        QStringList pa = query.value(20).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you, os, gifts, pa);

        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
            query.value(6).toString(), finances);

        return mp;
        
    }
    else
    {
        qDebug() << "person exists failed: " << query.lastError();
        return MP();
    }
}

std::vector<Speech> DbManager::getSpeechFromName(const QString& name)
{
    QSqlQuery query;
    query.prepare("SELECT speechContent.*, speech.* FROM speechcontent JOIN speech ON speechContent.speech_time = speech.date_time WHERE speechContent.name = ?;");

    query.bindValue(0, name);

    if (query.exec()) {
        // Query executed successfully
        qDebug() << "Query executed successfully";
    }
    else {
        // Error occurred during query execution
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    QString currentSpeechTime = "";
    Speech currentSpeech = Speech();
    std::vector<Speech> speeches;



    while (query.next())
    {
        QString speechContent_speechtime = query.value(4).toString();

        bool speech_exists = false;
        for (int i = 0; i < speeches.size(); i++) {
            if (speeches[i].getTime() == speechContent_speechtime) {
                Speechcontent content = Speechcontent(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(4).toString(), query.value(3).toString());
                speeches[i].addContent(content);
                speech_exists = true;
            }
        }

        if(speech_exists == false){
            Debate debate = Debate();
            std::vector<Speechcontent> contents;
            Speechcontent content = Speechcontent(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(4).toString(), query.value(3).toString());
            contents.push_back(content);
            Speech speech = Speech(query.value(6).toString(), query.value(5).toString(), query.value(7).toString(), debate, contents);
            speeches.push_back(speech);
        }


        qDebug() << query.value(0);
        qDebug() << query.value(1);
        qDebug() << query.value(2);
        qDebug() << query.value(3);
        qDebug() << query.value(4);
        qDebug() << query.value(5);
        qDebug() << query.value(6);
        qDebug() << query.value(7);
        qDebug() << query.value(8);
        qDebug() << query.value(9);
        qDebug() << query.value(10);
        qDebug() << query.value(11);

    }

    return speeches;
}

std::vector<Finances> DbManager::getAllFinances()
{
    std::vector<Finances> allFinances;
    qDebug() << "Finances in db:";
    QSqlQuery query("SELECT * FROM finances");
    int mp_name = query.record().indexOf("mp_name");
    while (query.next())
    {
        QStringList cd = query.value(1).toString().split("|");
        QStringList oc = query.value(2).toString().split("|");
        QStringList emp = query.value(3).toString().split("|");
        QStringList it = query.value(4).toString().split("|");
        QStringList orgs = query.value(5).toString().split("|");
        QStringList prop = query.value(6).toString().split("|");
        QStringList ret = query.value(7).toString().split("|");
        QStringList is = query.value(8).toString().split("|");
        QStringList to_you = query.value(9).toString().split("|");
        QStringList by_you = query.value(10).toString().split("|");
        QStringList os = query.value(11).toString().split("|");
        QStringList gifts = query.value(12).toString().split("|");
        QStringList pa = query.value(13).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you,
            os, gifts, pa);
        allFinances.push_back(finances);
    }
    return allFinances;
}

std::vector<Vote> DbManager::getAllVotes()
{
    std::vector<Vote> allVotes;
    qDebug() << "Votes in db:";
    QSqlQuery query("SELECT * FROM vote");
    while (query.next())
    {
        QString ayes_string = query.value(2).toString();
        QString noes_string = query.value(3).toString();
        QStringList ayes = ayes_string.split("!");
        QStringList noes = noes_string.split("!");
        Vote vote = Vote(query.value(1).toString(), ayes, noes);
        allVotes.push_back(vote);
    }
    return allVotes;
}

bool DbManager::createFinancialInterestsTable()
{
    QSqlQuery query;

    query.prepare("DROP Table finances");
    query.exec();

    query.prepare("CREATE TABLE finances( mp_name VARCHAR(50) PRIMARY KEY, company_directorships VARCHAR(800) NULL, other_companies VARCHAR(1600) NULL, employment VARCHAR(100) NULL, interest_trust VARCHAR(500) NULL, organizations VARCHAR(800) NULL, property VARCHAR(800) NULL, retirement VARCHAR(300) NULL, investment_schemes VARCHAR(500) NULL, debts_to_you VARCHAR(400) NULL, debts_owed_by_you VARCHAR(300) NULL, overseas_travel VARCHAR(1000) NULL, gifts VARCHAR(1000) NULL, payment_activities VARCHAR(500) NULL);");
    //query.prepare("CREATE TABLE finances( mp_name VARCHAR(50) PRIMARY KEY);");

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
        QStringList fields;
        if(line.contains('"')){
            QStringList fields1 = line.split('"');
            for(int i = 0; i < fields1.size(); i++){
                if(i % 2 == 1){
                    fields.append(fields1[i]);
                }else{
                    fields.append(fields1[i].split(","));
                    fields.pop_back();
                }
            }
        }else{
            fields = line.split(",");
        }

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

    query.prepare("CREATE TABLE speechContent(speechID INTEGER PRIMARY KEY AUTOINCREMENT, type VARCHAR(10), name VARCHAR(50), text VARCHAR(1000), speech_time DATETIME);");

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

    query.prepare("INSERT INTO speechContent (type, name, text, speech_time) VALUES (?, ?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
        QStringList fields;
        if(line.contains('"')){
            QStringList fields1 = line.split('"');
            fields.append(fields1[0].split(","));
            fields.pop_back();
            fields1.pop_front();
            fields.append(fields1[fields1.size()-1].split(",")[1]);
            fields1.pop_back();
            QString text = "";
            for (int i = 0; i < fields1.size(); i++){
                text += fields1[i];
            }
            fields.insert(3, text);

        }else{
            fields = line.split(",");
        }


        for (int i = 0; i < 4; i++) {
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

bool DbManager::createVotesTable()
{
    QSqlQuery query;

    query.prepare("DROP Table vote");
    query.exec();

    query.prepare("CREATE TABLE vote( ID INTEGER PRIMARY KEY AUTOINCREMENT, vote_name VARCHAR(100), ayes VARCHAR(500), noes VARCHAR(500));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'vote': one might already exist.";
        return false;
    }

    QFile file("../web-scrapers/transcripts-scraper/votes.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO vote (vote_name, ayes, noes) VALUES (?, ?, ?)");

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
