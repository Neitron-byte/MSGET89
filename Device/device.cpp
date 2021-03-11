#include "device.h"

Device::Device(QObject *parent)
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
        if (m_interfaceConnected){
            delete m_interfaceConnected;
        }
        m_interfaceConnected = new ComInterface();
        connect(m_interfaceConnected,SIGNAL(signalStatus(const QString&)), SIGNAL(signalStatusDev(const QString&)));

        break;
    default:
        break;
    }

}

void Device::showDialog()
{
    if(m_interfaceConnected){
    m_interfaceConnected->showDialog();
    }
}

void Device::connecting()
{
    if (m_interfaceConnected->open()){
        is_connect = true;
    }

}

void Device::disconnecting()
{
    is_connect = false;
    m_interfaceConnected->close();
}



