//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
#include <stdio.h>
#include "../qtGuiApplication/dbmanager.h"
#include "../qtGuiApplication/mp.h"
//#include "include/QtGui/QApplication"
//#include "include/QtWidgets/QWidget"

int another(int param)
{
    puts("Something");
    if (param == 0)
        puts("Zero");
    else
        puts("non Zero");

    return 0;
}

bool test_mp_name()
{

    static const QString path = "parliament.db";

    DbManager db(path);

    QString name = "Jamie Strange";

    MP mp = db.getMpFromName(name);

    return name == mp.getName();
}

bool test_mp_name_special()
{

    static const QString path = "parliament.db";

    DbManager db(path);

    // Testing for three different types of diacritics over letters
    QString name1 = "Tāmati Coffey";
    QString name2 = "Chlöe Swarbrick";
    QString name3 = "Ricardo Menéndez March";

    MP mp1 = db.getMpFromName(name1);
    MP mp2 = db.getMpFromName(name2);
    MP mp3 = db.getMpFromName(name3);

    return (name1 == mp1.getName() && name2 == mp2.getName() && name3 == mp3.getName());
}

bool test_get_all_mps()
{
    static const QString path = "little_parliament.db";

    DbManager db(path);

    std::vector<MP> all_mps = db.getAllMps();

    std::vector<QString> names = {"Kiritapu Allan", "Ginny Andersen", "Chris Baillie"};

    for (unsigned int i = 0; i < 3; i++)
    {
        if (all_mps[i].getName() != names[i])
        {
            printf("what");
            return false;
        }
    }
    return true;
}


int main(int argc, char *argv[])
{
    puts("main");

    for (int x = 0; x < 10; x++)
        printf("%d\n", x);
    another(0);
    puts("main fin");

    printf("MP name test: %d\n", test_mp_name());
    printf("MP special character test: %d\n", test_mp_name_special());
    printf("Get all mps: %d\n", test_get_all_mps());

    return 0;
}
