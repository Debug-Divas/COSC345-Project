#ifndef PARTYNATIONAL_H
#define PARTYNATIONAL_H

#include <QDialog>

namespace Ui {
class partyNATIONAL;
}

class partyNATIONAL : public QDialog
{
    Q_OBJECT

public:
    explicit partyNATIONAL(QWidget *parent = nullptr);
    ~partyNATIONAL();

private:
    Ui::partyNATIONAL *ui;
};

#endif // PARTYNATIONAL_H
