// dialog.cpp
#include "dialog.h"
#include "ui_dialog.h"
#include "parties.h"

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

void Dialog::on_labourButton_clicked()
{
    // Create an instance of the 'parties' class
    parties *party1 = new parties(this); // Assuming 'this' is the parent widget

    // Show the 'parties' dialog
    party1->exec(); // Use exec() for modal dialog or show() for modeless
}

void Dialog::on_actButton_clicked()
{
    // Create an instance of the 'parties' class
    parties *party2 = new parties(this);

    // Show the 'parties' dialog
    party2->exec();
}

void Dialog::on_greenButton_clicked()
{
    parties *party3 = new parties(this);
    party3->exec();
}

void Dialog::on_nationalButton_clicked()
{
    parties *party4 = new parties(this);
    party4->exec();
}

void Dialog::on_maoriButton_clicked()
{
    parties *party5 = new parties(this);
    party5->exec();
//    party5->deleteLater();

}
