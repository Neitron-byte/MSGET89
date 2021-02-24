#ifndef COMCONNECTION_H
#define COMCONNECTION_H

#include "Device/iconnection.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>

class comConnection: public IConnection
{
    struct SettingsComPort {
        QString m_name;
        uint m_baudRate;
        QSerialPort::DataBits m_dataBits;
        QSerialPort::Parity m_parity;
        QSerialPort::StopBits m_stopBits;
        QSerialPort::FlowControl m_flowControl;
    };

    //текущие настройки порта
    SettingsComPort m_SettingsCom;

public:

    comConnection();


    void write();

};

#endif // COMCONNECTION_H
