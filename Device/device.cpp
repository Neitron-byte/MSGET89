#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{

}

Device::~Device()
{
    if(m_interfaceConnected){
        delete m_interfaceConnected;
    }
    qDebug()<<"Distructor Device";
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
