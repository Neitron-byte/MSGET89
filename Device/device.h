#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>


//_________Интерфейсный класс____________//

class IDevice : public QObject
{
    Q_OBJECT
public:
    explicit IDevice(QObject *parent = nullptr);

    virtual void connect() = 0;
    virtual void disconnect() = 0;



signals:

};

#endif // DEVICE_H
