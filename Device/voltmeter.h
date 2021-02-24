#ifndef VOLTMETER_H
#define VOLTMETER_H

#include <QObject>
#include "Device/device.h"
#include "Device/iconnection.h"

class Voltmeter: public IDevice
{
    Q_OBJECT



public:
    Voltmeter();

    virtual void connect() =0;
    virtual void disconnect() =0;


    virtual void receiveValue() = 0; //интерфейс, который должен переопределить каждый наследник

protected:
    //Интерфейс подключения
    IConnection* m_connection = nullptr;

friend class Controller;

};



#endif // VOLTMETER_H
