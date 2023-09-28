#ifndef VOTE_H
#define VOTE_H

#include <QString>
#include <QStringList>

class Vote
{
public:
    Vote();
    Vote(const QString vote_name, const QStringList ayes, const QStringList noes);

    QString getVoteName() const;
    QStringList getAyes() const;
    QStringList getNoes() const;

private:
    QString vote_name;
    QStringList ayes;
    QStringList noes;
};


#endif // VOTE_H
