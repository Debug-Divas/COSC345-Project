
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QDebug>

#include "../qtGuiApplication/dbmanager.h"


using namespace testing;

TEST(dbmanager, dbmanagerTest)
{
    puts("test file");
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}


TEST(testGetName, dbmanagerTest){

    static const QString path = "parliament.db";

    DbManager db(path);

    QString name = "Jamie Strange";

    MP mp = db.getMpFromName(name);

    EXPECT_EQ(name, mp.getName());
}


TEST(testGetNameSpecialChar, dbmanagerTest){

    static const QString path = "parliament.db";

    DbManager db(path);

    QString name1 = "Tāmati Coffey";
    QString name2 = "Chlöe Swarbrick";
    QString name3 = "Ricardo Menéndez March";

    MP mp1 = db.getMpFromName(name1);
    MP mp2 = db.getMpFromName(name2);
    MP mp3 = db.getMpFromName(name3);

    EXPECT_EQ(name1, mp1.getName());
    EXPECT_EQ(name2, mp2.getName());
    EXPECT_EQ(name3, mp3.getName());
}

