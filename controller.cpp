#include "controller.h"

Device *Controller::createDevice(const modelsDevice& model)
{
    switch (model) {
    case modelsDevice::HP34420:
        return new HP34420();
        break;
    case modelsDevice::H4_7:
        return new H4_7();
        break;
    default:
        break;
    }

}

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::createCalibrator(const modelsDevice& calibrator)
{
        m_calibrator = createDevice(calibrator);

 }

void Controller::createVoltmeter(const modelsDevice& voltmeter)
{

        m_voltmeter = createDevice(voltmeter);
}


void Controller::createInterfaceCalibrator(const typeConnection & type)
{
    m_calibrator->creatInterface(type);
}

void Controller::createInterfaceVoltmeter(const typeConnection & type)
{
    m_voltmeter->creatInterface(type);
}
