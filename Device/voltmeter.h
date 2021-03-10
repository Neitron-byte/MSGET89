#ifndef VOLTMETER_H
#define VOLTMETER_H

#include <QObject>
#include "device.h"


class Voltmeter: public Device
{
    Q_OBJECT

public:
    Voltmeter();
    virtual ~Voltmeter();
    virtual QByteArray receiveValue(uint ) =0;

};

#endif // VOLTMETER_H
