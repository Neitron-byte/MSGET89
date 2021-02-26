#ifndef INTERFACECONNECT_H
#define INTERFACECONNECT_H

#include <QObject>

//_____________Абстрактный класс используемого интерфейса для подключения прибора________________//

class InterfaceConnect : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceConnect(QObject *parent = nullptr);

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void write() = 0;
    virtual void read() = 0;


signals:

};



#endif // INTERFACECONNECT_H
