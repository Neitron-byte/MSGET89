#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Device/device.h"
#include "Device/calibrator.h"
#include "Device/h4_7.h"
#include "Device/voltmeter.h"
#include "Device/hp34420.h"
#include "Device/EnumModelsDevice.h"
#include <QDebug>
#include <devicedialog.h>
#include "verification.h"





//__________Класс контроллер для управления приборами__________//

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    //открытие диалогового окна конфигурирования системы
    void showDialogSettingDevice();

public slots:

    //____создание приборов___________//
    void createCalibrator(const enumModelCalibrator::models&);
    void createVoltmeter(const enumModelVoltmeter::models&);

    //____создание интерфеса взаимодействия______//
    void createInterfaceCalibrator(const enumTypeConnection::type& );
    void createInterfaceVoltmeter(const enumTypeConnection::type& );

    //____отображение диалогового окна настроек интерфейса_____//
    void showDialogSettingCal();
    void showDialogSettingVol();

    //______подключение к приборам__________//
    void connectionCal();
    void connectionVol();

    //____замена процедуры поверки___________//
    void setVeryfycation(Verification* );


signals:
    void signalStatus1(const QString&);
    void signalStatus2(const QString&);

private:
    // Указатели на прибора
    Calibrator* m_calibrator = nullptr;
    Voltmeter* m_voltmeter = nullptr;

    //диалоговое окно настройки приборов
    DeviceDialog* m_settingsDevice = nullptr;

    //алгоритм поверки
    Verification* m_veryfication = nullptr;
};



#endif // CONTROLLER_H
