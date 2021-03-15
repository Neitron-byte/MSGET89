#include "controller.h"


Controller::Controller(QObject *parent) : QObject(parent)
  , m_settingsDevice(new DeviceDialog)
{
    qDebug()<<"Constructor controller";
    //создание приборов
    connect(m_settingsDevice,SIGNAL(createCalibrator(enumModelCalibrator::models)),this,SLOT(createCalibrator(enumModelCalibrator::models)));
    connect(m_settingsDevice,SIGNAL(createVoltmeter(enumModelVoltmeter::models)),this,SLOT(createVoltmeter(enumModelVoltmeter::models)));
    //создание интерфейса подключения
    connect(m_settingsDevice,SIGNAL(createConnectionCalibrator(enumTypeConnection::type)),this,SLOT(createInterfaceCalibrator(enumTypeConnection::type)));
    connect(m_settingsDevice,SIGNAL(createConnectionVoltmeter(enumTypeConnection::type)),this, SLOT(createInterfaceVoltmeter(enumTypeConnection::type)));
    //вызов диалогового окна настройки
    connect(m_settingsDevice,SIGNAL(showDialogSettingCal()),this,SLOT(showDialogSettingCal()));
    connect(m_settingsDevice,SIGNAL(showDialogSettingVol()),this,SLOT(showDialogSettingVol()));
    //подключение к приборам
    connect(m_settingsDevice,SIGNAL(connectionCal()),this,SLOT(connectionCal()));
    connect(m_settingsDevice,SIGNAL(connectionVol()),this,SLOT(connectionVol()));
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
    if(m_veryfication){
        delete m_veryfication;
    }
    qDebug()<<"Distructor controller";
}

void Controller::showDialogSettingDevice()
{
    m_settingsDevice->show();
}

void Controller::createCalibrator(const enumModelCalibrator::models& calibrator)
{

    switch (calibrator) {
    case enumModelCalibrator::H4_7:
        if (m_calibrator){
           delete m_calibrator;
        }
        m_calibrator = new H4_7();
        connect(m_calibrator,SIGNAL(signalStatusDev(QString)),SIGNAL(signalStatus1(QString)));
        break;
    default:

        break;
    }



 }

void Controller::createVoltmeter(const enumModelVoltmeter::models& voltmeter)
{
        qDebug()<<"Create Voltmeter";

        switch (voltmeter) {
        case enumModelVoltmeter::HP34420:
            if(m_voltmeter){
                delete m_voltmeter;
            }
            m_voltmeter = new HP34420();
            connect(m_voltmeter,SIGNAL(signalStatusDev(QString)),SIGNAL(signalStatus2(QString)));

            break;
        default:

            break;
        }


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

void Controller::connectionCal()
{

  m_calibrator->connecting();
}

void Controller::connectionVol()
{

    m_voltmeter->connecting();
}



void Controller::setVeryfycation(const Verification * veryfication)
{
    if(m_veryfication){
    delete this->m_veryfication;
    }
    m_veryfication = const_cast<Verification*>(veryfication);
    qDebug()<<"Calibration is set";
}

void Controller::startCalibration()
{
    m_veryfication->startVerification(m_calibrator,m_voltmeter);
}
