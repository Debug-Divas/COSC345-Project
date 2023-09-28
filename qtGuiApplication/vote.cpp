#include <QString>
#include <QStringList>
#include "vote.h"

Vote::Vote()
{
}

Vote::Vote(const QString vote_name, const QStringList ayes, const QStringList noes) :
    vote_name(vote_name), ayes(ayes), noes(noes)
{
}

QString Vote::getVoteName() const
{
    return vote_name;
}

QStringList Vote::getAyes() const
{
    return ayes;
}

QStringList Vote::getNoes() const
{
    return noes;
}


