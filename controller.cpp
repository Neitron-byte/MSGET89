#include "controller.h"

Device *Controller::createDevice(const enumsdevice::models& model)
{
    switch (model) {
    case enumsdevice::models::HP34420:
        return new HP34420();
        break;
    case enumsdevice::models::H4_7:
        return new H4_7();
        break;
    default:
        break;
    }

}

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::createCalibrator(const enumsdevice::models& calibrator)
{
        m_calibrator = createDevice(calibrator);

 }

void Controller::createVoltmeter(const enumsdevice::models& voltmeter)
{

        m_voltmeter = createDevice(voltmeter);
}


void Controller::createInterfaceCalibrator(const enumsdevice::typeConnection& type)
{
    m_calibrator->creatInterface(type);
}

void Controller::createInterfaceVoltmeter(const enumsdevice::typeConnection& type)
{
    m_voltmeter->creatInterface(type);
}
