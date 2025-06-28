#ifndef FILE_H
#define FILE_H
#include"ifilereader.h"
#include"QFile"
#include"QString"
#include"memory"
#include"QDebug"
#include"QFileInfo"

class FileReader : public IFileReader
{
public:
    FileReader() = default ;
    FileReader(const QString  path);

    FileReader(const   FileReader & file);
    FileReader( FileReader && file);

    FileReader & operator =(const  FileReader& file);
    FileReader & operator =( FileReader&& file);



    QByteArray  read(const    quint64 read_size) override;
    QByteArray  readall()     override;
    QString     getFileInfo() override;
    bool isOpen()             override;

    virtual    ~ FileReader() ;
private:

    std::shared_ptr<QFile> file_byte;
    QFile file_1;
    bool create_file(QString path);
    void Move( FileReader & file);

    QString path;





};
#endif
