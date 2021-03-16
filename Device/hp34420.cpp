#include "hp34420.h"

HP34420::HP34420()
{
    qDebug()<<"Constructor HP34420";
}

HP34420::~HP34420()
{
    qDebug()<<"Distructor HP34420";
}

void HP34420::connecting()
{
    if(m_interfaceConnected->open()){
        QString SetRemote = "SYST:REM\r\n";
        QString SetCount = "SAMP:COUN 1\r\n";
        if (m_interfaceConnected->write(SetRemote.toLocal8Bit())){
            if (m_interfaceConnected->write(SetCount.toLocal8Bit())){
                is_connect = true;
            }
        }
    }
}

float HP34420::receiveValue(uint ch)
{
    //Отправка команды на подготовку канала к измерениям
    QString Request = "ROUT:TERM FRON"+QString::number(ch)+"\r\n";

    if(m_interfaceConnected->write(Request.toLocal8Bit())){
        Request = "READ?\r\n";
        if (m_interfaceConnected->write(Request.toLocal8Bit())){
            //QThread::msleep(1000);
            QByteArray value = m_interfaceConnected->read();
            qDebug()<<"Получение данных";



            return value.toFloat();
        }
    }

}


