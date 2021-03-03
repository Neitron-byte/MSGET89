#ifndef HP34420_H
#define HP34420_H

#include "Device/idevice.h"
#include "Device/device.h"
#include "QDebug"

class HP34420: public Device, public IVoltmeter
{
public:
    HP34420();
    ~HP34420();
    void connecting() override;
    void disconnecting() override;
    void receiveValue() override;

};

#endif // HP34420_H
