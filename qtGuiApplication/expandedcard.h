#ifndef EXPANDEDCARD_H
#define EXPANDEDCARD_H

#include <QDialog>
#include "mp.h"

namespace Ui {
class ExpandedCard;
}

class ExpandedCard : public QDialog
{
    Q_OBJECT

public:
    explicit ExpandedCard(QWidget *parent = nullptr);
    explicit ExpandedCard(MP mp);
    ~ExpandedCard();
    void setButtonHighlight(QPushButton *button);
private:
    Ui::ExpandedCard *ui;
    MP mp;
    void Show_Financials();
signals:
    void okButtonClicked(); // Add the signal for the "OK" button

private slots:
    void on_okButton_accepted();
    void on_TranscriptsButton_clicked();
    void on_FinancesButton_clicked();
    void on_VotesButton_clicked();
};

#endif // EXPANDEDCARD_H
