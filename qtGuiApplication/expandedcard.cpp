#include "expandedcard.h"
#include "ui_expandedcard.h"
#include "mainwindow.h"
#include <QDialogButtonBox>

#include "mp.h"
#include "finances.h"

ExpandedCard::ExpandedCard(QWidget *parent) : QDialog(parent), ui(new Ui::ExpandedCard)
{
    ui->setupUi(this);

    // Assuming the QDialogButtonBox in the UI file is named 'okButton'
    connect(ui->okButton, &QDialogButtonBox::accepted, this, &ExpandedCard::on_okButton_accepted);
    connect(ui->okButton, &QDialogButtonBox::rejected, this, &ExpandedCard::deleteLater);
}

ExpandedCard::ExpandedCard(MP mp) : ui(new Ui::ExpandedCard)
{
    this->mp = mp;
    ui->setupUi(this);

    ui->Name->setText(mp.getName());
    ui->Party->setText(mp.getParty());

    ui->Portrait->setPixmap(QPixmap("../images/portraits/" + mp.getName() + ".jpg"));

    // Assuming the QDialogButtonBox in the UI file is named 'okButton'
    connect(ui->okButton, &QDialogButtonBox::accepted, this, &ExpandedCard::on_okButton_accepted);
    connect(ui->okButton, &QDialogButtonBox::rejected, this, &ExpandedCard::deleteLater);
}

ExpandedCard::~ExpandedCard()
{
    delete ui;
}

void ExpandedCard::on_okButton_accepted()
{
    //Test1
    qDebug() << "OK Button Accepted"; // Debug message
    // Emit the custom signal okButtonClicked() when the "OK" button is clicked
    emit okButtonClicked();
}


void ExpandedCard::on_TranscriptsButton_clicked()
{
    qDebug() << "Transcripts Button clicked";
}


void ExpandedCard::on_FinancesButton_clicked()
{
    qDebug() << "Finances Button clicked";
}


void ExpandedCard::on_VotesButton_clicked()
{
    qDebug() << "Votes Button clicked";

}

