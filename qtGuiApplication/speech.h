#ifndef SPEECH_H
#define SPEECH_H

#include <QString>
#include <QStringList>
#include <QDateTime>

#include "debate.h"
#include "speechcontent.h"

class Speech
{
public:
    Speech();
    Speech(const QString time, const QString name, const QString debate_time, const Debate debate, const std::vector<Speechcontent> contents);

    QString getTime() const;
    QString getName() const;
    QString getDebateTime() const;
    Debate getDebate() const;
    std::vector<Speechcontent> getContents() const;
    void addContent(Speechcontent content);

private:
    QString time;
    QString name;
    QString debate_time;
    Debate debate;
    std::vector<Speechcontent> contents;
};

#endif // MP_H
