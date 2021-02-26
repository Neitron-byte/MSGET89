#ifndef COMINTERFACE_H
#define COMINTERFACE_H

#include "Device/interfaceconnect.h"
#include<QtSerialPort/QSerialPort>


//___________________Класс наследник, реализующий интерфейс через COM-порт___________________//


class  ComInterface : public InterfaceConnect
{
public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

public:
     ComInterface();
     void open() override;
     void close() override;
     void write() override;
     void read() override;

private:
     Settings m_currentSettings;
};
#endif // COMINTERFACE_H
