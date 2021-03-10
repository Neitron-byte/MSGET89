#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <QObject>
#include "Device/cominterface.h"
#include "device.h"
#include <QDebug>

class Calibrator: public Device
{
    Q_OBJECT

public:
    Calibrator();
    virtual ~Calibrator();
    virtual bool setValue(float ) = 0;
    virtual bool setFreqValue(float , uint ) = 0;


};

#endif // CALIBRATOR_H
