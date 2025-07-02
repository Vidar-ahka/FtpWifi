#ifndef  FILE_TEST
#define  FILE_TEST

#include <QTest>
#include"file/filemetadatacreate.h"
#include"file/filemetadataparse.h"


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
        QByteArray content = file.readall();
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
        QVERIFY(!file1.isOpen());
        QCOMPARE(file2.isOpen(), true);
    }

    void testAssignmentOperator() {
        FileReader file1(path_file);
        QVERIFY(file1.isOpen());
        FileReader file2(path_file);
        file2 = file1;
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

        QString str2 = "size:" + QString::number(test_byte.size()) + "\n" + "name:" + "test_file.txt";
        QCOMPARE(str, str2);

        ParsingFileInfo parsing(str);
        QCOMPARE(parsing.getName(), "test_file.txt");
    }


    void testFileMetaDataValidJson()
    {
        qint64 chunkSize = 5;
        FileMetaDataCreate meta(path_file, chunkSize);
        QJsonObject obj = meta.object();
        QJsonDocument doc(obj);
        QByteArray jsonData = doc.toJson();

        FileMetaDataParse parser(jsonData);

        QVERIFY(parser.contains("name"));
        QCOMPARE(parser.value("name").toString(), QFileInfo(path_file).fileName());
        QVERIFY(parser.contains("chunks"));
        QVERIFY(parser.value("chunks").toArray().size() > 0);
    }

    \
    void testFileMetaDataInvalidJson()
    {
        QByteArray invalidData = "this is not valid json";

        FileMetaDataParse parser(invalidData);

        QVERIFY(!parser.contains("name"));
        QVERIFY(!parser.contains("size"));
        QVERIFY(!parser.contains("chunks"));
    }

    void cleanupTestCase()
    {
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
