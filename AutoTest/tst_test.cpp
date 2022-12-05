#include <QtTest>

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

public slots:
    void testBenchmark();
    void test_case1();

};

test::test()
{

}

test::~test()
{

}

void test::test_case1()
{
    QVERIFY(true);
}


void test::testBenchmark()
{
    QString str("hellO");
    QBENCHMARK{
        str.toLower();    // 为了测试出准确度，该代码被重复多次执行。
    }
    QVERIFY2(true,"FAILUE");     // QVERIFY2 (条件，消息)
}


QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
