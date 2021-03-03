#ifndef DIALOGSETTINGSCOM_H
#define DIALOGSETTINGSCOM_H

#include <QDialog>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "dialogsettingscom.h"

namespace Ui {
class DialogSettingsCom;
}

//_____________Диалоговое окно настроек COM ______________//

class DialogSettingsCom : public QDialog
{
    Q_OBJECT

    void fillPortsParameters();
    void fillPortsInfo();

public:
    explicit DialogSettingsCom(QWidget *parent = nullptr);
    ~DialogSettingsCom();

private:
    Ui::DialogSettingsCom *ui;


public:
    QString getNameCom();
    QSerialPort::BaudRate getBaudRate();
    QSerialPort::DataBits getDataBits();
    QSerialPort::StopBits getStopBits();
    QSerialPort::Parity getParity();
    QSerialPort::FlowControl getFlow();

};

#endif // DIALOGSETTINGSCOM_H
