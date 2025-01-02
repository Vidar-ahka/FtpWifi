#include <QApplication>
#include <QTest>
#include"file_test.h"
#include"load_test.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoadTest f;
    FileTest t;
    QTest::qExec(&f, argc, argv);

    return 0;
}
