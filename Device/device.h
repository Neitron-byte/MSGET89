#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include "Device/interfaceconnect.h"
#include "Device/EnumModelsDevice.h"
#include "Device/cominterface.h"
#include <QDebug>



class Device : public QObject
{
    Q_OBJECT

signals:
    void signalStatusDev(const QString& );

public:
    explicit Device(QObject *parent = nullptr);
    virtual ~Device();
    void creatInterface(const enumTypeConnection::type&);
    void showDialog();
    virtual void connecting();
    virtual void disconnecting();
    //получить статус подключения
    bool getStatusConnect();

protected:
    //интерфейс покдлючения прибора
    InterfaceConnect* m_interfaceConnected = nullptr;
    //состояние подключения
    bool is_connect = false;




 };





#endif // DEVICE_H
