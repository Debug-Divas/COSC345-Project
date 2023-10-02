#ifndef ELECTIONSTATISTICSSUB_H
#define ELECTIONSTATISTICSSUB_H

#include <QDialog>

namespace Ui {
class electionStatisticsSub;
}

class electionStatisticsSub : public QDialog
{
    Q_OBJECT

public:
    explicit electionStatisticsSub(QWidget *parent = nullptr);
    ~electionStatisticsSub();
    void setButtonHighlight(QPushButton *button);

private slots:
    void on_Stats1_clicked();

    void on_Stats2_clicked();

    void on_Stats3_clicked();

private:
    Ui::electionStatisticsSub *ui;

    void clearImageDisplay();
};

#endif // ELECTIONSTATISTICSSUB_H
