#ifndef INTERFACECONNECT_H
#define INTERFACECONNECT_H

#include <QObject>

//_____________Абстрактный класс используемого интерфейса для подключения прибора________________//

class InterfaceConnect : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceConnect(QObject *parent = nullptr);

    virtual bool open() = 0;
    virtual void close() = 0;
    virtual bool write(const QByteArray&) = 0;
    virtual QByteArray read() = 0;
    virtual void showDialog() = 0;

signals:

};



#endif // INTERFACECONNECT_H
