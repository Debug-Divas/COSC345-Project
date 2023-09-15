/********************************************************************************
** Form generated from reading UI file 'partyact.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTYACT_H
#define UI_PARTYACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_partyACT
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *partyACT)
    {
        if (partyACT->objectName().isEmpty())
            partyACT->setObjectName("partyACT");
        partyACT->resize(623, 341);
        verticalLayout = new QVBoxLayout(partyACT);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(partyACT);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName("textBrowser");

        verticalLayout_2->addWidget(textBrowser);


        verticalLayout->addWidget(frame);


        retranslateUi(partyACT);

        QMetaObject::connectSlotsByName(partyACT);
    } // setupUi

    void retranslateUi(QDialog *partyACT)
    {
        partyACT->setWindowTitle(QCoreApplication::translate("partyACT", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("partyACT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<h1 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:105.769%; background-color:#ffffff;\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:xx-large; font-weight:700; color:#000000; background-color:#ffffff;\">ACT Party</span></h1>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:105.769%; background-color:#ffffff;\"><br /><sp"
                        "an style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:18px; color:#000000; background-color:#ffffff;\">The ACT Party has 10 members of Parliament, 9 from the party list and one electorate seat.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:105.769%; background-color:#ffffff;\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:18px; color:#000000; background-color:#ffffff;\"><br /></span><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:medium; font-weight:700; color:#000000; background-color:#ffffff;\">ACT New Zealand in Parliament</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:171.429%; background-color:#ffffff;\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:14px; color:#000000; background-colo"
                        "r:#ffffff;\">ACT New Zealand first registered with the Electoral Commission in February 1995 and entered Parliament in 1996.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:171.429%; background-color:#ffffff;\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:14px; color:#000000; background-color:#ffffff;\">The party leader is\302\240</span><a href=\"https://www.parliament.nz/en/mps-and-electorates/members-of-parliament/seymour-david/\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:14px; font-weight:700; text-decoration: underline; color:#007179;\">David Seymour</span></a><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:14px; color:#000000;\">.</span></p>\n"
"<h4 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:116.667%; background-color:#"
                        "ffffff;\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:medium; font-weight:700; color:#000000; background-color:#ffffff;\">ACT\302\240Principles</span></h4>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:171.429%; background-color:#ffffff;\"><span style=\" font-family:'Open Sans','Arial','Verdana','sans-serif'; font-size:14px; font-style:italic; color:#000000;\">'The principal object of the Party is to promote an open and benevolent society in which individual New Zealanders are free to achieve their full potential.'</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class partyACT: public Ui_partyACT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTYACT_H
