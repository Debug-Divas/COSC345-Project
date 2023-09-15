#include "partymaori.h"
#include "ui_partymaori.h"

partyMAORI::partyMAORI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partyMAORI)
{
    ui->setupUi(this);
}

partyMAORI::~partyMAORI()
{
    delete ui;
}
