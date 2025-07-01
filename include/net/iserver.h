#ifndef SERVER_H
#define SERVER_H
#include"QObject"
class IServer : public QObject
{
    Q_OBJECT
public :    
    virtual ~IServer() = default;
signals:
   void  signalread(QByteArray byte);
};

#endif
