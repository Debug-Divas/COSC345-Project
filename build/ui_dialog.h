/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *actButton;
    QPushButton *labourButton;
    QPushButton *greenButton;
    QPushButton *nationalButton;
    QPushButton *maoriButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1060, 238);
        horizontalLayout_2 = new QHBoxLayout(Dialog);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(Dialog);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        actButton = new QPushButton(frame);
        actButton->setObjectName("actButton");
        actButton->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../images/parties/act.png"), QSize(), QIcon::Normal, QIcon::Off);
        actButton->setIcon(icon);
        actButton->setIconSize(QSize(180, 190));

        horizontalLayout->addWidget(actButton);

        labourButton = new QPushButton(frame);
        labourButton->setObjectName("labourButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../images/parties/labour.png"), QSize(), QIcon::Normal, QIcon::Off);
        labourButton->setIcon(icon1);
        labourButton->setIconSize(QSize(180, 190));

        horizontalLayout->addWidget(labourButton);

        greenButton = new QPushButton(frame);
        greenButton->setObjectName("greenButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../images/parties/green.png"), QSize(), QIcon::Normal, QIcon::Off);
        greenButton->setIcon(icon2);
        greenButton->setIconSize(QSize(180, 190));

        horizontalLayout->addWidget(greenButton);

        nationalButton = new QPushButton(frame);
        nationalButton->setObjectName("nationalButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../images/parties/national.png"), QSize(), QIcon::Normal, QIcon::Off);
        nationalButton->setIcon(icon3);
        nationalButton->setIconSize(QSize(180, 190));

        horizontalLayout->addWidget(nationalButton);

        maoriButton = new QPushButton(frame);
        maoriButton->setObjectName("maoriButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../images/parties/maori.png"), QSize(), QIcon::Normal, QIcon::Off);
        maoriButton->setIcon(icon4);
        maoriButton->setIconSize(QSize(180, 190));

        horizontalLayout->addWidget(maoriButton);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        actButton->setText(QString());
        labourButton->setText(QString());
        greenButton->setText(QString());
        nationalButton->setText(QString());
        maoriButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
