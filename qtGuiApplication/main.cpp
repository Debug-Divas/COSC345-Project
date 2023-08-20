#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <dbmanager.h>


static const QString path = "parliament.db";

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DbManager db(path);

    if (db.isOpen())
    {
        
        std::vector<MP> mps = db.getAllMps();
        for (size_t i = 0; i < mps.size(); ++i) {
            qDebug() << "===" << mps[i].getName();
            qDebug() << "===" << mps[i].getElectorate();
            qDebug() << "===" << mps[i].getFinances().getProperty();
        }

        /*
        std::vector<Finances> finances = db.getAllFinances();
        for (size_t i = 0; i < finances.size(); ++i) {
            qDebug() << "===" << finances[i].getMpName();
            qDebug() << "===" << finances[i].getInterestTrust();
        }*/

        //db.createMpsTable();
        /*
        std::vector<MP> mps = db.getAllMps();
        for (size_t i = 0; i < mps.size(); ++i) {
            qDebug() << "===" << mps[i].getName();
            qDebug() << "===" << mps[i].getElectorate();
        }

        MP jamie = db.getMpFromName("Jamie Strange");
        qDebug() << "===" << jamie.getName();
*/
        /*
        db.createTable();   // Creates a table if it doens't exist. Otherwise, it will use existing table.
        db.addPerson("A");
        db.addPerson("B");
        db.addPerson("C");
        db.printAllPersons();
        db.removePerson("C");
        db.printAllPersons();
        db.removeAllPersons();*/
        qDebug() << "End";
    }
    else
    {
        qDebug() << "Database is not open!";
    }

    return a.exec();
}
