#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{

}

Calibrator *Controller::createCalibrator(const modelsCalibrator& calibrator) const
{
    switch (calibrator) {
    case modelsCalibrator::H4_7:
        return new H_4_7();
        break;
    default:
        break;
    }

 }

Voltmeter *Controller::createVoltmeter(const modelsVoltmeter& voltmeter) const
{
    switch (voltmeter) {
    case modelsVoltmeter::HP34420A:
        return new HP_34420A();
        break;

    default:
        break;
    }

}


void Controller::createInterfaceCalibrator(const typeConnection & type)
{
    switch (type) {
    case typeConnection::COM:
        m_calibrator->m_connection = new comConnection();
        break;

    default:
        break;
    }

}

void Controller::createInterfaceVoltmeter(const typeConnection & type)
{

    switch (type) {
    case typeConnection::COM:
        m_voltmeter->m_connection = new comConnection();
        break;

    default:
        break;
    }

}
