#ifndef H4_7_H
#define H4_7_H

#include "Device/idevice.h"
#include "Device/device.h"
#include "Device/cominterface.h"
#include "QDebug"

class H4_7 : public Device, public ICalibrator
{
public:
    H4_7();
    ~H4_7();
    void connecting() override;
    void disconnecting() override;
    void setValue() override;

};

#endif // H4_7_H
