#ifndef PARTYMAORI_H
#define PARTYMAORI_H

#include <QDialog>

namespace Ui {
class partyMAORI;
}

class partyMAORI : public QDialog
{
    Q_OBJECT

public:
    explicit partyMAORI(QWidget *parent = nullptr);
    ~partyMAORI();

private:
    Ui::partyMAORI *ui;
};

#endif // PARTYMAORI_H
