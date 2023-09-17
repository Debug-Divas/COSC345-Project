#include <QStringList>
#include <QDateTime>
#include "speech.h"
#include "debate.h"
#include "speechcontent.h"

Speech::Speech()
{
}

Speech::Speech(const QString time, const QString name, const QString debate_time, const Debate debate, const std::vector<Speechcontent> contents) :
    time(time), name(name), debate_time(debate_time), debate(debate), contents(contents)
{
}

QString Speech::getTime() const
{
    return time;
}

QString Speech::getName() const
{
    return name;
}

QString Speech::getDebateTime() const
{
    return debate_time;
}

Debate Speech::getDebate() const
{
    return debate;
}

std::vector<Speechcontent> Speech::getContents() const
{
    return contents;
}


