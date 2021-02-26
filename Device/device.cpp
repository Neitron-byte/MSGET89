#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{

}

void Device::creatInterface(const typeConnection & type)
{

    switch (type) {
    case typeConnection::COM:
        m_interfaceConnected = new ComInterface();
        break;
    default:
        break;
    }

}
