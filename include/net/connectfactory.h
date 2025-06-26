#include"connect.h"
#include"memory"
#include"QHash"
class ConnectFactory
{
public:
    ConnectFactory() = default;

    std::shared_ptr<Connect> CreateConnect(const QString ip , int port);
    std::shared_ptr<Connect> getConnect   (const QString ip);
    virtual  ~ConnectFactory() = default;

private:
    QHash<QString, std::shared_ptr<Connect>> connect_hash;
};
