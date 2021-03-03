#ifndef COMINTERFACE_H
#define COMINTERFACE_H

#include "Device/interfaceconnect.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include "devicedialog.h"


//___________________Класс наследник, реализующий интерфейс через COM-порт___________________//


class  ComInterface : public InterfaceConnect
{
public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;
      };

public:
     ComInterface();
     ~ComInterface();
     void open() override;
     void close() override;
     void write() override;
     void read() override;

public slots:

     void setSettings(const Settings&&);

private:
     Settings m_currentSettings;

     friend class DeviceDialog;
};



#endif // COMINTERFACE_H
