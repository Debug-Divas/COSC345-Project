#ifndef PARTYACT_H
#define PARTYACT_H

#include <QDialog>

namespace Ui {
class partyACT;
}

class partyACT : public QDialog
{
    Q_OBJECT

public:
    explicit partyACT(QWidget *parent = nullptr);
    ~partyACT();

private:
    Ui::partyACT *ui;
};

#endif // PARTYACT_H
