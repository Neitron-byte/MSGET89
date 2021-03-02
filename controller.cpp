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

}

void Controller::createCalibrator(const enumModelDevice::models& calibrator)
{
        m_calibrator = createDevice(calibrator);

 }

void Controller::createVoltmeter(const enumModelDevice::models& voltmeter)
{

        m_voltmeter = createDevice(voltmeter);
}


void Controller::createInterfaceCalibrator(const enumTypeConnection::type& type)
{
    m_calibrator->creatInterface(type);
}

void Controller::createInterfaceVoltmeter(const enumTypeConnection::type& type)
{
    m_voltmeter->creatInterface(type);
}
