#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <QObject>
#include "idevice.h"
#include "Device/cominterface.h"
#include "device.h"
#include <QDebug>

class Calibrator: public Device
{
    Q_OBJECT

public:
    Calibrator();
    virtual ~Calibrator();
    virtual void setValue() = 0;


};

#endif // CALIBRATOR_H
