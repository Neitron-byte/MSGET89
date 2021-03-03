#include "h4_7.h"

H4_7::H4_7()
{
    qDebug()<<"Constructor H4_7";
}

H4_7::~H4_7()
{
    qDebug()<<"Distructor H4_7";
}

void H4_7::connecting()
{
    m_interfaceConnected->open();

}

void H4_7::disconnecting()
{
    m_interfaceConnected->close();
}

void H4_7::setValue()
{
    m_interfaceConnected->write();
}
