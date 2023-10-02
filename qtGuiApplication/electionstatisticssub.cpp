#include "electionstatisticssub.h"
#include "ui_electionstatisticssub.h"
#include <QLabel>

electionStatisticsSub::electionStatisticsSub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::electionStatisticsSub)
{
    ui->setupUi(this);

    // Create a QVBoxLayout for ImageDisplay and set it as its layout
    QVBoxLayout *imageDisplayLayout = new QVBoxLayout(ui->ImageDisplay);
    ui->ImageDisplay->setLayout(imageDisplayLayout);
}

electionStatisticsSub::~electionStatisticsSub()
{
    delete ui;
}

void electionStatisticsSub::clearImageDisplay()
{
    // Get the existing layout of ImageDisplay
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->ImageDisplay->layout());

    // Remove all child widgets from the layout and delete them
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void electionStatisticsSub::on_Stats1_clicked()
{
    // Clear the frame first
    clearImageDisplay();

    QPixmap pixmap("../images/Votes.PNG");

    // Create a QLabel to display the image
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setPixmap(pixmap);
    imageLabel->setScaledContents(true);

    // Get the existing layout of ImageDisplay
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->ImageDisplay->layout());

    // Add the imageLabel to the layout
    layout->addWidget(imageLabel);
}

void electionStatisticsSub::on_Stats2_clicked()
{
    // Clear the frame first
    clearImageDisplay();

    QPixmap pixmap("../images/HouseTurnOver.PNG");

    // Create a QLabel to display the image
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setPixmap(pixmap);
    imageLabel->setScaledContents(true);

    // Get the existing layout of ImageDisplay
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->ImageDisplay->layout());

    // Add the imageLabel to the layout
    layout->addWidget(imageLabel);
}

void electionStatisticsSub::on_Stats3_clicked()
{
    // Clear the frame first
    clearImageDisplay();

    QPixmap pixmap("../images/ElectoratesMap.PNG");

    // Create a QLabel to display the image
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setPixmap(pixmap);
    imageLabel->setScaledContents(true);

    // Get the existing layout of ImageDisplay
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->ImageDisplay->layout());

    // Add the imageLabel to the layout
    layout->addWidget(imageLabel);
}
