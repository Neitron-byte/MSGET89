#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Device/calibrator.h"
#include "Device/voltmeter.h"
#include "Device/h_4_7.h"
#include "Device/hp_34420a.h"
#include "Device/iconnection.h"
#include "Device/comconnection.h"
#include "Device/tcpconnection.h"

//__________Модели калибраторов__________//
enum class modelsCalibrator
{
    H4_7

};

//__________Модели вольтметров__________//
enum class modelsVoltmeter
{
    HP34420A
};

//__________Тип подключения__________//
enum class typeConnection
{
    COM,
    TCP
};

//__________Класс контроллер для управления приборами__________//

class Controller : public QObject
{
    Q_OBJECT

    Calibrator* m_calibrator = nullptr;
    Voltmeter* m_voltmeter = nullptr;

public:
    explicit Controller(QObject *parent = nullptr);

    //____фабричные методы_____//____создание объектов____//
    Calibrator* createCalibrator(const modelsCalibrator&) const;
    Voltmeter* createVoltmeter(const modelsVoltmeter&) const;

    //____создание интерфеса взаимодействия______//
    void createInterfaceCalibrator(const typeConnection&);
    void createInterfaceVoltmeter(const typeConnection&);


signals:

};



#endif // CONTROLLER_H
