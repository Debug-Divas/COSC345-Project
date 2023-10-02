#include "electionstatisticssub.h"
#include "ui_electionstatisticssub.h"

electionStatisticsSub::electionStatisticsSub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::electionStatisticsSub)
{
    ui->setupUi(this);
}

electionStatisticsSub::~electionStatisticsSub()
{
    delete ui;
}



