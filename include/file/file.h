#ifndef FILE_H
#define FILE_H
#include"fileabstract.h"
#include"QFile"
#include"QString"
#include"functional"
#include"memory"
class File : public FileAbstract
{
public:
    File() noexcept;
    File(QString  path);
    QByteArray  read(quint64 read_size) override;
    QByteArray  readall()               override ;
    quint64     append(QByteArray byte) override;
    virtual    ~File();
private:
    std::shared_ptr<QFile> file;





};
#endif
