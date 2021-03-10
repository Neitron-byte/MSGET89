#include "h4_7.h"

H4_7::H4_7()
{
    qDebug()<<"Constructor H4_7";
}

H4_7::~H4_7()
{
    qDebug()<<"Distructor H4_7";
}

bool H4_7::setValue(float U)
{
    QString SendData = "UD"+ QString::number(U) +"\r\n";
    QByteArray Data = SendData.toLocal8Bit();

    if(m_interfaceConnected->write(Data)){
        return true;
    }

    return false;

}

bool H4_7::setFreqValue(float U, uint F)
{
    QString SendData = "UA"+ QString::number(U)+"F"+QString::number(F)+"\r\n";

    QByteArray Data = SendData.toLocal8Bit();

    if(m_interfaceConnected->write(Data)){
        return true;
    }

    return false;
}




