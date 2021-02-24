#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <QObject>
#include "Device/device.h"
#include "Device/iconnection.h"

//__________Абстрактный класс___Калибрато____________//
class Calibrator: public IDevice
{
    Q_OBJECT



public:
    Calibrator();

    virtual void connect() =0;
    virtual void disconnect() =0;


    virtual void setValue() = 0; //интерфейс, который должен переопределить каждый наследник

protected:

    //Интерфейс подключения
    IConnection* m_connection = nullptr;


friend class Controller;
};



#endif // CALIBRATOR_H
