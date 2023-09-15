#include "partygreen.h"
#include "ui_partygreen.h"

partyGREEN::partyGREEN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partyGREEN)
{
    ui->setupUi(this);
}

partyGREEN::~partyGREEN()
{
    delete ui;
}
