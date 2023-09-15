#ifndef PARTYGREEN_H
#define PARTYGREEN_H

#include <QDialog>

namespace Ui {
class partyGREEN;
}

class partyGREEN : public QDialog
{
    Q_OBJECT

public:
    explicit partyGREEN(QWidget *parent = nullptr);
    ~partyGREEN();

private:
    Ui::partyGREEN *ui;
};

#endif // PARTYGREEN_H
