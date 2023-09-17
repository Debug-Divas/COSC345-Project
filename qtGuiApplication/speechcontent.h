#ifndef SPEECHCONTENT_H
#define SPEECHCONTENT_H

#include <QString>
#include <QStringList>
#include <QDateTime>

class Speechcontent
{
public:
    Speechcontent();
    Speechcontent(const int id, const QString type, const QString name, const QString speechTime, const QString text);

    int getId() const;
    QString getType() const;
    QString getName() const;
    QString getSpeechTime() const;
    QString getText() const;

private:
    int id;
    QString type;
    QString name;
    QString speech_time;
    QString text;
};

#endif // MP_H
