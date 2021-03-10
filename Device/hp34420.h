#ifndef HP34420_H
#define HP34420_H


#include "Device/device.h"
#include "QDebug"
#include "Device/voltmeter.h"

class HP34420: public Voltmeter

{

public:
    HP34420();
    ~HP34420();
    virtual void connecting() override;
    virtual QByteArray receiveValue(uint ) override;

};

#endif // HP34420_H
