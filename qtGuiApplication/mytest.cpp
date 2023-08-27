#include <QtTest/QtTest>
#include "mp.h"
#include "dbmanager.h"

class MyTest : public QObject {
    Q_OBJECT

private:
    DbManager db;  // Create a DbManager instance for testing

    MP setupTestMP(QString name) {
        return db.getMpFromName(name);
    }

private slots:
    void initTestCase() {
        QString path = "parliament.db";
        db = DbManager(path);
        // Set up any other resources here
    }

    void cleanupTestCase() {
        // Clean up any resources if needed
    }

    bool function1(QString name, MP m) {
        return name == m.getName();
    }

    void test_function1() {
        MP jamie = setupTestMP("Jaime Strange");
        QVERIFY2(function1("Jaime Strange", jamie), "Function test failed!");
    }
};

QTEST_MAIN(MyTest);
