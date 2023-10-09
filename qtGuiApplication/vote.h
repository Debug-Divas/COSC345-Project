#ifndef VOTE_H
#define VOTE_H

#include <QString>
#include <QStringList>

class Vote
{
public:
    Vote();
    Vote(const QString date, const QString vote_name, const QStringList ayes, const QStringList noes);

    QString getVoteName() const;
    QString getDate() const;
    QStringList getAyes() const;
    QStringList getNoes() const;

private:
    QString date;
    QString vote_name;
    QStringList ayes;
    QStringList noes;
};


#endif // VOTE_H
