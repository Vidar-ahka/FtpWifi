#ifndef LOAD_H
#define LOAD_H
#include"QFile"
#include"Abstractload.h"
#include"QDebug"
class Load : public  AbstractLoad
{
public:
    Load();
    Load(QString path , quint64 exsize);

    Load(Load &  load);
    Load(Load && load);

    Load & operator = (Load & load);
    Load & operator = (Load && load);
    quint64 append(QByteArray  byte)override;
    bool isOpen()      override;
    bool isCompleted() override;
    virtual ~Load();
private:
    void Move(Load & load);
    bool create_file(QString path);
    std::shared_ptr<QFile> file;
    quint64 exsize;
    quint64 cursize;

};

#endif
