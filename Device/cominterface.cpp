#include "cominterface.h"

ComInterface::ComInterface()
{
    qDebug()<<"Constructor COM";
}

ComInterface::~ComInterface()
{
    qDebug()<<"Distructor COM";
}

void ComInterface::open()
{

}

void ComInterface::close()
{

}

void ComInterface::write()
{

}

void ComInterface::read()
{

}

void ComInterface::setSettings(const Settings && settingsTmp)
{
    m_currentSettings.name = settingsTmp.name;
    m_currentSettings.baudRate = settingsTmp.baudRate;
    m_currentSettings.dataBits = settingsTmp.dataBits;
    m_currentSettings.parity = settingsTmp.parity;
    m_currentSettings.stopBits = settingsTmp.stopBits;
    m_currentSettings.flowControl = m_currentSettings.flowControl;
    qDebug()<<m_currentSettings.name
           <<m_currentSettings.baudRate
          <<m_currentSettings.dataBits
         <<m_currentSettings.flowControl
        <<m_currentSettings.parity
       <<m_currentSettings.stopBits;

}
