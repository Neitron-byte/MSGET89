#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include "Device/idevice.h"
#include "Device/interfaceconnect.h"
#include "Device/EnumModelsDevice.h"
#include "Device/cominterface.h"
#include <QDebug>



class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = nullptr);
    ~Device();
    void creatInterface(const enumTypeConnection::type&);
    void showDialog();

signals:
    void signalStatusDev(const QString& );

protected:
    InterfaceConnect* m_interfaceConnected = nullptr;




 };





#endif // DEVICE_H
