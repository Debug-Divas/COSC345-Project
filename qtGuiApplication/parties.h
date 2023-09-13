#ifndef PARTIES_H
#define PARTIES_H

#include <QDialog>

namespace Ui {
class parties;
}

class parties : public QDialog
{
    Q_OBJECT

public:
    explicit parties(QWidget *parent = nullptr);
    ~parties();

private:
    Ui::parties *ui;
};

#endif // PARTIES_H
