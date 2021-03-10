#ifndef H4_7_H
#define H4_7_H

#include "Device/idevice.h"
#include "Device/device.h"
#include "Device/cominterface.h"
#include "QDebug"
#include "calibrator.h"

class H4_7 : public Calibrator
{

public:
    H4_7();
    virtual~H4_7();
    virtual void setValue() override;


};

#endif // H4_7_H
