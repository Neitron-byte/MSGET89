#ifndef IDEVICE_H
#define IDEVICE_H

#include <QObject>

//__________Интерфейсные классы для приборов_____________//

class IDevice : public QObject
{
    Q_OBJECT

public:
    explicit IDevice(QObject *parent = nullptr);

signals:

public:
    virtual void connecting() = 0;
    virtual void disconnecting() = 0;

};

//__________Интерфейсный класс-наследник для калибратора_____________//

class ICalibrator : public IDevice
{
public:
    virtual void setValue() = 0;
};

//__________Интерфейсный класс-наследник для вольтметра_____________//

class IVoltmeter : public IDevice
{
public:
    virtual void receiveValue() = 0;
};



#endif // IDEVICE_H
