/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *peopleButton;
    QPushButton *partiesButton;
    QPushButton *electoratesButton;
    QPushButton *billsButton;
    QPushButton *electionStatsButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *searchQuery;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *partyQuery;
    QPushButton *filterButton;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *CardsLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1127, 611);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        peopleButton = new QPushButton(frame);
        peopleButton->setObjectName("peopleButton");

        horizontalLayout->addWidget(peopleButton);

        partiesButton = new QPushButton(frame);
        partiesButton->setObjectName("partiesButton");

        horizontalLayout->addWidget(partiesButton);

        electoratesButton = new QPushButton(frame);
        electoratesButton->setObjectName("electoratesButton");

        horizontalLayout->addWidget(electoratesButton);

        billsButton = new QPushButton(frame);
        billsButton->setObjectName("billsButton");

        horizontalLayout->addWidget(billsButton);

        electionStatsButton = new QPushButton(frame);
        electionStatsButton->setObjectName("electionStatsButton");

        horizontalLayout->addWidget(electionStatsButton);


        gridLayout->addWidget(frame, 0, 0, 1, 2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(60);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(200, 500));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        frame_2 = new QFrame(widget);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setMinimumSize(QSize(90, 10));
        frame_2->setMaximumSize(QSize(16777215, 40));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(label);

        searchQuery = new QLineEdit(frame_2);
        searchQuery->setObjectName("searchQuery");
        searchQuery->setMaximumSize(QSize(9090909, 25));

        horizontalLayout_2->addWidget(searchQuery);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(widget);
        frame_3->setObjectName("frame_3");
        frame_3->setMaximumSize(QSize(16777215, 40));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(40, 50));

        horizontalLayout_3->addWidget(label_2);

        partyQuery = new QComboBox(frame_3);
        partyQuery->addItem(QString());
        partyQuery->addItem(QString());
        partyQuery->addItem(QString());
        partyQuery->addItem(QString());
        partyQuery->addItem(QString());
        partyQuery->addItem(QString());
        partyQuery->addItem(QString());
        partyQuery->setObjectName("partyQuery");

        horizontalLayout_3->addWidget(partyQuery);


        verticalLayout->addWidget(frame_3);

        filterButton = new QPushButton(widget);
        filterButton->setObjectName("filterButton");

        verticalLayout->addWidget(filterButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setMinimumSize(QSize(900, 490));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 898, 488));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(3);
        sizePolicy4.setVerticalStretch(3);
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy4);
        CardsLayout = new QGridLayout(scrollAreaWidgetContents_2);
        CardsLayout->setObjectName("CardsLayout");
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1127, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        peopleButton->setText(QCoreApplication::translate("MainWindow", "People", nullptr));
        partiesButton->setText(QCoreApplication::translate("MainWindow", "Parties", nullptr));
        electoratesButton->setText(QCoreApplication::translate("MainWindow", "Electorates", nullptr));
        billsButton->setText(QCoreApplication::translate("MainWindow", "Bills", nullptr));
        electionStatsButton->setText(QCoreApplication::translate("MainWindow", "Election Statistics", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Search:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Parties:</span></p></body></html>", nullptr));
        partyQuery->setItemText(0, QCoreApplication::translate("MainWindow", "All", nullptr));
        partyQuery->setItemText(1, QCoreApplication::translate("MainWindow", "Labour Party", nullptr));
        partyQuery->setItemText(2, QCoreApplication::translate("MainWindow", "National Party", nullptr));
        partyQuery->setItemText(3, QCoreApplication::translate("MainWindow", "Green Party", nullptr));
        partyQuery->setItemText(4, QCoreApplication::translate("MainWindow", "Te P\304\201ti M\304\201ori", nullptr));
        partyQuery->setItemText(5, QCoreApplication::translate("MainWindow", "ACT New Zealand", nullptr));
        partyQuery->setItemText(6, QCoreApplication::translate("MainWindow", "Independent", nullptr));

        filterButton->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
