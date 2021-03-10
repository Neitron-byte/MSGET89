#ifndef HP34420_H
#define HP34420_H

#include "Device/idevice.h"
#include "Device/device.h"
#include "QDebug"
#include "Device/voltmeter.h"

class HP34420: public Voltmeter

{

public:
    HP34420();
    ~HP34420();
    virtual void receiveValue() override;

};

#endif // HP34420_H
