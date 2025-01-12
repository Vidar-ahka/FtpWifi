#include <QApplication>
#include <QTest>
#include"file_test.h"
#include"load_test.h"
#include"net_test.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoadTest l;
    FileTest f;
    NetTest  n;
    QTest::qExec(&n, argc, argv);

    return a.exec();
}
