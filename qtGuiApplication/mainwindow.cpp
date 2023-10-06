#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "dialog.h"
#include "expandedcard.h"
#include "parties.h"
#include "electionstatisticssub.h"
#include "emptycard.h"
#include <QDebug>
#include <QBoxLayout>
#include <dbmanager.h>
#include <QPixmap>
#include <QLabel>
static const QString path = "parliament.db";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MP Insight by Debug Divas!");
    expandedCard = nullptr;
    on_peopleButton_clicked();
}

MainWindow::~MainWindow()
{
    clearCardsLayout();
    delete ui;
}



void MainWindow::setButtonHighlight(QPushButton *button)
{
    // Remove any existing styles from all buttons
    ui->peopleButton->setStyleSheet("");
    ui->partiesButton->setStyleSheet("");
    ui->electionStatsButton->setStyleSheet("");

    // Apply the highlightedButton stylesheet to the specified button
    button->setStyleSheet("background-color: lightblue;");
}

void MainWindow::handleExpandButtonClicked(MP mp)
{
    Card *senderCard = qobject_cast<Card*>(sender());
    if (senderCard) {
        if (expandedCard) {
            delete expandedCard;
        }

        expandedCard = new ExpandedCard(mp);
        connect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked);
        ui->CardsLayout->addWidget(expandedCard);
        senderCard->hide();

        // Hide all existing cards
        for (Card *card : cards) {
            card->hide();
        }
    }
}

void MainWindow::handleOkButtonClicked()
{
        for (Card *card : cards) {
            card->show();
        }

        if (expandedCard) {
            ui->CardsLayout->removeWidget(expandedCard);
            delete expandedCard;
            expandedCard = nullptr;
        }
}

void MainWindow::on_peopleButton_clicked()
{

    setButtonHighlight(ui->peopleButton);
    DbManager db(path);
    std::vector<MP> mps;
    removeParties();
    ui->filterOptions->show();
    ui->scrollArea->show();
    if (db.isOpen())
    {
        mps = db.getAllMps();
        if (!mps.empty())
        {
            showMpsOnScreen(mps);
        }
        else {
            qDebug() << "No mps found";
        }
    }
    else
    {
        qDebug() << "Couldn't open mps";
    }

}

void MainWindow::showMpsOnScreen(std::vector<MP> mps) {
    clearCardsLayout();

    if(mps.empty()){
        EmptyCard *emptyCard = new EmptyCard;
        ui->CardsLayout->addWidget(emptyCard);
        qDebug() << "No mps found";
    }

    int maxColumns = 3; // Maximum number of cards per row
    int currentColumn = 0;
    int currentRow = 0;

    for (size_t i = 0; i < mps.size(); ++i) {
        Card* card = new Card(mps[i]);
        ui->CardsLayout->addWidget(card, currentRow, currentColumn);

        // Update column and row positions
        ++currentColumn;
        if (currentColumn >= maxColumns) {
            currentColumn = 0;
            ++currentRow;
        }

        cards.push_back(card);

        connect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
    }
}

void MainWindow::clearCardsLayout()
{
    for (Card *card : cards) {
        disconnect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
        card->hide();
        card->deleteLater();
    }
    cards.clear();

    if (expandedCard) {
        delete expandedCard;
        expandedCard = nullptr;
    }

    QLayoutItem *item;
    while ((item = ui->CardsLayout->takeAt(0)) != nullptr) {
        QWidget *widget = item->widget();
        if (widget) {
            delete widget;
        }
        delete item;
    }
}
bool findSpecialChar(QString str){
    QString strComp = "àáâãäåāæçèéêëēīìíîïðñòóôõöō÷øùúûüūýþÿ";
        for(size_t i = 0; i < str.size(); ++i){
            if(strComp.contains(str[i].toLower())){
                return true;
            }
        }
    return false;
}

