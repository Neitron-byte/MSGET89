#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{

}

void Device::creatInterface(const enumTypeConnection::type& type)
{
    switch (type) {
    case enumTypeConnection::COM:
        m_interfaceConnected = new ComInterface();
        break;
    default:
        break;
    }

}
