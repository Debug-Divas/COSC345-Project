#ifndef EMPTYCARD_H
#define EMPTYCARD_H

#include <QDialog>

namespace Ui {
class EmptyCard;
}

class EmptyCard : public QDialog
{
    Q_OBJECT

public:
    explicit EmptyCard(QWidget *parent = nullptr);
    ~EmptyCard();

private:
    Ui::EmptyCard *ui;
};

#endif // EMPTYCARD_H
