#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Device/device.h"
#include "Device/h4_7.h"
#include "Device/hp34420.h"
#include "Device/EnumModelsDevice.h"


//__________Класс контроллер для управления приборами__________//

class Controller : public QObject
{
    Q_OBJECT

    Device* m_calibrator = nullptr;
    Device* m_voltmeter = nullptr;

    //фабричный метод создания приборов
    Device* createDevice(const enumsdevice::models&);

public:
    explicit Controller(QObject *parent = nullptr);

    //____создание приборов___________//
    void createCalibrator(const enumsdevice::models&);
    void createVoltmeter(const enumsdevice::models&);

    //____создание интерфеса взаимодействия______//
    void createInterfaceCalibrator(const enumsdevice::typeConnection& );
    void createInterfaceVoltmeter(const enumsdevice::typeConnection&);


signals:

};



#endif // CONTROLLER_H
