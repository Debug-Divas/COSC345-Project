#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "dialog.h"
#include "expandedcard.h"
#include "parties.h"
#include <QDebug>
#include <QBoxLayout>
#include <dbmanager.h>

static const QString path = "parliament.db";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    expandedCard = nullptr;
    on_peopleButton_clicked();
}

MainWindow::~MainWindow()
{
    clearCardsLayout();
    delete ui;
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

void MainWindow::on_filterButton_clicked()
{
    QString searchQuery = ui->searchQuery->text();
    QString partyQuery = ui->partyQuery->currentText();
    QString typeMP = ui->typeMP->currentText();
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

        if (!mps.empty())
        {
            std::vector<MP> filteredMps;
            if (!searchQuery.isEmpty()) {
                showMpsOnScreen(mps);
                for (size_t i = 0; i < mps.size(); ++i) {
                    if (mps[i].getName().toUpper().contains(searchQuery.toUpper())) {
                        qDebug() << mps[i].getName().toUpper();
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
                qDebug() << "Im here";
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
            qDebug() << "No mps found";
        }
    }
    else
    {
        qDebug() << "Couldn't open mps";
    }
}
void MainWindow::on_partiesButton_clicked()
{
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
//    ui->filterOptions->hide(); // Assuming the name of the filter bar widget is "filterOptions"

    qDebug() << "Election Stats Button Clicked";
}

