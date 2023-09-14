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
    ui->Electorate->setText(mp.getJobTitle() );

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
    ui->page_contents->setText("transcripts");
}


void ExpandedCard::on_FinancesButton_clicked()
{
    qDebug() << "Finances Button clicked";
    QString text = "";

   // Vector<QString> fins = ["company_directorships", "other_companies", "employment", "interest_trust", "organizations"];

    ui->page_contents->setText("finances");
    ui->page_contents->
//     property, retirement, investment_schemes, debts_to_you, debts_owed_by_you, overseas_travel, gifts, payment_activities) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

}


void ExpandedCard::on_VotesButton_clicked()
{
    qDebug() << "Votes Button clicked";
    ui->page_contents->setText("votes");

}

