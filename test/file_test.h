#ifndef  FILE_TEST
#define  FILE_TEST
#include <QTest>

#include <QByteArray>
#include <QDir>
#include"file/filereader.h"
#include"file/parsingfileinfo.h"
#include"QFile"

class FileTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        path_dir = "testfiledir/";
        path_file = path_dir + "test_file.txt";
        test_byte = "hello, world";
        QDir dir;
        if (!dir.exists(path_dir))
        {
            dir.mkdir(path_dir);
        }
        QFile file(path_file);
        QVERIFY(file.open(QIODevice::WriteOnly));
        file.write(test_byte);
        file.close();
    }

    void init() {}

    void cleanup() {}

    void testCopyConstructor() {
        FileReader file1(path_file);
        QVERIFY(file1.isOpen());
        FileReader file2(file1);
        QCOMPARE(file1.isOpen(), file2.isOpen());
    }

    void testReadFile() {
        FileReader file(path_file);
        QVERIFY(file.isOpen());
        QByteArray content = file.readall(); // Исправлено: readall -> readAll
        QCOMPARE(content, test_byte);
    }

    void testCreateFile() {
        FileReader file(path_file);
        QVERIFY(file.isOpen());
    }

    void testMoveConstructor() {
        FileReader file1(path_file);
        QVERIFY(file1.isOpen());
        FileReader file2(std::move(file1));
        QVERIFY(!file1.isOpen()); // file1 должен быть закрыт
        QCOMPARE(file2.isOpen(), true);
    }

    void testAssignmentOperator() {
        FileReader file1(path_file);
        QVERIFY(file1.isOpen());
        FileReader file2(path_file);
        file2 = file1; // Операция присваивания
        QCOMPARE(file1.isOpen(), file2.isOpen());
    }

    void testMoveAssignmentOperator() {
        FileReader file1(path_file);
        QVERIFY(file1.isOpen());
        FileReader file2;
        file2 = std::move(file1);
        QVERIFY(!file1.isOpen());
        QCOMPARE(file2.isOpen(), true);
    }
    void testGetInfo()
    {
        FileReader file(path_file);
        QString str = file.getFileInfo();

        QString str2 = "size:"+QString::number(test_byte.size())+"\n"+"name:"+"test_file.txt";

        QCOMPARE(str,str2);

        ParsingFileInfo parsing(str);

        QCOMPARE(parsing.getName(),"test_file.txt");


    }

    void cleanupTestCase() {
        QFile::remove(path_file);
        QDir dir;
        dir.rmdir(path_dir);
    }

private:
    QString path_dir;
    QString path_file;
    QByteArray test_byte;
};

#endif


