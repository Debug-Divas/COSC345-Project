#include "parties.h"
#include "ui_parties.h"

parties::parties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parties)
{
    ui->setupUi(this);
}

parties::~parties()
{
    delete ui;
}
