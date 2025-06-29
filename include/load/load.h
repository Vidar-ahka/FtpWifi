#ifndef LOAD_H
#define LOAD_H
#include"QFile"
#include"iload.h"
#include"QDebug"
class Load : public ILoad
{
public:
    Load();
    Load(const QString path , const quint64 exsize);

    Load(const Load &  load);
    Load(Load && load);

    Load & operator = (const Load & load);
    Load & operator = (Load && load);

    quint64 append(const QByteArray  byte)override;
    bool isOpen()      override;
    bool isCompleted() override;

    virtual ~Load();

private:
    void Move(Load & load);
    bool create_file(QString path);
    std::shared_ptr<QFile> file;
    quint64 exsize;
    quint64 cursize;
    QString path;

};

#endif
