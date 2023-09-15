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

    Show_Financials();
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

    Show_Financials();

}


void ExpandedCard::on_VotesButton_clicked()
{
    qDebug() << "Votes Button clicked";
    ui->page_contents->setText("votes");

}

void ExpandedCard::Show_Financials(){

    QString text = "";

    if(mp.getFinances().getCompanyDirectorships()[0] != ""){
        text += "<b>Company directorships and controlling interests</b><br>";
        for(int i = 0; i < mp.getFinances().getCompanyDirectorships().size(); i++){
            text += mp.getFinances().getCompanyDirectorships()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getOtherCompanies()[0] != ""){
        text += "<b>Interests (such as shares and bonds) in companies and business entities</b><br>";
        for(int i = 0; i < mp.getFinances().getOtherCompanies().size(); i++){
            text += mp.getFinances().getOtherCompanies()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getEmployment()[0] != ""){
        text += "<b>Employment</b><br>";
        for(int i = 0; i < mp.getFinances().getEmployment().size(); i++){
            text += mp.getFinances().getEmployment()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getInterestTrust()[0] != ""){
        text += "<b>Interests in trusts</b><br>";
        for(int i = 0; i < mp.getFinances().getInterestTrust().size(); i++){
            text += mp.getFinances().getInterestTrust()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getOrganizations()[0] != ""){
        text += "<b>Organisations and trusts seeking Government funding</b><br>";
        for(int i = 0; i < mp.getFinances().getOrganizations().size(); i++){
            text += mp.getFinances().getOrganizations()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getProperty()[0] != ""){
        text += "<b>Real property</b><br>";
        for(int i = 0; i < mp.getFinances().getProperty().size(); i++){
            text += mp.getFinances().getProperty()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getRetirement()[0] != ""){
        text += "<b>Retirement schemes</b><br>";
        for(int i = 0; i < mp.getFinances().getRetirement().size(); i++){
            text += mp.getFinances().getRetirement()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getInvestmentSchemes()[0] != ""){
        text += "<b>Managed investment schemes</b><br>";
        for(int i = 0; i < mp.getFinances().getInvestmentSchemes().size(); i++){
            text += mp.getFinances().getInvestmentSchemes()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getDebtsToYou()[0] != ""){
        text += "<b>Debts owed to a member</b><br>";
        for(int i = 0; i < mp.getFinances().getDebtsToYou().size(); i++){
            text += mp.getFinances().getDebtsToYou()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getDebtsOwedByYou()[0] != ""){
        text += "<b>Debts owed by a member</b><br>";
        for(int i = 0; i < mp.getFinances().getDebtsOwedByYou().size(); i++){
            text += mp.getFinances().getDebtsOwedByYou()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getOverseasTravel()[0] != ""){
        text += "<b>Overseas travel</b><br>";
        for(int i = 0; i < mp.getFinances().getOverseasTravel().size(); i++){
            text += mp.getFinances().getOverseasTravel()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getGifts()[0] != ""){
        text += "<b>Gifts</b><br>";
        for(int i = 0; i < mp.getFinances().getGifts().size(); i++){
            text += mp.getFinances().getGifts()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    if(mp.getFinances().getPaymentActivities()[0] != ""){
        text += "<b>Payments for activities</b><br>";
        for(int i = 0; i < mp.getFinances().getPaymentActivities().size(); i++){
            text += mp.getFinances().getPaymentActivities()[i];
            text += "<br>";
        }
        text += "<br>";
    }

    ui->page_contents->setText(text);
}
