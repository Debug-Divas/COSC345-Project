#include "partynational.h"
#include "ui_partynational.h"

partyNATIONAL::partyNATIONAL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partyNATIONAL)
{
    ui->setupUi(this);
}

partyNATIONAL::~partyNATIONAL()
{
    delete ui;
}
