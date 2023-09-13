#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_labourButton_clicked();

    void on_actButton_clicked();

    void on_greenButton_clicked();

    void on_nationalButton_clicked();

    void on_maoriButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
