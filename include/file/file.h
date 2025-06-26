#ifndef FILE_H
#define FILE_H
#include"fileabstract.h"
#include"QFile"
#include"QString"
#include"memory"
#include"QDebug"
#include"QFileInfo"

class File : public AbstractFile
{
public:
    File() = default ;
    File(const QString  path);

    File(const  File & file);
    File( File && file);

    File & operator =(const File& file);
    File & operator =(File&& file);



    QByteArray  read(const    quint64 read_size) override;
    QByteArray  readall()     override;
    QString     getFileInfo() override;
    bool isOpen()             override;

    virtual    ~File() ;
private:

    std::shared_ptr<QFile> file_byte;
    QFile file_1;
    bool create_file(QString path);
    void Move(File & file);







};
#endif
