#ifndef COMINTERFACE_H
#define COMINTERFACE_H

#include "Device/interfaceconnect.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include "devicedialog.h"
#include "QObject"


//___________________Класс наследник, реализующий интерфейс через COM-порт___________________//


class  ComInterface : public InterfaceConnect
{
    Q_OBJECT
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
     void showDialog() override;

public    slots:
    void handleError(QSerialPort::SerialPortError error);

signals:
     void signalStatus (const QString&);

private:
     Settings m_currentSettings;

     QSerialPort* m_serial = nullptr;

};



#endif // COMINTERFACE_H
