#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Device/device.h"
#include "Device/h4_7.h"
#include "Device/hp34420.h"
#include "Device/EnumModelsDevice.h"
#include <QDebug>


//__________Класс контроллер для управления приборами__________//

class Controller : public QObject
{
    Q_OBJECT



    //фабричный метод создания приборов
    Device* createDevice(const enumModelDevice::models& );

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

public slots:

    //____создание приборов___________//
    void createCalibrator(const enumModelDevice::models&);
    void createVoltmeter(const enumModelDevice::models&);

    //____создание интерфеса взаимодействия______//
    void createInterfaceCalibrator(const enumTypeConnection::type& );
    void createInterfaceVoltmeter(const enumTypeConnection::type& );


signals:


private:
    Device* m_calibrator = nullptr;
    Device* m_voltmeter = nullptr;

};



#endif // CONTROLLER_H
