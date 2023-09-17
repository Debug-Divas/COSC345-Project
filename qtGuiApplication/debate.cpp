#include <QStringList>
#include <QDateTime>
#include "debate.h"

Debate::Debate()
{
}

Debate::Debate(const QString time, const QString title, const QString subtitle) :
    time(time), title(title), subtitle(subtitle)
{
}

QString Debate::getTime() const
{
    return time;
}

QString Debate::getTitle() const
{
    return title;
}

QString Debate::getSubtitle() const
{
    return subtitle;
}
