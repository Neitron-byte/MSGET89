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
{
    qDebug()<<"Constructor controller";
}

Controller::~Controller()
{
    if(m_calibrator){
        delete m_calibrator;
    }
    if(m_voltmeter){
        delete m_voltmeter;
    }
    qDebug()<<"Distructor controller";
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
