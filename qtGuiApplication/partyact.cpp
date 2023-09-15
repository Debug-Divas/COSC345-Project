#include "partyact.h"
#include "ui_partyact.h"

partyACT::partyACT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partyACT)
{
    ui->setupUi(this);
}

partyACT::~partyACT()
{
    delete ui;
}
