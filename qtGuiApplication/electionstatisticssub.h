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

private:
    Ui::electionStatisticsSub *ui;
};

#endif // ELECTIONSTATISTICSSUB_H
