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
    virtual float receiveValue(uint ) =0;

};

#endif // VOLTMETER_H
