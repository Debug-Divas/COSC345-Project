#include <QString>
#include <QStringList>
#include "vote.h"

Vote::Vote()
{
}

Vote::Vote(const QString date, const QString vote_name, const QStringList ayes, const QStringList noes) :
    date(date), vote_name(vote_name), ayes(ayes), noes(noes)
{
}

QString Vote::getVoteName() const
{
    return vote_name;
}

QString Vote::getDate() const
{
    return date;
}

QStringList Vote::getAyes() const
{
    return ayes;
}

QStringList Vote::getNoes() const
{
    return noes;
}


