#ifndef FILE_H
#define FILE_H
#include"fileabstract.h"
#include"QFile"
#include"QString"
#include"memory"
#include"QDebug"
class File : public AbstractFile
{
public:
    File() = default ;
    File(QString  path);

    File(  File & file);
    File( File && file);

    File & operator =(const File& file);
    File & operator =( File&& file);

    void Move(File & file);

    QByteArray  read(quint64 read_size) override;
    QByteArray  readall()               override ;
    bool isOpen();

    virtual    ~File();
private:
    std::shared_ptr<QFile> file_byte;
    QFile file_1;
    bool create_file(QString path);







};
#endif