QString replaceSpecialChar(QString str){
    QString strA = "àáâãäā";
    QString strE = "èéêëēe";
    QString strI = "īìíîïi";
    QString strO = "òóôõöō";
    QString strU = "ùúûüūu";
        for(size_t i = 0; i < strA.size();i++){
            str.replace(strA[i],"a").replace(strE[i],"e").replace(strU[i],"u");
            str.replace(strO[i],"o").replace("ç","c").replace(strI[i],"i");
        }
    return str;

}
void MainWindow::on_filterButton_clicked()
{
    QString searchQuery = ui->searchQuery->text();
    QString partyQuery = ui->partyQuery->currentText();
    QString typeMP = ui->typeMP->currentText();
    QString electorades = ui ->electorates ->currentText();
    qDebug() << searchQuery << " " << partyQuery << " " << typeMP;

    DbManager db(path);
    std::vector<MP> mps;

    if (db.isOpen())
    {

        if (partyQuery == "All") {
            mps = db.getAllMps();
        }
        else {
            mps = db.getAllMpsFromParty(partyQuery);
        }
        if(electorades == "All"){

        }
        else{
            std::vector<MP> temp;
            for(size_t i=0; i<mps.size();i++){
                if(mps[i].getElectorate() == electorades){
                    temp.push_back(mps[i]);
                    break;
                }
            }
            mps = temp;
        }
        if (!mps.empty())
        {
            std::vector<MP> filteredMps;
            if (!searchQuery.isEmpty()) {
                showMpsOnScreen(mps);
                bool specialChar = false;
                QString compString;
                if(findSpecialChar(searchQuery)){
                    specialChar = true;
                }
                for (size_t i = 0; i < mps.size(); ++i) {
                    if(specialChar){
                        compString = mps[i].getName().toLower();
                    }
                    else{

                        compString= replaceSpecialChar(mps[i].getName().toLower());
                    }
                    if (compString.contains(searchQuery.toLower())) {
                        filteredMps.push_back(mps[i]);
                    }
                    else if (mps[i].getParty().contains(searchQuery)) {
                        filteredMps.push_back(mps[i]);
                    }
                    else if (mps[i].getElectorate().contains(searchQuery)) {
                        filteredMps.push_back(mps[i]);
                    }
                }
            }
            else {
                filteredMps = mps;

            }
            std::vector<MP> typeFilter;
            if(typeMP == "All"){
                showMpsOnScreen(filteredMps);
            }
            else{
                for (size_t i = 0; i < filteredMps.size(); ++i) {

                    if(typeMP == "List MP"){
                        qDebug() << "in List MP";
                        if(filteredMps[i].getElectorate() == ""){
                            typeFilter.push_back(filteredMps[i]);
                        }
                    }
                    else if(typeMP == "Electorates MP"){
                        qDebug() << "IN Elect";
                        if(filteredMps[i].getElectorate() != ""){
                            typeFilter.push_back(filteredMps[i]);
                        }
                    }

                }
                showMpsOnScreen(typeFilter);
            }
        }
        else {
            showMpsOnScreen(mps);
        }
    }
    else
    {
        clearCardsLayout();
        EmptyCard *emptyCard = new EmptyCard;
        ui->CardsLayout->addWidget(emptyCard);
        qDebug() << "Couldn't open mps";
    }
}


void MainWindow::on_partiesButton_clicked()
{
    setButtonHighlight(ui->partiesButton);
    clearCardsLayout();
    ui->filterOptions->hide();
    ui->scrollArea->hide();
    Dialog *dialog = new Dialog;

    // Create a QVBoxLayout for frame_5 if it doesn't have one
    if (!ui->frame_5->layout()) {
        QVBoxLayout* newLayout = new QVBoxLayout(ui->frame_5);
        ui->frame_5->setLayout(newLayout);
    }

    QVBoxLayout* frameLayout = qobject_cast<QVBoxLayout*>(ui->frame_5->layout());
    if (frameLayout) {
        // Remove existing widgets from frameLayout
        QLayoutItem* item;
        while ((item = frameLayout->takeAt(0)) != nullptr) {
            QWidget* widget = item->widget();
            if (widget) {
                widget->deleteLater();
            }
            delete item;
        }

        // Add the Dialog to frameLayout
        frameLayout->addWidget(dialog);
    }
}

void MainWindow::removeParties()
{
    QVBoxLayout* frameLayout = qobject_cast<QVBoxLayout*>(ui->frame_5->layout());
    if (frameLayout) {
        // Remove existing widgets from frameLayout
        QLayoutItem* item;
        while ((item = frameLayout->takeAt(0)) != nullptr) {
            QWidget* widget = item->widget();
            if (widget) {
                widget->deleteLater();
            }
            delete item;
        }
    }
}




void MainWindow::on_electionStatsButton_clicked()
{
    setButtonHighlight(ui->electionStatsButton);
    clearCardsLayout();
    ui->filterOptions->hide();
    ui->scrollArea->hide();
    electionStatisticsSub *electSub = new electionStatisticsSub;

    // Create a QVBoxLayout for frame_5 if it doesn't have one
    if (!ui->frame_5->layout()) {
        QVBoxLayout* newLayout = new QVBoxLayout(ui->frame_5);
        ui->frame_5->setLayout(newLayout);
    }

    QVBoxLayout* frameLayout = qobject_cast<QVBoxLayout*>(ui->frame_5->layout());
    if (frameLayout) {
        // Remove existing widgets from frameLayout
        QLayoutItem* item;
        while ((item = frameLayout->takeAt(0)) != nullptr) {
            QWidget* widget = item->widget();
            if (widget) {
                widget->deleteLater();
            }
            delete item;
        }

        // Add the Dialog to frameLayout
        frameLayout->addWidget(electSub);
}
}
