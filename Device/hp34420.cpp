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
    m_interfaceConnected->open();
}

void HP34420::disconnecting()
{
    m_interfaceConnected->close();
}

void HP34420::receiveValue()
{

}