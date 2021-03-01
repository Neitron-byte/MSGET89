#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{

}

void Device::creatInterface(const enumsdevice::typeConnection & type)
{

    switch (type) {
    case enumsdevice::typeConnection::COM:
        m_interfaceConnected = new ComInterface();
        break;
    default:
        break;
    }

}
