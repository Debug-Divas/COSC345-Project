#include "emptycard.h"
#include "ui_emptycard.h"

EmptyCard::EmptyCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmptyCard)
{
    ui->setupUi(this);
}

EmptyCard::~EmptyCard()
{
    delete ui;
}
