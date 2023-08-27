#ifndef TST_MYTEST_H
#define TST_MYTEST_H

#include <QObject>

class MyTest : public QObject {
    Q_OBJECT

private slots:
    bool function1();
    void test_function1();
};

#endif // TST_MYTEST_H
