#ifndef DEBATE_H
#define DEBATE_H

#include <QString>
#include <QStringList>
#include <QDateTime>

class Debate
{
public:
    Debate();
    Debate(const QString time, const QString title, const QString subtitle);

    QString getTime() const;
    QString getTitle() const;
    QString getSubtitle() const;

private:
    QString time;
    QString title;
    QString subtitle;
};

#endif // MP_H
