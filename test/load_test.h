#ifndef LOAD_TEST_H
#define LOAD_TEST_H
#include"QObject"
#include"QTest"
#include"QDir"
#include"load/load.h"
#include"load/dataloadmanager.h"
class LoadTest : public  QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        path_dir  = "testload/";
        path_file = path_dir+"load_test.txt";
        data = QByteArray("Tamerlan");
        QDir dir;
        if(!dir.exists(path_dir))
        {
            dir.mkdir(path_dir);
        }
        load = Load(path_file,data.size());

    }
    void testAppendFile()
    {
        quint64 size =  load.append(data);
        QCOMPARE(size,data.size());
    }

    void testCopyConstructor()
    {
        Load load_copy(load);
        QVERIFY(load_copy.isOpen());
        QVERIFY(load.isOpen());

    }
    void testMoveConstructor()
    {
        Load lode_move = std::move(load);
        QVERIFY(lode_move.isOpen());
        QVERIFY(!load.isOpen());
    }
    void testDataLoadManager()
    {
        QByteArray byte ="helloworld";
        DataLoadManager log;
        log.createLoad(4,"name.txt",byte.size());
        log.appenddata(4,byte);
    }
    void cleanupTestCase()
    {
        QDir dir;
        QFile::remove(path_file);

        if(dir.exists(path_dir))
        {
            dir.rmdir(path_dir);
        }

}

private:
    Load load;
    QString    path_dir;
    QString    path_file;
    QByteArray data;
};

#endif
