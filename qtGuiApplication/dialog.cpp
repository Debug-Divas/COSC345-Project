// dialog.cpp
#include "dialog.h"
#include "ui_dialog.h"
#include "parties.h"
#include "partyact.h"
#include "partygreen.h"
#include "partynational.h"
#include "partymaori.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_actButton_clicked()
{
    // Create an instance of the 'parties' class
    partyACT *party1 = new partyACT(this); //

    // Show the 'parties' dialog
    party1->exec();
}


void Dialog::on_labourButton_clicked()
{
    // Create an instance of the 'parties' class
    parties *party2 = new parties(this); // Assuming 'this' is the parent widget

    // Show the 'parties' dialog
    party2->exec(); // Use exec() for modal dialog or show() for modeless
}



void Dialog::on_greenButton_clicked()
{
    partyGREEN *party3 = new partyGREEN(this);
    party3->exec();
}

void Dialog::on_nationalButton_clicked()
{
    partyNATIONAL *party4 = new partyNATIONAL(this);
    party4->exec();
}

void Dialog::on_maoriButton_clicked()
{
    partyMAORI *party5 = new partyMAORI(this);
    party5->exec();
}
