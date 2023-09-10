/********************************************************************************
** Form generated from reading UI file 'expandedcard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPANDEDCARD_H
#define UI_EXPANDEDCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpandedCard
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *TranscriptsButton;
    QPushButton *FinancesButton;
    QPushButton *VotesButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QLabel *Party;
    QLabel *Portrait;
    QDialogButtonBox *okButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;

    void setupUi(QDialog *ExpandedCard)
    {
        if (ExpandedCard->objectName().isEmpty())
            ExpandedCard->setObjectName("ExpandedCard");
        ExpandedCard->resize(1023, 469);
        gridLayout = new QGridLayout(ExpandedCard);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(ExpandedCard);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(16777215, 60));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        TranscriptsButton = new QPushButton(frame);
        TranscriptsButton->setObjectName("TranscriptsButton");

        horizontalLayout->addWidget(TranscriptsButton);

        FinancesButton = new QPushButton(frame);
        FinancesButton->setObjectName("FinancesButton");

        horizontalLayout->addWidget(FinancesButton);

        VotesButton = new QPushButton(frame);
        VotesButton->setObjectName("VotesButton");

        horizontalLayout->addWidget(VotesButton);


        gridLayout->addWidget(frame, 6, 0, 1, 3);

        widget = new QWidget(ExpandedCard);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        Name = new QLabel(widget);
        Name->setObjectName("Name");
        Name->setMaximumSize(QSize(100, 30));

        verticalLayout->addWidget(Name);

        Party = new QLabel(widget);
        Party->setObjectName("Party");
        Party->setMaximumSize(QSize(170, 30));

        verticalLayout->addWidget(Party);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        Portrait = new QLabel(ExpandedCard);
        Portrait->setObjectName("Portrait");
        Portrait->setMaximumSize(QSize(100, 100));
        Portrait->setFrameShape(QFrame::NoFrame);
        Portrait->setFrameShadow(QFrame::Plain);
        Portrait->setPixmap(QPixmap(QString::fromUtf8("../images/wood-michael-TEST.jpg")));
        Portrait->setScaledContents(true);

        gridLayout->addWidget(Portrait, 0, 0, 1, 1);

        okButton = new QDialogButtonBox(ExpandedCard);
        okButton->setObjectName("okButton");
        okButton->setMaximumSize(QSize(50, 30));
        okButton->setOrientation(Qt::Horizontal);
        okButton->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(okButton, 0, 2, 1, 1);

        widget_2 = new QWidget(ExpandedCard);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 971, 354));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName("label");
        label->setMouseTracking(true);
        label->setLayoutDirection(Qt::RightToLeft);
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_2->addWidget(scrollArea);


        gridLayout->addWidget(widget_2, 7, 0, 1, 3);


        retranslateUi(ExpandedCard);

        QMetaObject::connectSlotsByName(ExpandedCard);
    } // setupUi

    void retranslateUi(QDialog *ExpandedCard)
    {
        ExpandedCard->setWindowTitle(QCoreApplication::translate("ExpandedCard", "Dialog", nullptr));
        TranscriptsButton->setText(QCoreApplication::translate("ExpandedCard", "Transcripts", nullptr));
        FinancesButton->setText(QCoreApplication::translate("ExpandedCard", "Finances", nullptr));
        VotesButton->setText(QCoreApplication::translate("ExpandedCard", "Votes", nullptr));
        Name->setText(QCoreApplication::translate("ExpandedCard", "<html><head/><body><p><span style=\" font-weight:700;\">Michael wood</span></p></body></html>", nullptr));
        Party->setText(QCoreApplication::translate("ExpandedCard", "<html><head/><body><p><span style=\" font-weight:700;\">Labour MP for Mt Roskill</span></p></body></html>", nullptr));
        Portrait->setText(QString());
        label->setText(QCoreApplication::translate("ExpandedCard", "So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs "
                        "raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man"
                        ". [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made thSo, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I gra"
                        "b my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously"
                        "]So, I grab my axe, hook up to the Marshal stack, an\342\200\231 ramp it all the way up to 11. The crowd didn\342\200\231t know what hit \342\200\230em. I really made their ears bleed, man. [laughs raucously]eir ears bleed, man. [laughs raucously]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpandedCard: public Ui_ExpandedCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPANDEDCARD_H
