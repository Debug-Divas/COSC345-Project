#include <QStringList>
#include <QDateTime>
#include "speechcontent.h"

Speechcontent::Speechcontent()
{
}

Speechcontent::Speechcontent(const int id, const QString type, const QString name, const QString speech_time, const QString text) :
    id(id), type(type), name(name), speech_time(speech_time), text(text)
{
}

int Speechcontent::getId() const
{
    return id;
}

QString Speechcontent::getType() const
{
    return type;
}

QString Speechcontent::getName() const
{
    return name;
}

QString Speechcontent::getSpeechTime() const
{
    return speech_time;
}

QString Speechcontent::getText() const
{
    return text;
}
