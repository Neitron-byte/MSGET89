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
     //открытие порта
     bool open() override;
     //Закрыть....
     void close() override;
     //Записать
     bool write(const QByteArray&) override;

     //Показать окно настроек интерфейса подключения прибора
     void showDialog() override;


public    slots:
    void handleError(QSerialPort::SerialPortError error);
    //Чтение данных
    QByteArray read() override;

signals:
     void signalStatus (const QString&);

private:
     //настройки Com-порта
     Settings m_currentSettings;

     // указатель на COM
     QSerialPort* m_serial = nullptr;

     //cтатус подключения
     bool is_Open = false;

     //тайм-аут
     uint m_timeOut = 30000;

};



#endif // COMINTERFACE_H
