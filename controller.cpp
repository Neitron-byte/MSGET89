#include "controller.h"

Device *Controller::createDevice(const enumModelDevice::models& model)
{
    switch (model) {
    case enumModelDevice::HP34420:
        return new HP34420();
        break;
    case enumModelDevice::H4_7:
        return new H4_7();
        break;
    default:
        return nullptr;
        break;
    }


}

Controller::Controller(QObject *parent) : QObject(parent)
  , m_settingsDevice(new DeviceDialog)
{
    qDebug()<<"Constructor controller";
    //создание приборов
    connect(m_settingsDevice,SIGNAL(createCalibrator(enumModelDevice::models)),this,SLOT(createCalibrator(enumModelDevice::models)));
    connect(m_settingsDevice,SIGNAL(createVoltmeter(enumModelDevice::models)),this,SLOT(createVoltmeter(enumModelDevice::models)));
    //создание интерфейса подключения
    connect(m_settingsDevice,SIGNAL(createConnectionCalibrator(enumTypeConnection::type)),this,SLOT(createInterfaceCalibrator(enumTypeConnection::type)));
    connect(m_settingsDevice,SIGNAL(createConnectionVoltmeter(enumTypeConnection::type)),this, SLOT(createInterfaceVoltmeter(enumTypeConnection::type)));
    //вызов диалогового окна настройки
    connect(m_settingsDevice,SIGNAL(showDialogSettingCal()),this,SLOT(showDialogSettingCal()));
    connect(m_settingsDevice,SIGNAL(showDialogSettingVol()),this,SLOT(showDialogSettingVol()));
    //подключение к приборам
    connect(m_settingsDevice,SIGNAL(connectionCal()),m_calibrator->
}

Controller::~Controller()
{
    if(m_calibrator){
        delete m_calibrator;
    }
    if(m_voltmeter){
        delete m_voltmeter;
    }
    if(m_settingsDevice){
        delete m_settingsDevice;
    }
    qDebug()<<"Distructor controller";
}

void Controller::showDialogSettingDevice()
{
    m_settingsDevice->show();
}

void Controller::createCalibrator(const enumModelDevice::models& calibrator)
{
        qDebug()<<"Create Calibrator";
        m_calibrator = createDevice(calibrator);

 }

void Controller::createVoltmeter(const enumModelDevice::models& voltmeter)
{
        qDebug()<<"Create Voltmeter";
        m_voltmeter = createDevice(voltmeter);

}


void Controller::createInterfaceCalibrator(const enumTypeConnection::type& type)
{
    if(m_calibrator){
    m_calibrator->creatInterface(type);
    qDebug()<<"Create Interface Cal";
    }
}

void Controller::createInterfaceVoltmeter(const enumTypeConnection::type& type)
{
    if(m_voltmeter){
    m_voltmeter->creatInterface(type);
    qDebug()<<"Create Interface Vol";
    }
}

void Controller::showDialogSettingCal()
{
    if(m_calibrator){
    m_calibrator->showDialog();
    }
}

void Controller::showDialogSettingVol()
{
    if(m_voltmeter){
    m_voltmeter->showDialog();
    }
}
