#include "cominterface.h"

ComInterface::ComInterface()
{
    qDebug()<<"Constructor COM";
    m_serial = new QSerialPort();
    connect(m_serial, &QSerialPort::errorOccurred, this, &ComInterface::handleError);

}

ComInterface::~ComInterface()
{
    qDebug()<<"Distructor COM";
}

void ComInterface::open()
{
    //qDebug()<<m_currentSettings.name<< " Open";

    m_serial->setPortName(m_currentSettings.name);
    m_serial->setBaudRate(m_currentSettings.baudRate);
    m_serial->setDataBits(m_currentSettings.dataBits);
    m_serial->setParity(m_currentSettings.parity);
    m_serial->setStopBits(m_currentSettings.stopBits);
    m_serial->setFlowControl(m_currentSettings.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        qDebug()<<m_currentSettings.name << "is open";
        emit signalStatus (tr("Connected to %1 : %2, %3, %4, %5, %6")
                                   .arg(m_currentSettings.name).arg(m_currentSettings.baudRate).arg(m_currentSettings.dataBits)
                                .arg(m_currentSettings.parity).arg(m_currentSettings.stopBits).arg(m_currentSettings.flowControl));

    } else {
        emit signalStatus (tr("Error connecting to %1").arg(m_currentSettings.name));
    }
}

void ComInterface::close()
{
    if (m_serial->isOpen()){
        m_serial->close();
    }
}

void ComInterface::write()
{

}

void ComInterface::read()
{

}

void ComInterface::showDialog()
{
       DialogSettingsCom dlg;
       switch (dlg.exec()) {
        case QDialog::Accepted:
           qDebug() << "Accepted";
                m_currentSettings.name = dlg.getNameCom();
                m_currentSettings.baudRate = dlg.getBaudRate();
                m_currentSettings.dataBits = dlg.getDataBits();
                m_currentSettings.flowControl = dlg.getFlow();
                m_currentSettings.parity = dlg.getParity();
                m_currentSettings.stopBits = dlg.getStopBits();

           break;
       case QDialog::Rejected:
           qDebug() << "Rejected";
           break;
       default:
           qDebug() << "Unexpected";
       }
       qDebug()<<m_currentSettings.name
              <<m_currentSettings.baudRate
             <<m_currentSettings.dataBits
            <<m_currentSettings.flowControl
           <<m_currentSettings.parity
          <<m_currentSettings.stopBits;
}

void ComInterface::handleError(QSerialPort::SerialPortError error)
{
        emit signalStatus(m_serial->errorString());

        this->close();

}


