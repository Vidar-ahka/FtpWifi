#include"QTest"
#include"file/file.h"
#include"QObject"
#include"QFile"
#include"QByteArray"
#include"QDir"

class TestFile : public QObject
{
    Q_OBJECT

private slots:

    void initTestCase()
    {
        QString path = "testfiledir/";
        QDir dir;
        if(!dir.exists(path))
        {
            dir.mkdir(path);
        }
        QFile file("testfiledir/test_file.txt");
        QVERIFY(file.open(QIODevice::WriteOnly));
        file.write(test_byte);
        file.close();
    }

    void init()
    {

    }


    void cleanup() {

    }


    void testCopyConstructor() {

        File file1(path_file );
        QVERIFY(file1.isOpen());
        File file2(file1);
        QCOMPARE(file1.isOpen(), file2.isOpen());

}


    void testReadFile() {
        // Создаем файл и записываем в него данные

        File file(path_file );
        QVERIFY(file.isOpen());
        QByteArray  content = file.readall();
        QCOMPARE(content,test_byte);
    }
    void testCreateFile() {
        File file(path_file );
        QVERIFY(file.isOpen());
    }
    void testMoveConstructor() {
        File file1(path_file );
        QVERIFY(file1.isOpen());

        // Создаем второй файл через конструктор перемещения
        File file2(std::move(file1));
        QVERIFY(!file1.isOpen()); // file1 должен быть закрыт
        QCOMPARE(file2.isOpen(), true);
    }

    void testAssignmentOperator() {
        File file1(path_file );
        QVERIFY(file1.isOpen());

        File file2(path_file );
        file2 = file1; // Операция присваивания

        QCOMPARE(file1.isOpen(), file2.isOpen());
    }

    void testMoveAssignmentOperator() {
        File file1(path_file );
        QVERIFY(file1.isOpen());
        File file2;
        file2 = std::move(file1);
        QVERIFY(!file1.isOpen());
        QCOMPARE(file2.isOpen(), true);

    }

    void cleanupTestCase() {

        QFile::remove(path_file );
        QDir dir;
        dir.rmdir(path_dir);


    }
private:
    QString path_dir =  "testfiledir/" ;
    QString path_file = path_dir+"test_file.txt";
    QByteArray test_byte = "Hello, world";

};
QTEST_MAIN(TestFile)
#include "test_main.moc"
